#include "Board.h"
#include "FileStream.h"
#include "FileSystem.h"
#include "PlayerActions.h"

#include "InfectionCard.h"
#include "GuiManager.h"
#include "Game.h"
#include <iostream>
#include <vector>
#include "CityCard.h"
#include "RandomNumberGenerator.h"
#include <time.h>
#include "RoleCard.h"
#include "EventCard.h"
#include "Frames.h"
#include "EpidemicCard.h"
#include "RandomNumberGenerator.h"

#ifdef DEBUG
#include <assert.h>
#endif


void Board::tryStartGame()
{
	// Can we start the game?
	if (this->_startGame) {
		this->_startGame = false;
		GuiManager::showMsgBox("The game has started!");
		this->generateGameContentAtStartOfGame();
	}
}
void Board::generateGameContentAtStartOfGame()
{
	this->generatePlayerCards();

	// Give each player four cards, while we have cards.
	for (int playerIndex = 0; playerIndex < this->getNumberOfPlayers(); playerIndex++) {
		for (int i = 0; i < 4; i++) {
			if (this->_playerWithdrawPile.size() == 0) {
				break;
			} else {
				this->getPlayer(playerIndex).addCard(this->_playerWithdrawPile.at(this->_playerWithdrawPile.size() - 1));
				this->_playerWithdrawPile.pop_back();
			}
		}
		int i = RandomNumberGenerator::next(0, 6);
		// Give each player a random role card.
		RoleCard *p = new RoleCard(RoleCard::roleCardNames[i]);
		this->getPlayer(playerIndex).setRoleCard(p);
	}
	//===========================================================
	//intializing infectionCardDeck
	Board::infectionCityCardsInitializor();


	//starting the infection with 9 cities (required 9 cities if not null exception)
	for (int i = 0; i < STARTING_INFECTION_CARD && i < infectionCityCards.size(); i++)
	{
		InfectionCard::infectCityCube(infectionCityCards.at(0));
		Board::discardInfectionCard.push_back(infectionCityCards.at(0));
		Board::infectionCityCards.erase(infectionCityCards.begin());
	}
}

/*
This will initialize the infectionCard deck
*/
void Board::infectionCityCardsInitializor()
{
	infectionCityCards.push_back(0);
	infectionCityCards.push_back(0);
	infectionCityCards.push_back(0);

	for (int i = 1; i < this->getNumCities(); i++)
	{
		int rng = RandomNumberGenerator::next(0, infectionCityCards.size());
		infectionCityCards.insert(infectionCityCards.begin() + rng, i);
		
		rng = RandomNumberGenerator::next(0, infectionCityCards.size());
		infectionCityCards.insert(infectionCityCards.begin() + rng, i);

		rng = RandomNumberGenerator::next(0, infectionCityCards.size());
		infectionCityCards.insert(infectionCityCards.begin() + rng, i);
	}
	infectionCityCards.shrink_to_fit();
}

Board::Board(std::string saveFolder)
{
	// Load the board data.
	this->loadBoardData(saveFolder + BOARD_DATA_FILE);
	this->loadNodes(saveFolder + NODES_DATA_FILE);

	// If we're not editing, load the players.
	if (!this->_editingMap) {
		this->loadPlayers(saveFolder + PLAYER_DATA_FILE);
	} else {
		GuiManager::showMsgBox("In Map Editing mode. Hit 'Done Editing' to save the map and start playing.");
	}
}

Board::~Board()
{
	for (unsigned int i = 0; i < this->_players.size();i++)
		delete this->_players.at(i);

	while (!this->_playerWithdrawPile.empty()) {
		delete this->_playerWithdrawPile.at(this->_playerWithdrawPile.size()-1);
		this->_playerWithdrawPile.pop_back();
	}

	delete this->_cities;
}

void Board::save(std::string saveFolder)
{
	this->saveBoardData(saveFolder + BOARD_DATA_FILE);
	this->saveNodes(saveFolder + NODES_DATA_FILE);
	this->savePlayers(saveFolder + PLAYER_DATA_FILE);
}

