#pragma once
#include "Pawn.h"
#include "Cities.h"

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
	Cities *targetCity;

public:
	Infection_Card(Cities *targetCity);

};
//this role card class inherited class card
class Role_Card : public Card{

};
//this epedimic card class inherited class card
class Epedemic_Card : public Card{

};
//this event card class inherited class card
class Event_Card : public Card{

};




