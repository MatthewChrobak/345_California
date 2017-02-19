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

	static const std::string _nodeFile;
	void loadNodes(std::string nodeFile);
	void saveNodes(std::string nodeFile);

	static const std::string _playerFile;
	void loadPlayers(std::string playerFile);
	void savePlayers(std::string playerFile);

};

