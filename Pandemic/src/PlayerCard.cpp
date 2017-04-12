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


