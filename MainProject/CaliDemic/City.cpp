#include "City.h"
#include "Game.h"
#include "InfectionColors.h"
#include "InfectionCard.h"
#include <iostream>
#include <string>


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

void City::consoleAddNodeAtCoordDialogue(int x, int y)
{
	City* city = new City();
	std::cout << "Please enter a name: " << std::endl;
	std::getline(std::cin, city->name);

	while (city->name == "") {
		std::getline(std::cin, city->name);
	}

	city->x = x;
	city->y = y;

	std::cout << "Black: " << InfectionColor::Black << std::endl;
	std::cout << "Blue: " << InfectionColor::Blue << std::endl;
	std::cout << "Yellow: " << InfectionColor::Yellow << std::endl;
	std::cout << "Red: " << InfectionColor::Red << std::endl;

	std::string input;
	std::getline(std::cin, input);
	city->color = (InfectionColor)std::atoi(input.c_str());

	Game::getGameBoard()->addCity(city);
}