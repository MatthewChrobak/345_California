#pragma once
#include <string>
#include "Pawn.h"
#include "Cities.h"
#include <ctime>
#include <cstdlib>

class Card{

};

//this reference card class inherited class card
class Reference_Card : public Card{

};
//this player card class inherited class card
class Player_Card : public Card{

};

//this infection card class inherited class card
class Infection_Card : public Card{
private:
	std::string infectCityNameCard;

public:
	Infection_Card(std::string infectCityNameCard);
	~Infection_Card();
	std::string getInfectCityNameCard();
	
};

//this role card class inherited class card
class Role_Card : public Card{
	Pawn* pawn;
};
//this epedimic card class inherited class card
class Epedemic_Card : public Card{

};
//this event card class inherited class card
class Event_Card : public Card{

};



