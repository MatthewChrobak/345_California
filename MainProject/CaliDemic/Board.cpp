#include "Board.h"
#include "FileStream.h"
#include "FileSystem.h"
#include "PlayerActions.h"
#include "ActionCounter.h"
#include "Game.h"
#include <iostream>
#include <vector>
#include "CityCard.h"

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
		infectionCityCards.push_back(i);
		infectionCityCards.push_back(i);
	}
	infectionCityCards.shrink_to_fit();

}

Board::Board(std::string saveFolder)
{
	this->loadNodes(saveFolder + NODES_DATA_FILE);
	this->loadPlayers(saveFolder + PLAYER_DATA_FILE);

	for (int i = 0; i < 7; i++) {
		getCurrentTurnPlayer().addCard(new CityCard(i)); 
	}
}

Board::~Board()
{
	for (unsigned int i = 0; i < this->_players.size();i++)
		delete this->_players.at(i);

	delete this->_cities;
}

void Board::save(std::string saveFolder)
{
	this->saveNodes(saveFolder + NODES_DATA_FILE);
	this->savePlayers(saveFolder + PLAYER_DATA_FILE);
}

void Board::playerCreation()
{
	int numberOfPlayer = 0;
	std::cout << "How many player do you want to create? " << std::endl;
	std::cin >> numberOfPlayer;

	for (int i = 0; i < numberOfPlayer; i++)
		_players.push_back(new Player());

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

	fs->write(_players.size());

	// Write the player data.
	for (unsigned int i = 0; i < _players.size(); i++)
		fs->write(_players.at(i)->pawn->cityIndex);

	delete fs;
}

void Board::loadPlayers(std::string playerFile)
{

	// If the file does not exist, there's nothing to load.
	if (!FileSystem::fileExists(playerFile)) {
		this->_players.push_back(new Player());
		this->_players.push_back(new Player());
		return;
	}

	FileStream* fs = FileStream::Open(playerFile, FileMode::Read);

	int numPlayers = fs->readInt();

	/*
	Read the player data & the new player is just a blank object
	so we can actually read from the file because the vector size is not initialize
	*/
	for (int i = 0; i < numPlayers; i++) {
		Player* player = new Player();
		player->pawn->cityIndex = fs->readInt();
		this->_players.push_back(player);
	}

	delete fs;
}


City* Board::getCity(int index)
{
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
void Board::playerTurnChange()
{
	if (actionCounter == 0)
	{
		this->currentTurnPlayer = ((this->currentTurnPlayer) + 1) % _players.size();
		resetActionCounter();
	}
}