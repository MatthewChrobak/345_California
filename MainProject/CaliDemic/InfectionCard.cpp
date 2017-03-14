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
	//local counter to know if it reaches the last index of the city's cube
	int counter = 0;
	//checking if the city's cube array is full (aka. Infected)
	for (int i = 0; i < Game::getGameBoard()->getCity(city)->cubeMaxSize; i++)
	{
		counter++;
		//checking the current index if it is not infected by any colors diseases
		if (Game::getGameBoard()->getCity(city)->cube[i] != InfectionColor::Black ||
			Game::getGameBoard()->getCity(city)->cube[i] != InfectionColor::Red ||
			Game::getGameBoard()->getCity(city)->cube[i] != InfectionColor::Blue ||
			Game::getGameBoard()->getCity(city)->cube[i] != InfectionColor::Yellow)
		{
			//infect the city if at the index i
			Game::getGameBoard()->getCity(city)->infectCity();
			break;
		}
	}
	/*
	if the counter is 3 that means that the city's cube array is full.
	Thus, we will call the infect outbreak functions to infect close city
	from the current infected city.
	*/
	if (counter == 3)
	{
		Game::getGameBoard()->getCity(city)->infectCityOutBreak(city);
	}

}