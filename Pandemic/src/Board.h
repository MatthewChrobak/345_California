#pragma once
#include "InfectionColors.h"
#include "CityGraph.h"
#include "City.h"
#include "Board.h"
#include "Player.h"
#include <vector>
#include <stack>
#include "PlayerCard.h"
#include "EventCard.h"

#define STARTING_INFECTION_CARD 9
#define INFECTION_RATE 0

class Board
{
public:
	Board();
	~Board();

	void addPlayer(Player* player);
	void generateGameContentAtStartOfGame();
	void addCity(City* city);
	City* getCity(int index);
	int getNumCities();
	
	//disease cure boolean
	//index value indicating disease according it's color...bool array if cured update bool value

	bool isCured[4];
	bool oneQuietNight = false; // In case the player plays a one Quiet night card
	
	static void checkTurn();

	/*
	This is to change turn once the number of action is reach
	holding the next player index
	*/
	bool playerTurnChange();
	/*
	This is to know the current turn of a player
	*/
	Player& getCurrentTurnPlayer();
	Player& getPlayer(int index);
	int getNumberOfPlayers();
	int currentTurnPlayer = 0;
	void drawCards(); // Draw 2 cards from the player deck
	std::vector<std::string> playerCardDeck;
	int checkChange = 0;


	int getInfectionRate();
	static void incrementInfectionRate();

	int getActualInfectionRate();
	void setActualInfectionRate(int value);

	/*
	bank of all cities that can be infected
	the idea behind that is if the user decides to make 
	his own city than we can make his own city's infectionCard
	and we have an discard pile
	*/
	std::vector<PlayerCard*> playerWithdrawPile;
	std::vector<int> infectionCityCards;
	std::vector<int> discardInfectionCard;
	void infectionCityCardsInitializor();
	void drawInfectionCard();
	void drawLastInfectionCard();
	void shuffleDiscardedInfectionDeck();

	static int _infectionRate;
	int drawTopInfectionCard();

private:
	CityGraph* _cities;
	std::vector<Player*> _players;
	std::vector<int> playerIndex;

	void generatePlayerCards();
};