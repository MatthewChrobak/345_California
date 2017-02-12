#pragma once
#include "CityGraph.h"
#include "City.h"

class Board
{
public:
	Board(std::string savefolder);
	~Board();

	void Save(std::string savefolder);

	City* getCity(int index);
	int getNumCities();

private:
	CityGraph* _cities;

	static const std::string _nodeFile;
};

