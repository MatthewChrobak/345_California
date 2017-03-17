#include "PlayerCard.h"
#include "Game.h"
#include "EventCard.h"
#include "EpidemicCard.h"
#include "Board.h"
#include "InfectionCard.h"
#include "City.h"
#include <stdlib.h>    
#include <time.h>
#include <stdio.h> 
#include "FileStream.h"
#include "FileSystem.h"
#include "ActionCounter.h"


void PlayerCard::playCard()
{
	// Throw an exception because this method is virtual and should be overriden.
	throw;
}

std::string PlayerCard::getSurfaceName()
{
	// Throw an exception because this method is virtual and should be overriden.
	throw;
}

PlayerCardType PlayerCard::getType()
{
	return this->_cardType;
}

//Default constructor
PlayerCard::PlayerCard() {};

PlayerCard::~PlayerCard()
{
}


//Automatically discards en Epidemic card if the player picks one
void PlayerCard::useEpidemic() {
	
	int counter = 0;
	int epidemicInfection = Game::getGameBoard()->infectionCityCards.back();
	//shrinking the infectionCityCards
	Game::getGameBoard()->infectionCityCards.shrink_to_fit();

	static const int cityColor = Game::getGameBoard()->getCity(epidemicInfection)->color;
	//infect the draw city three times
	for (int i = 0; i < 3; i++)
	{
		
		if (Game::getGameBoard()->getCity(epidemicInfection)->cube[i] == -1)
		{
			counter++;
			Game::getGameBoard()->getCity(epidemicInfection)->cube[i] = cityColor;
			Game::numOfCubeDecrementor(cityColor);
		}

	}
	//if the draw city is not been infect three times that mean that there is an outbreak
	if (counter < 3)
	{
		City::infectCityOutBreak(epidemicInfection);
	}


	//Further functions needed to initiate the effects of picking an epidemic card

}

