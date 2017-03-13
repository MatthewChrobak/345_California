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
	//checking if the city's cube array is full (aka. Infected)
	for (int i = 0; i < Game::getGameBoard()->getCity(city)->cubeMaxSize;i++)
	{
		if (Game::getGameBoard()->getCity(city)->cube[i] == Game::getGameBoard()->getCity(city)->color)
		{
			Game::getGameBoard()->getCity(city)->infectCity();
		}
	}

	
	
}