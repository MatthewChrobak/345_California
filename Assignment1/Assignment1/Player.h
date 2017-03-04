#pragma once
#include "Card.h"
#include "Pawn.h"
#include <string>
#include <iostream>

class Player{

private:
	Role_Card *roleCard;
	Player_Card *playerCard;
	Reference_Card *referenceCard;
	Pawn *pawn;
	Infection_Card *infectionCard;
	int numOfActions = 0;

public:
	Player(Role_Card* roleCard, Player_Card* playerCard, Reference_Card* referenceCard);
	~Player();
	void display();
	void setPlayerInfectionCard(Infection_Card* infectionCard);
	std::string getPlayerInfectionCard();
	void infectCity(Cities* targetCity);

};
