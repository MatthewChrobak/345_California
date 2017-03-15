#pragma once
#include "Paths.h"
#include <string>
#include <vector>
#include <iostream>
#include <random>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

enum PlayerCardType
{
	City_Card,
	Epidemic_Card,
	Event_Card
};

class PlayerCard {

public:
	PlayerCardType getType();
	virtual void playCard() = 0;
	virtual std::string getSurfaceName() = 0;

protected:
	PlayerCardType _cardType;

public:
	static vector <string> playerCards;
	static vector <string> playerCardsDeck;

public:
	PlayerCard();
	~PlayerCard();

public:
	
	static string getPlayerCards();
	static string getSingleCard(int cardPosition);

	static void playerCardGameOver();          //Game over if playerCardsDeck = 0
	static int getVectorSize();                //Retrieves the size of a vector

	static void removeSingleCard(int cardPosition);             //Removes a single card from a vector at a specific position
	static void setPlayerCards(int numberOfCards);              //Sets a number of cards to a player
	static void clearVector();                                  //Clears a vector from all its values
	static void getEventDescription();                          //Retrieves the description of an event card
	static void getEpidemicDescription();                       //Retrieves the description of an epidemic card
	static void buildStationPC();                               //Discards enough cards to build a research station
	static void useEpidemic();                                  //Discards Epidemic cards if player picks one
	static void setPlayerCardDeck();

};
