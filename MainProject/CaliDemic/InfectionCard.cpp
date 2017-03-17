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
	//The city color that is going to be infected.
	int cityColor = Game::getGameBoard()->getCity(city)->color;

	//checking if the city's cube array is full (aka. Infected)

	//checking the current index if it is not infected by any colors diseases
	if (Game::getGameBoard()->getCity(city)->cube[cityColor] < 3)
	{
		//this will remove the card from the infectionDeck
		Game::getGameBoard()->discardInfectionCard.push_back(city);
		Game::getGameBoard()->infectionCityCards.erase(Game::getGameBoard()->infectionCityCards.begin() + city);
		//infect the city normally
		Game::getGameBoard()->getCity(city)->infectCity(city, cityColor);
		//resize the infection Card deck and Discard pile
		Game::getGameBoard()->infectionCityCards.shrink_to_fit();
		Game::getGameBoard()->discardInfectionCard.shrink_to_fit();

		//decrement the cube's color
		Game::numOfCubeDecrementor(cityColor);
		
	}
	else if (Game::getGameBoard()->getCity(city)->cube[cityColor] == 3)
	{
		/*
		if the counter is 3 that means that the city's cube color counter is full.
		Thus, we will call the infect outbreak functions to infect close city
		from the current infected city.
		*/
		Game::getGameBoard()->getCity(city)->infectCityOutBreak(city);
	}
	

}