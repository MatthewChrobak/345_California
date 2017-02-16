#include "Board.h"
#include "City.h"
#include "FileStream.h"

const std::string Board::_nodeFile = "nodes.dat";


Board::Board(std::string savefolder)
{
	this->loadNodes(savefolder + Board::_nodeFile);
}

void Board::loadNodes(std::string nodefile)
{
	FileStream* fs = FileStream::Open(nodefile, FileMode::Read);

	// Figure out how many nodes there are, and initiaize a board with that many
	// nodes on it.
	int numNodes = fs->readInt();
	this->_cities = new CityGraph(numNodes);

	// Read every node's data.
	for (int i = 0; i < numNodes; i++)
	{
		City* city = new City();
		city->Name = fs->readString();
		int infection1 = fs->readInt();
		int infection2 = fs->readInt();
		int infection3 = fs->readInt();
		city->Color = (InfectionColor)fs->readInt();
		city->X = fs->readInt();
		city->Y = fs->readInt();

		// Read through all the nodes adjacent to this node
		// and add it to its colleciton.
		int numAdjacentNodes = fs->readInt();
		for (int x = 0; x < numAdjacentNodes; x++) {
			city->addAdjacentNode(fs->readInt());
		}

		// Set the i'th city on the current board to the created city.
		this->_cities->setNode(i, city);
	}
}


Board::~Board()
{
	// TODO
}


void Board::save(std::string savefolder)
{
	// TODO
}


City* Board::getCity(int index)
{
	return (City*)(this->_cities->getNode(index));
}

int Board::getNumCities()
{
	return this->_cities->getNumNodes();
}