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

/*
normal infection without outbreak
*/
void City::infectCity(int city, int index)
{
	Game::getGameBoard()->getCity(city)->cube[index]++;
	GuiManager::showMsgBox("The city: " + Game::getGameBoard()->getCity(city)->name + " is infected" );
}

//normal infection (3 cubes) without outbreak
void City::infectCityThree(int city, int index)
{
	for (int i = 0; i < 3; i++)
	{
		Game::getGameBoard()->getCity(city)->cube[index]++;
	}
	GuiManager::showMsgBox("The city: " + Game::getGameBoard()->getCity(city)->name + " is infected");
}

/*
infection with outbreak of the current passing city.
*/
void City::infectCityOutBreak(int city)
{
	GuiManager::showMsgBox("OH NO! AN OUTBREAK OCCURRED!!!");
	City::outbreakCount += 1;

	if (City::outbreakCount >= 8) {
		GuiManager::showMsgBox("Game Over");
		GuiManager::handleWindowClose();
		return;
	}
	/*
	an iterator that will go through all the nodes connect to the city that is
	being outbreak and if another city's cube size is rearched, than another outbreak event will 
	happen. A counter is use to recursively call the infectCityOutbreak if the cube is full.
	*/
	auto iterator = Game::getGameBoard()->getCity(city)->getAdjacentNodes();
	int currentOutbreakCityColor = Game::getGameBoard()->getCity(city)->color;
	for (unsigned int i = 0; i < iterator.size(); i++)
	{
		if (Game::getGameBoard()->getCity(iterator.at(i))->cube[currentOutbreakCityColor] < 3)
		{
			Game::getGameBoard()->getCity(iterator.at(i))->cube[currentOutbreakCityColor]++;
			//decrement the num of cube
			Game::numOfCubeDecrementor(currentOutbreakCityColor);
			break;
		}
		/*
		Another outbreak could occur if the capacity of the cube color exceed three
		*/
		else
			infectCityOutBreak(iterator.at(i));
	}
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