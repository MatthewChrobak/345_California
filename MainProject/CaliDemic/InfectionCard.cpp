#include "InfectionCard.h"
#include "City.h"
#include "InfectionColors.h"
#include "Game.h"


InfectionCard::InfectionCard()
{
}


InfectionCard::~InfectionCard()
{
}

void InfectionCard::infectCityCube(int city)
{
	Game::getGameBoard()->getCity(city)->infectCity();
}