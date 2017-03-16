#include "InfectionCard.h"
#include "City.h"
#include "InfectionColors.h"
#include "Game.h"
#include "Board.h"
#include <iostream>



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
	//The city color that is going to be infected.
	int cityColor = Game::getGameBoard()->getCity(city)->color;

	//checking if the city's cube array is full (aka. Infected)
	for (int i = 0; i < City::cubeMaxSize; i++, counter++)
	{
		//checking the current index if it is not infected by any colors diseases
		if (Game::getGameBoard()->getCity(city)->cube[i] == -1)
		{
			//this will remove the card from the infectionDeck
			Game::getGameBoard()->infectionCityCards.erase(Game::getGameBoard()->infectionCityCards.begin() + i);
			//infect the city if it is at the index i
			Game::getGameBoard()->getCity(city)->infectCity(city, i);
			Game::getGameBoard()->infectionCityCards.shrink_to_fit();

			//decrement the cube's color
			Game::numOfCubeDecrementor(cityColor);
			break;
		}
	}
	/*
	if the counter is 3 that means that the city's cube array is full.
	Thus, we will call the infect outbreak functions to infect close city
	from the current infected city.
	*/
	if (counter > 3)
	{
		Game::getGameBoard()->getCity(city)->infectCityOutBreak(city);
	}

}