void Board::loadBoardData(std::string boardFile)
{
	// If the file does not exist, there's nothing to load.
	if (!FileSystem::fileExists(boardFile)) {
		return;
	}

	FileStream* fs = FileStream::Open(boardFile, FileMode::Read);

	this->_editingMap = fs->readBool();
	this->_startGame = fs->readBool();
	currentTurnPlayer = fs->readInt();
	Game::actionCounter = fs->readInt();
	for (int i = 0; i < InfectionColor::InfectionColor_Length; i++) {
		this->isCured[i] = fs->readBool();
	}

	// Cubes counters and research center.
	Game::numOfBlackCube = fs->readInt();
	Game::numOfYellowCube = fs->readInt();
	Game::numOfBlueCube = fs->readInt();
	Game::numOfRedCube = fs->readInt();
	Game::numOfResearchCenter = fs->readInt();


	City::outbreakCount = fs->readInt();
	this->setActualInfectionRate(fs->readInt());


	// Read all player cards in the withdraw pile.
	int numPlayerCards = fs->readInt();
	for (int i = 0; i < numPlayerCards; i++) {
		int type = fs->readInt();

		if (type == PlayerCardType::City_Card) {
			this->_playerWithdrawPile.push_back(new CityCard(fs->readInt()));
		} else if (type == PlayerCardType::Event_Card) {
			// This is nonesense.
			fs->readInt();
		}
	}

	// Read all infection cards in the pickup pile.
	int numInfectionCityCards = fs->readInt();
	for (int i = 0; i < numInfectionCityCards; i++) {
		this->infectionCityCards.push_back(fs->readInt());
	}

	// Read all infection cards in the discard pile.
	int numInfectionCityCardsDiscard = fs->readInt();
	for (int i = 0; i < numInfectionCityCardsDiscard; i++) {
		this->discardInfectionCard.push_back(fs->readInt());
	}

	delete fs;
}

void Board::saveBoardData(std::string boardFile)
{
	FileStream* fs = FileStream::Open(boardFile, FileMode::Write);

	fs->write(this->_editingMap);
	fs->write(this->_startGame);
	fs->write(currentTurnPlayer);
	fs->write(Game::actionCounter);
	for (int i = 0; i < InfectionColor::InfectionColor_Length; i++) {
		fs->write(this->isCured[i]);
	}

	// Cubes counters and research center.
	fs->write(Game::numOfBlackCube);
	fs->write(Game::numOfYellowCube);
	fs->write(Game::numOfBlueCube);
	fs->write(Game::numOfRedCube);
	fs->write(Game::numOfResearchCenter);

	fs->write(City::outbreakCount);
	fs->write(this->getActualInfectionRate());

	// Save all the cards in the withdraw pile.
	fs->write(this->_playerWithdrawPile.size());
	for (unsigned int i = 0; i < this->_playerWithdrawPile.size(); i++) {
		PlayerCard* card = this->_playerWithdrawPile.at(i);
		fs->write(card->getType());

		if (card->getType() == PlayerCardType::City_Card) {
			fs->write(((CityCard*)card)->cityIndex);
		} else {
			fs->write(-1);
		}
	}

	// Save all epidemic cards in the withdraw pile.
	fs->write(this->infectionCityCards.size());
	for (unsigned int i = 0; i < this->infectionCityCards.size(); i++) {
		fs->write(this->infectionCityCards.at(i));
	}

	// Save all the epidemic cards in the discard pile.
	fs->write(this->discardInfectionCard.size());
	for (unsigned int i = 0; i < this->discardInfectionCard.size(); i++) {
		fs->write(this->discardInfectionCard.at(i));
	}

	delete fs;
}


void Board::loadNodes(std::string nodesFile)
{
	this->_cities = new CityGraph();

	// If the file does not exist, there's nothing to load.
	if (!FileSystem::fileExists(nodesFile)) {
		return;
	}

	FileStream* fs = FileStream::Open(nodesFile, FileMode::Read);

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
		this->_cities->addNode(city);
	}

	delete fs;
}

void Board::saveNodes(std::string nodesFile)
{
	FileStream* fs = FileStream::Open(nodesFile, FileMode::Write);

	fs->write(this->getNumCities());

	// Write every node's data
	for (int i = 0; i < this->getNumCities(); i++) {
		City* city = this->getCity(i);

		fs->write(city->name);
		fs->write(city->cube[0]);
		fs->write(city->cube[1]);
		fs->write(city->cube[2]);
		fs->write(city->cube[3]);
		fs->write(city->research);
		fs->write(city->color);
		fs->write(city->x);
		fs->write(city->y);

		// Get and 
		std::vector<int> nodes = city->getAdjacentNodes();
		fs->write(nodes.size());
		for (unsigned int x = 0; x < nodes.size(); x++) {
			fs->write(nodes[x]);
		}
	}

	delete fs;
}


