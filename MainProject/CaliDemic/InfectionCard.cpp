#include "InfectionCard.h"
#include "City.h"
#include "InfectionColors.h"
#include "Game.h"
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
	for (int i = 0; i < Game::getGameBoard()->getCity(city)->cubeMaxSize; i++)
	{
		counter++;
		//checking the current index if it is not infected by any colors diseases
		if (Game::getGameBoard()->getCity(city)->cube[i] != InfectionColor::Black ||
			Game::getGameBoard()->getCity(city)->cube[i] != InfectionColor::Red ||
			Game::getGameBoard()->getCity(city)->cube[i] != InfectionColor::Blue ||
			Game::getGameBoard()->getCity(city)->cube[i] != InfectionColor::Yellow)
		{
			//infect the city if it is at the index i
			Game::getGameBoard()->getCity(city)->infectCity();

			//decrement the cube's color
			switch (cityColor)
			{
				case 0:
					if (cityColor == InfectionColor::Red)
						Game::numOfRedCube--;

					if (Game::numOfRedCube <= 0)
					{
						std::cout << "Game Over! no more red cube." << std::endl;
						exit(0);
					}
					break;

				case 1:
					if (cityColor == InfectionColor::Blue)
						Game::numOfBlueCube--;

					if (Game::numOfBlueCube <= 0)
					{
						std::cout << "Game Over! no more blue cube." << std::endl;
						exit(0);
					}
					break;

				case 2:
					if (cityColor == InfectionColor::Black)
						Game::numOfBlackCube--;

					if (Game::numOfBlackCube <= 0)
					{
						std::cout << "Game Over! no more Black cube." << std::endl;
						exit(0);
					}
					break;

				case 3:
					if (cityColor == InfectionColor::Yellow)
						Game::numOfYellowCube--;

					if (Game::numOfYellowCube <= 0)
					{
						std::cout << "Game Over! no more Yellow cube." << std::endl;
						exit(0);
					}
					break;

					default:
						break;
			}
			break;
		}
	}
	/*
	if the counter is 3 that means that the city's cube array is full.
	Thus, we will call the infect outbreak functions to infect close city
	from the current infected city.
	*/
	if (counter == 3)
	{
		Game::getGameBoard()->getCity(city)->infectCityOutBreak(city);
	}

}