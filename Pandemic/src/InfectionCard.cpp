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
/*
normal infection without outbreak
*/
void InfectionCard::infectCity(int city, int index)
{
	Game::getGameBoard()->getCity(city)->cube[index]++;
	Game::numOfCubeDecrementor(index);
	GuiManager::showMsgBox("The city: " + Game::getGameBoard()->getCity(city)->name + " is infected.");
}
/*
infection with outbreak of the current passing city.
*/
void InfectionCard::infectCityOutBreak(int city)
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
