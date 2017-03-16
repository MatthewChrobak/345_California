#pragma once
#include "InfectionColors.h"
#include "CityGraph.h"
#include "City.h"
#include "Board.h"
#include "Player.h"
#include "ActionCounter.h"
#include <vector>
#include <stack>
#include "PlayerCard.h"



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
	//disease cure boolean
	//index value indicating disease according it's color...bool array if cured update bool value

	bool isCured[4];
	

	/*
	This is to change turn once the number of action is reach
	*/
	bool playerTurnChange();
	/*
	This is to know the current turn of a player
	*/
	Player& getCurrentTurnPlayer();
	Player& getPlayer(int index);
	int getNumberOfPlayers();
	int currentTurnPlayer = 0;
	std::vector<std::string> playerCardDeck;


	/*
	bank of all cities that can be infected
	the idea behind that is if the user decides to make 
	his own city than we can make his own city's infectionCard
	*/
	std::vector<int> infectionCityCards;
	void infectionCityCardsInitializor();
	void drawCards();

private:
	CityGraph* _cities;
	std::vector<Player*> _players;
	std::stack<PlayerCard*> _playerWithdrawPile;

	void loadBoardData(std::string boardFile);
	void saveBoardData(std::string boardFile);

	void loadNodes(std::string nodesFile);
	void saveNodes(std::string nodesFile);

	void loadPlayers(std::string playerFile);
	void savePlayers(std::string playerFile);

	void generatePlayerCards();
};

