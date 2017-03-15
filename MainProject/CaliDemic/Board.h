#pragma once
#include "InfectionColors.h"
#include "CityGraph.h"
#include "City.h"
#include "Board.h"
#include "Player.h"
#include "ActionCounter.h"
#include <vector>



class Board
{
public:

	Board(std::string saveFolder);
	~Board();

	void save(std::string saveFolder);
	//player creation, it might be modify for future project purpose
	void playerCreation();

	void addCity(City* city);
	City* getCity(int index);
	int getNumCities();

	/*
	This is to change turn once the number of action is reach
	*/
	void playerTurnChange();
	/*
	This is to know the current turn of a player
	*/
	Player& getCurrentTurnPlayer();
	Player& getPlayer(int index);
	int getNumberOfPlayers();
	int currentTurnPlayer = 0;

	/*
	bank of all cities that can be infected
	the idea behind that is if the user decides to make 
	his own city than we can make his own city's infectionCard
	*/
	static std::vector<int> infectionCityCards;
	static void infectionCityCardsInitializor();

private:
	CityGraph* _cities;
	std::vector<Player*> _players;

	void loadNodes(std::string nodesFile);
	void saveNodes(std::string nodesFile);

	void loadPlayers(std::string playerFile);
	void savePlayers(std::string playerFile);

};

