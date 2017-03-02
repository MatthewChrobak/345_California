#pragma once
#include "Card.cpp"
#include "Pawn.cpp"
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
	Player();
	void display();

};

int main(){
	Player *player1 = new Player();
	Player *player2 = new Player();


}