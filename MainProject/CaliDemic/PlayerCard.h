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

	PlayerCardType getType();
	virtual void playCard() = 0;
	virtual std::string getSurfaceName() = 0;

protected:
	PlayerCardType _cardType;

public:
	std::vector <string> playerCards;

	int cardCounter = 48;   //This value will decrease as more cards are played.

	vector <string> playerCardsDeck;

	vector <string> epidemic;

public:
	PlayerCard();
	~PlayerCard();

public:
	
	string getPlayerCards();
	string getSingleCard(int cardPosition);

	int getCardCounter();               //Counter for number of cards left in PlayerCards
	int getVectorSize();                //Retrieves the size of a vector

	void removeSingleCard(int cardPosition);             //Removes a single card from a vector at a specific position
	void setPlayerCards(int numberOfCards);              //Sets a number of cards to a player
	void clearVector();                                  //Clears a vector from all its values
	void getEventDescription();                          //Retrieves the description of an event card
	void getEpidemicDescription();                       //Retrieves the description of an epidemic card
	void buildStationPC();                               //Discards enough cards to build a research station
	void useEpidemic();                                  //Discards Epidemic cards if player picks one
	void setPlayerCardDeck();

	 //void listCities(); //To test the list of cities remaining in PlayerCards.
};
