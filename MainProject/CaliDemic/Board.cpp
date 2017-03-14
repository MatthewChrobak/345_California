#include "Board.h"
#include "FileStream.h"
#include "FileSystem.h"
#include "PlayerActions.h"
#include <iostream>
#include <vector>

#ifdef DEBUG
#include <assert.h>
#endif

Board::Board(std::string saveFolder)
{
	this->loadNodes(saveFolder + NODES_DATA_FILE);
	this->loadPlayers(saveFolder + PLAYER_DATA_FILE);
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

	for (unsigned int i = 0; i < numberOfPlayers; i++)
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

	// Write the player data.
	for (unsigned int i = 0; i < _players.size(); i++)
		fs->write(_players.at(i)->pawn->cityIndex);

	delete fs;
}

void Board::loadPlayers(std::string playerFile)
{

	// If the file does not exist, there's nothing to load.
	if (!FileSystem::fileExists(playerFile)) {
		return;
	}

	FileStream* fs = FileStream::Open(playerFile, FileMode::Read);

	// Read the player data.
	for (unsigned int i = 0; i < _players.size(); i++)
		_players.at(i)->pawn->cityIndex = fs->readInt();

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
	return *this->_players[Board::currentTurnPlayer];
}

Player& Board::getPlayer(int index)
{
#ifdef DEBUG
	assert(index >= 0 && index < this->numberOfPlayers);
#endif
	return *this->_players[index];
}

int Board::getNumberOfPlayers()
{
	return this->numberOfPlayers;
}