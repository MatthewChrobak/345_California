#pragma once
#include "CityGraph.h"
#include "City.h"

class Board
{
public:
	Board(std::string savefolder);
	~Board();

	void save(std::string savefolder);
	City* getCity(int index);
	int getNumCities();

private:
	CityGraph* _cities;
	static const std::string _nodeFile;

	void loadNodes(std::string nodeFile);
};

