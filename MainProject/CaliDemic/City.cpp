#include "City.h"
#include "Game.h"
#include "InfectionColors.h"
#include <iostream>
#include <string>

City::City()
{
}


City::~City()
{
}

/*
normal infection without outbreak
*/
void City::infectCity()
{
	if (this->infected)
		return;
	else
	{
		this->infected = true;
		for (int i = 0; i < cubeMaxSize; i++)
		{
			if (cube[i] != -1)
			{
				this->cube[i] = this->color;
				break;
			}
		}
		this->infected = false;
	}
}
/*
infection with outbreak
*/
void City::infectCityOutBreak()
{

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