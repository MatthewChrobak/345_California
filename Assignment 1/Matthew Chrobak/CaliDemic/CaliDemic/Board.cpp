#include "Board.h"
#include "City.h"
#include <fstream>
#include <iostream>
#include <string>

const std::string Board::_nodeFile = "nodes.dat";


Board::Board(std::string savefolder)
{
	std::ifstream fs;
	fs.open(savefolder + Board::_nodeFile);


	if (fs.is_open()) {
		std::string line;

		std::getline(fs, line);
		int numNodes = std::stoi(line);
		this->_cities = new CityGraph(numNodes);
		std::cout << "Detected " << numNodes << " nodes..." << std::endl;

		int cityIndex = 0;

		for (int i = 0; i < numNodes; i++) {
			std::string cityName;
			std::string infection1;
			std::string infection2;
			std::string infection3;
			std::string cityColor;

			std::string x;
			std::string y;

			std::getline(fs, cityName);
			std::getline(fs, infection1);
			std::getline(fs, infection2);
			std::getline(fs, infection3);

			std::getline(fs, cityColor);

			std::getline(fs, x);

			std::getline(fs, y);

			City* city = new City(cityName);
			city->x = std::stoi(x);
			city->y = std::stoi(y);

			this->_cities->setNode(cityIndex, city);

			cityIndex++;
		}
	}
	

	fs.close();
}


Board::~Board()
{
}


void Board::Save(std::string savefolder)
{
	std::ofstream fs(savefolder + Board::_nodeFile);
	if (fs.is_open()) {
		fs << "New York\n";
		fs << -1 << "\n" << 1 << "\n" << 2 << "\n";
		fs << 2147000000 << "\n";
		fs << 100 << "\n";
		fs << 200 << "\n";
		fs.close();
	}
	else {
		std::cout << "Failed to open up file for writing " << std::endl;
	}
	

}


City* Board::getCity(int index)
{
	return static_cast<City*>(this->_cities->getNode(index));
}

int Board::getNumCities()
{
	return this->_cities->getNumNodes();
}