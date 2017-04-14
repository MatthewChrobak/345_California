#include "BoardBuilder.h"
#include "FileStream.h"
#include "FileSystem.h"
#include "CityCard.h"
#include "EventCard.h"
#include "InfectionCard.h"

#define BOARD_FILE "cities.dat"
#define BOARD_METAFILE "meta.dat"
#define PLAYER_FILE "players.dat"
#define DEFAULT_BOARD_FILE (FileSystem::getStartupPath() + "defaultcities.dat")
#define DEFAULT_BOARD_METAFILE (FileSystem::getStartupPath() + "defaultmeta.dat")

Board* BoardBuilder::loadNewGame(int numberOfPlayers)
{

	Board* board = new Board();

	try
	{
		if (numberOfPlayers < 2 || numberOfPlayers > 4) {
			throw "Invalid number of players";
		}

		// Maybe randomize this in the future.
		for (int i = 0; i < numberOfPlayers; i++) {
			board->addPlayer(new Player(RoleType::Dispatcher));
		}
		this->loadCities(DEFAULT_BOARD_FILE, *board);

		// Add the infection cards, and the player cards.
		for (int i = 0; i < board->getNumberOfCities(); i++) {
			board->getInfectionCityCards_Withdraw().insertAtTop(new InfectionCard(i));
			board->getPlayerCardsDeck().insertAtTop(new CityCard(i));
		}

		int numCardsEach = -1 * (board->getNumberOfPlayers() - 6);

		// Give each player their cards.
		for (int i = 0; i < board->getNumberOfPlayers(); i++) {
			Player& player = board->getPlayer(i);

			for (int x = 0; x < numCardsEach; x++) {
				player.addCard(board->getPlayerCardsDeck().pickFromTop());
			}
		}

		// Set the number of cubes.
		for (int i = 0; i < 4; i++) {
			board->setNumOfAvailableCubes(i, 24);
		}

		// Set the number of research centers, actions, infection rate, and outbreak count.
		board->setNumOfAvailableResearchCenters(6);
		board->setActionsRemaining(4);
		board->setInfectionRate(2);
		board->setOutbreakCount(0);
	}
	catch (const char* e) {
		delete board;
		board = nullptr;
	}

	return board;
}

Board* BoardBuilder::loadFromSave(std::string name)
{
	Board* board = new Board();
	std::string path = FileSystem::getStartupPath() + name + "\\";

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

	board.setCurrentIndexTurn(fs->readInt());
	board.setActionsRemaining(fs->readInt());
	for (int i = 0; i < 4; i++) {
		board.setIsDiseaseCured(i, fs->readBool());
		board.setNumOfAvailableCubes(i, fs->readInt());
	}

	board.setNumOfAvailableResearchCenters(fs->readInt());
	board.setOutbreakCount(fs->readInt());
	board.setInfectionRate(fs->readInt());

	// Player cards in the withdraw pile
	int numCards = fs->readInt();
	Deck& deck = board.getPlayerCardsDeck();
	while (deck.size() != numCards)
	{
		int type = fs->readInt();

		if (type == PlayerCardType::City_Card) {
			deck.insertAtTop(new CityCard(fs->readInt()));
		}
		else if (type == PlayerCardType::Event_Card) {
			// TODO
			fs->readInt();
		}
	}

	// Infection cards in the pickup pile.
	numCards = fs->readInt();
	deck = board.getInfectionCityCards_Withdraw();
	while (deck.size() != numCards)
	{
		deck.insertAtTop(new InfectionCard(fs->readInt()));
	}

	// Infection cards in the discard pile.
	numCards = fs->readInt(); 
	deck = board.getInfectionCityCards_Discard();
	while (deck.size() != numCards)
	{
		deck.insertAtTop(new InfectionCard(fs->readInt()));
	}

	delete fs;
}

