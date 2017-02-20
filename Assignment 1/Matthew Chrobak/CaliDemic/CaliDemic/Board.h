#pragma once
#include "CityGraph.h"
#include "City.h"
#include "Board.h"
#include "Player.h"

class Board
{
public:
	Player* player;

	Board(std::string savefolder);
	~Board();

	void save(std::string savefolder);
	void addCity(City* city);
	City* getCity(int index);
	int getNumCities();

private:
	CityGraph* _cities;

	void loadNodes();
	void saveNodes();

	void loadPlayers(std::string playerFile);
	void savePlayers(std::string playerFile);

};

