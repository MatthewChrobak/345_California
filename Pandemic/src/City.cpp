#include "City.h"
#include "Game.h"
#include "InfectionColors.h"
#include "InfectionCard.h"
#include <iostream>
#include <string>
#include "GuiManager.h"

#ifdef DEBUG
#include <assert.h>
#endif

int City::outbreakCount = 0;

City::City()
{
	for (int i = 0; i < InfectionColor::InfectionColor_Length; i++)
	{
		this->cube[i] = 0;
	}
}


City::~City()
{
}

void City::buildResearchFacility()
{
	if (this->research == false)
		this->research = true;
	else
		return;
}

bool City::isAdjacent(int index)
{
	// Determines if the index is inside the adjacency list.
	for (unsigned int i = 0; i < this->_adjacentNodeIds.size(); i++) {
		if (this->_adjacentNodeIds.at(i) == index) {
			return true;
		}
	}
	return false;
}

City* City::getCityFromXY(int x, int y)
{
	auto board = Game::getInstance().getBoard();

	// Get the city index.
	int index = City::getCityIndexFromXY(x, y);

#ifdef DEBUG
	// If we're in debug mode, and we're not within the bounds, throw an exception.
	assert(index != -1 && index < board.getNumCities());
#endif
	
	// Make sure we're within valid bounds.
	if (index >= 0 && index < board.getNumCities()) {
		return board.getCity(index);
	} else {
		return nullptr;
	}
}

int City::getCityIndexFromXY(int x, int y)
{
	// Get the game board, and the number of cities.
	auto board = Game::getInstance().getBoard();
	int numCities = board.getNumCities();

	// Figure out what the width and height of the city is.
	int halfWidth = CITY_RENDER_WIDTH / 2;
	int halfHeight = CITY_RENDER_HEIGHT / 2;

	for (int i = 0; i < numCities; i++) {
		City* city = board.getCity(i);

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