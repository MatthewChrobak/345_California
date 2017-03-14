#pragma once
#include "InfectionColors.h"
#include "CityGraph.h"
#include "City.h"
#include "Board.h"
#include "Player.h"

class Board
{
public:
	Player* player;

	Board(std::string saveFolder);
	~Board();

	void save(std::string saveFolder);

	void addCity(City* city);
	City* getCity(int index);
	int getNumCities();

private:
	CityGraph* _cities;

	void loadNodes(std::string nodesFile);
	void saveNodes(std::string nodesFile);

	void loadPlayers(std::string playerFile);
	void savePlayers(std::string playerFile);

};

