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



//Infect a city with 1 cube
void InfectionCard::infectCityCube(int cityIndex)
{
	Board* board = Game::getGameBoard();
	City* city = board->getCity(cityIndex);
	int color = city->color;

	// Is there less than three cubes for the color?
	if (city->cube[color] < 3) {
		city->infectCity(cityIndex, color);
		Game::numOfCubeDecrementor(color);
	}
	else {
		city->infectCityOutBreak(cityIndex);
	}
}

//Infect a city with three cubes
void InfectionCard::infectCityCubeThree(int cityIndex)
{
	Board* board = Game::getGameBoard();
	City* city = board->getCity(cityIndex);
	int color = city->color;

	city->infectCityThree(cityIndex, color);
	Game::numOfCubeDecrementor(color);
	
}

//Infect a city with two cubes
void InfectionCard::infectCityCubeTwo(int cityIndex)
{
	Board* board = Game::getGameBoard();
	City* city = board->getCity(cityIndex);
	int color = city->color;

	city->infectCityTwo(cityIndex, color);
	Game::numOfCubeDecrementor(color);
}



void InfectionCard::infectLastCity(int lastCity)
{
	Board* board = Game::getGameBoard();
	City* city = board->getCity(lastCity);
	int color = city->color;

	city->infectCity(lastCity, color);
	Game::numOfCubeDecrementor(color);

}