void Board::savePlayers(std::string playerFile)
{
	// We don't want to save no players.
	if (this->_players.size() == 0) {
		return;
	}

	FileStream* fs = FileStream::Open(playerFile, FileMode::Write);

	fs->write(this->_players.size());

	// Write the player data.
	for (unsigned int playerIndex = 0; playerIndex < _players.size(); playerIndex++) {
		Player& player = this->getPlayer(playerIndex);

		fs->write(player.pawn->cityIndex);
		fs->write(player.getRoleCard()->getRoleCardVal());

		for (int cardIndex = 0; cardIndex < MAX_PLAYER_CARDS; cardIndex++) {
			PlayerCard* card = player.getCard(cardIndex);

			// If the card is null, write -1 to signify no card type.
			if (card == nullptr) {
				
				fs->write(-1);
			} else {
				fs->write(card->getType());

				// For now, assume the player just has city cards.
				switch (card->getType()) {
					case PlayerCardType::City_Card:
					{
						CityCard* cityCard = (CityCard*)card;
						fs->write(cityCard->cityIndex);
					}break;
				}
			}
			
		}
	}

	delete fs;
}

void Board::loadPlayers(std::string playerFile)
{

	// If the file does not exist, there's nothing to load.
	if (!FileSystem::fileExists(playerFile)) {
		//random number gen starts here ->
		const int AMOUNT = 2; //amount of random numbers that need to be generated
		const int MAX = 6; //maximum value (of course, this must be at least the same as AMOUNT;

		int value[AMOUNT]; //array to store the random numbers in

		srand((unsigned)time(NULL)); //always seed your RNG before using it

									 //generate random numbers:
		for (unsigned int i = 0; i<AMOUNT; i++) {
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

		//create two roleCards 
		RoleCard* rc1 = new RoleCard(RoleCard::roleCardNames[value[0]]);
		RoleCard* rc2 = new RoleCard(RoleCard::roleCardNames[value[1]]);

		//add roleCard to the players
		Player* playerOne = new Player();
		playerOne->setRoleCard(rc1);
		this->_players.push_back(playerOne);


		Player* playerTwo = new Player();
		playerTwo->setRoleCard(rc2);
		this->_players.push_back(playerTwo);
		return;
	}

	FileStream* fs = FileStream::Open(playerFile, FileMode::Read);

	int numPlayers = fs->readInt();

	/*
	Read the player data & the new player is just a blank object
	so we can actually read from the file because the vector size is not initialize
	*/
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

		this->_players.push_back(player);
	}

	delete fs;
}


//Draw 2 cards
void Board::drawCards()
{
	for (int i = 0; i < 2; i++)
	{
		if (this->_playerWithdrawPile.size() != 0) {
			this->getCurrentTurnPlayer().addCard(this->_playerWithdrawPile.at(this->_playerWithdrawPile.size() - 1));
			this->_playerWithdrawPile.pop_back();
		}
	}
}


//Generates the playerCards deck
void Board::generatePlayerCards()
{
	// Create a vector of city indexes.
	std::vector<int> cityIds;
	for (int i = 0; i < this->getNumCities(); i++) {
		cityIds.push_back(i);
	}

	while (cityIds.size() != 0) {
		int rng = RandomNumberGenerator::next(0, cityIds.size());

		//Add the city to the withdraw pile.
		CityCard* card = new CityCard(cityIds.at(rng));
		this->_playerWithdrawPile.push_back(card);

		//Remove the id from the vector.
		cityIds.erase(cityIds.begin() + rng);
	}

	//Temporarily hard-coding event cards and add them in the deck
	EventCard* card1 = new EventCard(Airlift);
	EventCard* card2 = new EventCard(OneQuietNight);
	EventCard* card3 = new EventCard(ResilientPopulation);
	EventCard* card4 = new EventCard(GovernmentGrant);
	EventCard* card5 = new EventCard(Forecast);

	std::vector<EventCard*> tempEventVector {card1, card2, card3, card4, card5};

	for (unsigned int i = 0; i < tempEventVector.size(); i++) {

		int rng = RandomNumberGenerator::next(0, _playerWithdrawPile.size());
		this->_playerWithdrawPile.insert(this->_playerWithdrawPile.begin() + rng, tempEventVector[i]);
	}

	//Adding epidemic cards to the player deck
	for (int i = 0; i < NUMBER_OF_EPIDEMIC; i++) {
		int rng = RandomNumberGenerator::next(0, _playerWithdrawPile.size());
		EpidemicCard* epidemicCard = new EpidemicCard();
		this->_playerWithdrawPile.insert(this->_playerWithdrawPile.begin() + rng, epidemicCard);
	}

}


