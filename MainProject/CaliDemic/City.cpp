#include "City.h"
#include "Game.h"
#include "InfectionColors.h"
#include "InfectionCard.h"
#include <iostream>
#include <string>

#ifdef DEBUG
#include <assert.h>
#endif


City::City()
{
	for (int i = 0; i < cubeMaxSize; i++)
	{
		this->cube[i] = -1;
	}
}


City::~City()
{
}

/*
normal infection without outbreak
*/
void City::infectCity(int city, int index)
{
	if (this->infected)
		return;
	else
	{
		this->infected = true;
		Game::getGameBoard()->getCity(city)->cube[index] = Game::getGameBoard()->getCity(city)->color;
		this->infected = false;
	}
}
/*
infection with outbreak of the current passing city.
*/
void City::infectCityOutBreak(int city)
{
	/*
	an iterator that will go through all the nodes connect to the city that is
	being outbreak and if another city's cube size is rearched, than another outbreak event will 
	happen. A counter is use to recursively call the infectCityOutbreak if the cube is full.
	*/
	auto iterator = Game::getGameBoard()->getCity(city)->getAdjacentNodes();
	for (unsigned int i = 0; i < iterator.size(); i++)
	{
		//reset the counter to 0 when it break out of the cube index loop.
		int counter = 0;
		for (unsigned int j = 0; i < cubeMaxSize; j++, counter++)
		{
			if (Game::getGameBoard()->getCity(iterator.at(i))->cube[j] == -1)
			{
				Game::getGameBoard()->getCity(iterator.at(i))->cube[j] = Game::getGameBoard()->getCity(city)->color;
				//decrement the num of cube
				int cityColor = Game::getGameBoard()->getCity(city)->color;
				Game::numOfCubeDecrementor(cityColor);
				break;
			}
			/*
			if the counter reached the limit then another outbreak will happen
			*/
			if (counter > 3)
			{
				infectCityOutBreak(iterator.at(i));
			}

		}
	}
}

void City::buildResearchFacility()
{
	if (this->research == false)
	{
		this->research = true;
		std::cout << "research facility builded" << std::endl;
	}
	else
	{
		std::cout << "research facility builded already" << std::endl;
		return;
	}
	
}

bool City::isAdjacent(int index)
{
	// Determines if the index is inside the adjacency list.
	for (int i = 0; i < this->_adjacentNodeIds.size(); i++) {
		if (this->_adjacentNodeIds.at(i) == index) {
			return true;
		}
	}
	return false;
}

City* City::getCityFromXY(int x, int y)
{
	// Get the city index.
	int index = City::getCityIndexFromXY(x, y);

#ifdef DEBUG
	// If we're in debug mode, and we're not within the bounds, throw an exception.
	assert(index != -1 && index < Game::getGameBoard()->getNumCities());
#endif
	
	// Make sure we're within valid bounds.
	if (index >= 0 && index < Game::getGameBoard()->getNumCities()) {
		return Game::getGameBoard()->getCity(index);
	} else {
		return nullptr;
	}
}

int City::getCityIndexFromXY(int x, int y)
{
	// Get the game board, and the number of cities.
	Board* board = Game::getGameBoard();
#ifdef DEBUG
	assert(board != nullptr);
#endif
	int numCities = board->getNumCities();

	// Figure out what the width and height of the city is.
	int halfWidth = CITY_RENDER_WIDTH / 2;
	int halfHeight = CITY_RENDER_HEIGHT / 2;

	for (int i = 0; i < numCities; i++) {
		City* city = board->getCity(i);

		// The x/y coordinate is their centerpoint.
		int centerX = city->x;
		int centerY = city->y;

		// Are we within the bounds of the current city?
		if (centerX - halfWidth <= x && centerX + halfWidth >= x) {
			if (centerY - halfHeight <= y && centerY + halfHeight >= y) {
				// We are. Return the city.
				return i;
			}
		}
	}

	return -1;
}