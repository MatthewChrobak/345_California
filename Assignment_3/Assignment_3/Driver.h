#pragma once
#include "GameResources.h"
#include  "InfectionCard.h"
#include "Player.h"
#include "City.h"

int main()
{
	GameResources *game = new GameResources();
	City *city1 = new City();
	Player *player1 = new Player();
	InfectionCard *card = new InfectionCard();

	

	delete game;
	delete city1;
	delete player1;
	delete card;
}
