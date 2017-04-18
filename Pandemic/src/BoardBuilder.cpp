#include "BoardBuilder.h"
#include "FileStream.h"
#include "FileSystem.h"
#include "CityCard.h"
#include "EventCard.h"
#include "InfectionCard.h"
#include <time.h>

#define BOARD_FILE "cities.dat"
#define BOARD_METAFILE "board.dat"
#define PLAYER_FILE "players.dat"
#define DEFAULT_BOARD_FILE (FileSystem::getStartupPath() + "/saves/def_nodes.dat")
#define DEFAULT_BOARD_METAFILE (FileSystem::getStartupPath() + "/saves/def_board.dat")

//// Load the game board, and change the game state.
//if (((UICheckbox*)GuiManager::getUIElementByName(CHK_DEFAULT_MAP))->isChecked() && created) {
//	Game::_gameBoard = new Board(FileSystem::getStartupPath() + GAME_SAVES_FOLDER + "default/");
//}
//else {
//	Game::_gameBoard = new Board(Game::_saveFolder);

Board* BoardBuilder::loadNewGame(const int numberOfPlayers)
{
	Board* board = new Board();

	const int MAX = 6; //maximum value (of course, this must be at least the same as AMOUNT;
	int value[4]; //array to store the random numbers in

	srand((unsigned)time(NULL)); //always seed your RNG before using it

								 //generate random numbers:
	for (unsigned int i = 0; i< 4; i++) {
		bool check; //variable to check or number is already used
		int n; //variable to store the number in
		do {
			n = rand() % MAX;
			//check or number is already used:
			check = true;
			for (unsigned int j = 0; j<i; j++)
				if (n == value[j]) //if number is already used
				{
					check = false; //set check to false
					break; //no need to check the other elements of value[]
				}
		} while (!check); //loop until new, unique number is found
		value[i] = n; //store the generated number in the array
	}

	for (int i = 0; i < numberOfPlayers; i++) {
		RoleCard* rc = new RoleCard(RoleCard::roleCardNames[value[i]]);
		Player* player = new Player();
		player->setRoleCard(rc);
		board->addPlayer(player);
	}

	this->loadCities(DEFAULT_BOARD_FILE, *board);
	return board;
}

Board* BoardBuilder::loadFromSave(std::string name)
{
	Board* board = new Board();
	std::string path = name + "/";

	try
	{
		this->loadBoardData(path + BOARD_METAFILE, *board);
		this->loadCities(path + BOARD_FILE, *board);
		this->loadPlayers(path + PLAYER_FILE, *board);
	}
	catch (const char* e) {
		delete board;
		board = nullptr;
	}

	return board;
}

void BoardBuilder::loadBoardData(std::string file, Board& board)
{
	if (!FileSystem::fileExists(file)) {
		throw "BoardBuilder::loadBoardData() - File does not exist";
	}

	FileStream* fs = FileStream::Open(file, FileMode::Read);

	board.currentTurnPlayer = fs->readInt();
	Game::actionCounter = fs->readInt();

	for (int i = 0; i < 4; i++) {
		board.isCured[i] = fs->readBool();
	}

	// Cubes counters and research center.
	Game::numOfBlackCube = fs->readInt();
	Game::numOfYellowCube = fs->readInt();
	Game::numOfBlueCube = fs->readInt();
	Game::numOfRedCube = fs->readInt();
	Game::numOfResearchCenter = fs->readInt();

	// Infection Rate
	Board::_infectionRate = fs->readInt();
	City::outbreakCount = fs->readInt();

	board.setActualInfectionRate(fs->readInt());


	// Read all player cards in the withdraw pile.
	int numPlayerCards = fs->readInt();
	for (int i = 0; i < numPlayerCards; i++) {
		int type = fs->readInt();

		if (type == PlayerCardType::City_Card) {
			board.playerWithdrawPile.push_back(new CityCard(fs->readInt()));
		}
		else if (type == PlayerCardType::Event_Card) {
			// This is nonesense.
			fs->readInt();
		}
	}

	// Read all infection cards in the pickup pile.
	int numInfectionCityCards = fs->readInt();
	for (int i = 0; i < numInfectionCityCards; i++) {
		board.infectionCityCards.push_back(fs->readInt());
	}

	// Read all infection cards in the discard pile.
	int numInfectionCityCardsDiscard = fs->readInt();
	for (int i = 0; i < numInfectionCityCardsDiscard; i++) {
		board.discardInfectionCard.push_back(fs->readInt());
	}

	delete fs;
}

void BoardBuilder::loadCities(std::string file, Board& board)
{
	if (!FileSystem::fileExists(file)) {
		throw "BoardBuilder::loadCities() - File does not exist";
	}

	FileStream* fs = FileStream::Open(file, FileMode::Read);

	// Figure out how many nodes there are
	int numNodes = fs->readInt();

	// Read every node's data.
	for (int i = 0; i < numNodes; i++) {
		City* city = new City();
		city->name = fs->readString();
		city->cube[0] = fs->readInt();
		city->cube[1] = fs->readInt();
		city->cube[2] = fs->readInt();
		city->cube[3] = fs->readInt();
		city->research = fs->readBool();
		city->color = (InfectionColor)fs->readInt();
		city->x = fs->readInt();
		city->y = fs->readInt();

		// Read through all the nodes adjacent to this node
		// and add it to its colleciton.
		int numAdjacentNodes = fs->readInt();
		for (int x = 0; x < numAdjacentNodes; x++) {
			city->addAdjacentNode(fs->readInt());
		}

		// Set the i'th city on the current board to the created city.
		board.addCity(city);
	}

	delete fs;
}

