#include "Board.h"
#include "FileStream.h"
#include "FileSystem.h"
#include "PlayerActions.h"
#include "ActionCounter.h"
#include "Game.h"
#include <iostream>
#include <vector>
#include "CityCard.h"
#include "RandomNumberGenerator.h"
#include <time.h>
#include "RoleCard.h"
#ifdef DEBUG
#include <assert.h>
#endif

/*
This will initialize the infectionCard deck
*/
void Board::infectionCityCardsInitializor()
{
	for (int i = 0; i < Game::getGameBoard()->getNumCities(); i++)
	{
		infectionCityCards.push_back(i);
	}
	infectionCityCards.shrink_to_fit();

}

Board::Board(std::string saveFolder)
{
	this->loadBoardData(saveFolder + BOARD_DATA_FILE);
	this->loadNodes(saveFolder + NODES_DATA_FILE);
	this->loadPlayers(saveFolder + PLAYER_DATA_FILE);
}

Board::~Board()
{
	for (unsigned int i = 0; i < this->_players.size();i++)
		delete this->_players.at(i);

	while (!this->_playerWithdrawPile.empty()) {
		delete this->_playerWithdrawPile.top();
		this->_playerWithdrawPile.pop();
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

	delete fs;
}

void Board::saveBoardData(std::string boardFile)
{
	FileStream* fs = FileStream::Open(boardFile, FileMode::Read);

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

		srand(time(NULL)); //always seed your RNG before using it

		//generate random numbers:
		for (int i = 0; i<AMOUNT; i++)
		{
			bool check; //variable to check or number is already used
			int n; //variable to store the number in
			do
			{
				n = rand() % MAX;
				//check or number is already used:
				check = true;
				for (int j = 0; j<i; j++)
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

		// TODO: Get the role of the player.
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
		this->_playerWithdrawPile.push(card);

		//Remove the id from the vector.
		cityIds.erase(cityIds.begin() + rng);
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
	boolean turnChanged = false;
	if (actionCounter == 0)
	{
		this->currentTurnPlayer = ((this->currentTurnPlayer) + 1) % _players.size();
		resetActionCounter();
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