void BoardBuilder::loadCities(std::string file, Board& board)
{
	if (!FileSystem::fileExists(file)) {
		throw "BoardBuilder::loadCities() - File does not exist";
	}

	FileStream* fs = FileStream::Open(file, FileMode::Read);

	// Figure out how many nodes there are.
	int numNodes = fs->readInt();

	// Read every node's data.
	while (board.getNumberOfCities() != numNodes)
	{
		City* city = new City();
		city->setName(fs->readString());
		city->setX(fs->readInt());
		city->setY(fs->readInt());
		city->setHasResearchCenter(fs->readBool());

		for (int i = 0; i < 4; i++) {
			city->setNumCubes(i, fs->readInt());
		}

		int numAdjNodes = fs->readInt();
		for (int i = 0; i < numAdjNodes; i++) {
			city->addAdjacentNode(fs->readInt());
		}

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
	while (board.getNumberOfPlayers() != numPlayers)
	{
		Player* player = new Player((RoleType)fs->readInt());
		player->pawn->cityIndex = fs->readInt();

		// Load all the player's cards.
		for (int i = 0; i < 7; i++) {
			int cardType = fs->readInt();

			// If the card type is non-negative, it means there's a card there.
			if (cardType != -1) {
				switch ((PlayerCardType)cardType)
				{
				case PlayerCardType::City_Card:
				{
					CityCard* card = new CityCard(fs->readInt());
					player->addCard(card);
				}
				}
			}
		}

		board.addPlayer(player);
	}

	delete fs;
}


void BoardBuilder::save(std::string savename, Board& board)
{
	std::string path = FileSystem::getStartupPath() + savename + "\\";
	FileSystem::createDirectory(path);

	this->saveBoardData(path + BOARD_METAFILE, board);
	this->saveCities(path + BOARD_FILE, board);
	this->savePlayers(path + PLAYER_FILE, board);
}

void BoardBuilder::saveBoardData(std::string file, Board& board)
{
	FileStream* fs = FileStream::Open(file, FileMode::Write);

	fs->write(board.getCurrentIndexTurn());
	fs->write(board.getActionsRemaining());

	for (int i = 0; i < 4; i++) {
		fs->write(board.getIsDiseaseCured(i));
		fs->write(board.getNumOfAvailableCubes(i));
	}

	fs->write(board.getNumOfAvailableResearchCenters());
	fs->write(board.getOutbreakCount());
	fs->write(board.getInfectionRate());

	Deck& deck = board.getPlayerCardsDeck();
	fs->write(deck.size());
	for (int i = 0; i < deck.size(); i++) {
		fs->write(deck.cardAt(i)->getType());

		if (deck.cardAt(i)->getType() == PlayerCardType::City_Card) {
			fs->write(((CityCard*)deck.cardAt(i))->getCityIndex());
		}
		else {
			// TODO
			fs->write(0);
		}
	}

	deck = board.getInfectionCityCards_Withdraw();
	fs->write(deck.size());
	for (int i = 0; i < deck.size(); i++) {
		fs->write(((InfectionCard*)deck.cardAt(i))->getCityIndex());
	}

	deck = board.getInfectionCityCards_Discard();
	fs->write(deck.size());
	for (int i = 0; i < deck.size(); i++) {
		fs->write(((InfectionCard*)deck.cardAt(i))->getCityIndex());
	}

	delete fs;
}


void BoardBuilder::savePlayers(std::string file, Board& board)
{
	FileStream* fs = FileStream::Open(file, FileMode::Write);

	fs->write(board.getNumberOfPlayers());

	for (int i = 0; i < board.getNumberOfPlayers(); i++) {
		Player& player = board.getPlayer(i);

		fs->write(player.roleCard->getRole());
		fs->write(player.pawn->cityIndex);

		for (int i = 0; i < 7; i++) {
			auto card = player.getCard(i);

			if (card != nullptr) {
				fs->write(card->getType());

				switch (card->getType())
				{
				case PlayerCardType::City_Card:
					fs->write(((CityCard*)card)->getCityIndex());
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

	fs->write(board.getNumberOfCities());

	for (int i = 0; i < board.getNumberOfCities(); i++) {
		City& city = board.getCity(i);
		fs->write(city.getName());
		fs->write(city.getX());
		fs->write(city.getY());
		fs->write(city.getHasResearchCenter());

		for (int x = 0; x < 4; x++) {
			fs->write(city.getNumCubes(x));
		}

		auto adjNodes = city.getAdjacentNodes();
		fs->write(adjNodes.size());
		for (int x = 0; x < adjNodes.size(); i++) {
			fs->write(adjNodes.at(x));
		}
	}

	delete fs;
}