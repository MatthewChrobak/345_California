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
	auto board = Game::getInstance().getBoard();
	City* city = board.getCity(cityIndex);
	int color = city->color;

	if (city->cube[color] < 3)
	{
		InfectionCard::infectCity(cityIndex, color);
	}
	else
	{
		InfectionCard::infectCityOutBreak(cityIndex);
	}
}

void InfectionCard::infectLastCity(int lastCity)
{
	auto game = Game::getInstance();
	auto board = game.getBoard();
	City* city = board.getCity(lastCity);
	int color = city->color;

	//Infect that city with 3 cubes
	for (int i = 0; i < 3; i++)
	{
		board.getCity(lastCity)->cube[color]++;
	}
	
	// TODO: MVC DOES NOT ALLOW THIS:  GuiManager::showMsgBox("The city: " + board.getCity(lastCity)->name + " is infected");
	game.numOfCubeDecrementor(color);

}

/*
normal infection without outbreak
*/
void InfectionCard::infectCity(int city, int index)
{
	auto game = Game::getInstance();
	auto board = game.getBoard();
	board.getCity(city)->cube[index]++;
	game.numOfCubeDecrementor(index);
	// TODO: MVC DOES NOT ALLOW THIS:  GuiManager::showMsgBox("The city: " + board.getCity(city)->name + " is infected.");
}

/*
infection with outbreak of the current passing city.
*/
void InfectionCard::infectCityOutBreak(int city)
{
	auto game = Game::getInstance();
	auto board = game.getBoard();
	// TODO: MVC DOES NOT ALLOW THIS:  GuiManager::showMsgBox("The city: " + board.getCity(city)->name + " is infected.");
	// TODO: MVC DOES NOT ALLOW THIS:  GuiManager::showMsgBox("OH NO! AN OUTBREAK OCCURRED!!!");
	City::outbreakCount += 1;

	if (City::outbreakCount >= 8) {
		// TODO: MVC DOES NOT ALLOW THIS:  GuiManager::showMsgBox("Game Over");
		// TODO: MVC DOES NOT ALLOW THIS:  GuiManager::handleWindowClose();
		return;
	}
	/*
	an iterator that will go through all the nodes connect to the city that is
	being outbreak and if another city's cube size is rearched, than another outbreak event will
	happen. A counter is use to recursively call the infectCityOutbreak if the cube is full.
	*/
	auto iterator = board.getCity(city)->getAdjacentNodes();
	int currentOutbreakCityColor = board.getCity(city)->color;
	for (unsigned int i = 0; i < iterator.size(); i++)
	{
		if (board.getCity(iterator.at(i))->cube[currentOutbreakCityColor] < 3)
		{
			board.getCity(iterator.at(i))->cube[currentOutbreakCityColor]++;
			//decrement the num of cube
			game.numOfCubeDecrementor(currentOutbreakCityColor);
		}
		/*
		Another outbreak could occur if the capacity of the cube color exceed three
		*/
		else
			infectCityOutBreak(iterator.at(i));
	}
}


