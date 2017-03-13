#include "Board.h"
#include "FileStream.h"
#include "FileSystem.h"
#include "Paths.h"
#include <iostream>

Board::Board(std::string savefolder)
{
	this->loadNodes();
	this->loadPlayers(savefolder + PLAYER_DATA_FILE);
}

Board::~Board()
{
	delete this->player;
	delete this->_cities;
}

void Board::save(std::string saveFolder)
{
#ifdef ADMIN_EDITOR
	// Only save the nodes if we're in ADMIN_EDIT mode.
	this->saveNodes();
#endif
	this->savePlayers(saveFolder + PLAYER_DATA_FILE);
}


void Board::loadNodes()
{
	this->_cities = new CityGraph();
	std::string nodefile = FileSystem::getStartupPath() + DATA_FOLDER + NODES_DATA_FILE;


	// If the file does not exist, there's nothing to load.
	if (!FileSystem::fileExists(nodefile)) {
		return;
	}

	FileStream* fs = FileStream::Open(nodefile, FileMode::Read);

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

void Board::saveNodes()
{
	FileStream* fs = FileStream::Open(FileSystem::getStartupPath() + DATA_FOLDER + NODES_DATA_FILE, FileMode::Write);

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
		for (int x = 0; x < nodes.size(); x++) {
			fs->write(nodes[x]);
		}
	}

	delete fs;
}


void Board::savePlayers(std::string playerFile)
{
	FileStream* fs = FileStream::Open(playerFile, FileMode::Write);

	// Write the player data.
	fs->write(player->pawn->cityIndex);

	delete fs;
}

void Board::loadPlayers(std::string playerFile)
{
	this->player = new Player();

	// If the file does not exist, there's nothing to load.
	if (!FileSystem::fileExists(playerFile)) {
		return;
	}

	FileStream* fs = FileStream::Open(playerFile, FileMode::Read);

	// Read the player data.
	player->pawn->cityIndex = fs->readInt();

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