City* Board::getCity(int index)
{
	if (index < 0 || index >= this->getNumCities()) {
		return nullptr;
	}
	return (City*)(this->_cities->getNode(index));
}

void Board::addCity(City* city)
{
	this->_cities->addNode(city);
}

int Board::getNumCities()
{
	return this->_cities->getNumNodes();
}

Player& Board::getCurrentTurnPlayer()
{
#ifdef DEBUG
	assert(this->_players.size() > 0);
#endif
	return *this->_players[Board::currentTurnPlayer];
}

Player& Board::getPlayer(int index)
{
#ifdef DEBUG
	assert(index >= 0 && index < (int)this->_players.size());
#endif
	return *this->_players[index];
}

int Board::getNumberOfPlayers()
{
	return this->_players.size();
}

/*
this will check the number of action and change turn if it reaches 
4 actions
*/
bool Board::playerTurnChange()
{
	bool turnChanged = false;
	if (Game::actionCounter == 0)
	{
		this->currentTurnPlayer = ((this->currentTurnPlayer) + 1) % _players.size();
		Game::resetActionCounter();
		turnChanged = true;
	}

	return turnChanged;
}


int Board::getInfectionRate()
{
	if (this->_infectionRate <= 2) {
		return 2;
	}

	if (this->_infectionRate <= 4) {
		return 3;
	}

	return 4;
}

void Board::incremenetInfectionRate()
{
	this->_infectionRate += 1;
}

//draw infections card at the end of the turn
void Board::drawInfectionCard()
{
	for (int i = 0; i < this->getInfectionRate(); i++)
	{
		if (infectionCityCards.size() != 0)
		{
			// Pick up the card only if it's not cured.
			if (isCured[Game::getGameBoard()->getCity(infectionCityCards.at(0))->color] != true)
			{
				InfectionCard::infectCityCube(infectionCityCards.at(0));
			}
			// Decrement i so we pick another card.
			i--;

			// Remove it from the pile.
			Board::discardInfectionCard.push_back(infectionCityCards.at(0));
			Board::infectionCityCards.erase(infectionCityCards.begin());
			Board::infectionCityCards.shrink_to_fit();
		}
	}
}

bool Board::isEditingMap()
{
	return this->_editingMap;
}

void Board::submitMap()
{
	this->_editingMap = false;
	this->_startGame = true;
	Game::save();
	GuiManager::handleWindowClose();
}


void Board::checkTurn()
{
	Board* board = Game::getGameBoard();
	Player& player = board->getCurrentTurnPlayer();

	if (board->playerTurnChange() == true)
	{
		board->drawCards();
		GuiManager::showMsgBox("Your current hand after picking two cards.");
		GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = true;

		int numberOfCards = player.getNumberOfCards();

		if (numberOfCards >= 6) //You only excess cards only when you draw while you have 6 or more cards
		{
			GuiManager::showMsgBox("Please discard " + std::to_string((numberOfCards + 2) % 7) + " cards.");
			GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = true;// show message that we have to discard.
			GameFrame::PlayerAction = PlayerActions::DiscardCards;

		}
		//draw infection card and the game will do the infection automatically
		Game::getGameBoard()->drawInfectionCard();
		GuiManager::showMsgBox("End of your turn.");
	}
}

int Board::getActualInfectionRate()
{
	return this->_infectionRate;
}

void Board::setActualInfectionRate(int value)
{
	this->_infectionRate = value;

}