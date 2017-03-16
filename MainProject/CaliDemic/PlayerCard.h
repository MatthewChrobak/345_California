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
	vector <string> playerCards;
	vector <string> playerCardsDeck;

public:
	PlayerCard();
	~PlayerCard();

public:
	
	string getPlayerCards();
	string getSingleCard(int cardPosition);

	void playerCardGameOver();          //Game over if playerCardsDeck = 0
	int getVectorSize();                //Retrieves the size of a vector

	void removeSingleCard(int cardPosition);             //Removes a single card from a vector at a specific position
	void setPlayerCards(int numberOfCards);              //Sets a number of cards to a player
	void clearVector();                                  //Clears a vector from all its values
	void getEventDescription();                          //Retrieves the description of an event card
	void getEpidemicDescription();                       //Retrieves the description of an epidemic card
	void buildStationPC();                               //Discards enough cards to build a research station
	void useEpidemic();                                  //Discards Epidemic cards if player picks one
	void setPlayerCardDeck();

};