void BoardBuilder::loadPlayers(std::string file, Board& board)
{
	if (!FileSystem::fileExists(file)) {
		throw "BoardBuilder::loadPlayers() - File does not exist";
	}

	FileStream* fs = FileStream::Open(file, FileMode::Read);

	int numPlayers = fs->readInt();
	for (int playerIndex = 0; playerIndex < numPlayers; playerIndex++) {
		Player* player = new Player();
		player->pawn->cityIndex = fs->readInt();

		int role = fs->readInt();
		player->setRoleCard(new RoleCard(RoleCard::roleCardNames[role]));

		// Go through all the player's cards.	
		for (int playerCardIndex = 0; playerCardIndex < MAX_PLAYER_CARDS; playerCardIndex++) {
			// Get the type of the card.
			int cardType = fs->readInt();

			// If the card type is non-negative.
			if (cardType != -1) {
				// What kind of card is it?
				switch ((PlayerCardType)cardType) {
				case PlayerCardType::City_Card:
				{
					CityCard* card = new CityCard(fs->readInt());
					player->addCard(card);
				}break;
				}
			}
		}

		board.addPlayer(player);
	}

	delete fs;
}


void BoardBuilder::save(std::string savename, Board& board)
{
	std::string path = savename + "/";
	FileSystem::createDirectory(path);

	this->saveBoardData(path + BOARD_METAFILE, board);
	this->saveCities(path + BOARD_FILE, board);
	this->savePlayers(path + PLAYER_FILE, board);
}

void BoardBuilder::saveBoardData(std::string file, Board& board)
{
	FileStream* fs = FileStream::Open(file, FileMode::Write);

	fs->write(board.currentTurnPlayer);
	fs->write(Game::actionCounter);
	for (int i = 0; i < InfectionColor::InfectionColor_Length; i++) {
		fs->write(board.isCured[i]);
	}

	// Cubes counters and research center.
	fs->write(Game::numOfBlackCube);
	fs->write(Game::numOfYellowCube);
	fs->write(Game::numOfBlueCube);
	fs->write(Game::numOfRedCube);
	fs->write(Game::numOfResearchCenter);

	// Infection rate
	fs->write(Board::_infectionRate);

	fs->write(City::outbreakCount);
	fs->write(board.getActualInfectionRate());

	// Save all the cards in the withdraw pile.
	fs->write(board.playerWithdrawPile.size());
	for (unsigned int i = 0; i < board.playerWithdrawPile.size(); i++) {
		PlayerCard* card = board.playerWithdrawPile.at(i);
		fs->write(card->getType());

		if (card->getType() == PlayerCardType::City_Card) {
			fs->write(((CityCard*)card)->cityIndex);
		}
		else {
			fs->write(-1);
		}
	}

	// Save all epidemic cards in the withdraw pile.
	fs->write(board.infectionCityCards.size());
	for (unsigned int i = 0; i < board.infectionCityCards.size(); i++) {
		fs->write(board.infectionCityCards.at(i));
	}

	// Save all the epidemic cards in the discard pile.
	fs->write(board.discardInfectionCard.size());
	for (unsigned int i = 0; i < board.discardInfectionCard.size(); i++) {
		fs->write(board.discardInfectionCard.at(i));
	}

	delete fs;
}


void BoardBuilder::savePlayers(std::string file, Board& board)
{
	FileStream* fs = FileStream::Open(file, FileMode::Write);

	fs->write(board.getNumberOfPlayers());

	for (int i = 0; i < board.getNumberOfPlayers(); i++) {
		Player& player = board.getPlayer(i);

		fs->write(player.pawn->cityIndex);
		fs->write(player.getRoleCard()->getRoleCardVal());

		for (int i = 0; i < 7; i++) {
			auto card = player.getCard(i);

			if (card != nullptr) {
				fs->write(card->getType());

				// TODO: Save event cards.
				switch (card->getType())
				{
				case PlayerCardType::City_Card:
					fs->write(((CityCard*)card)->cityIndex);
					break;
				}
			}
			else {
				fs->write(-1);
			}
		}
	}

	delete fs;
}

void BoardBuilder::saveCities(std::string file, Board& board)
{
	FileStream* fs = FileStream::Open(file, FileMode::Write);

	fs->write(board.getNumCities());

	for (int i = 0; i < board.getNumCities(); i++) {
		City* city = board.getCity(i);
		fs->write(city->name);
		for (int x = 0; x < 4; x++) {
			fs->write(city->cube[x]);
		}
		fs->write(city->research);
		fs->write(city->color);
		fs->write(city->x);
		fs->write(city->y);

		auto adjNodes = city->getAdjacentNodes();
		fs->write(adjNodes.size());
		for (int x = 0; x < adjNodes.size(); x++) {
			fs->write(adjNodes.at(x));
		}
	}

	delete fs;
}