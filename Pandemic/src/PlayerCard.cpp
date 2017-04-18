#include "PlayerCard.h"
#include "Game.h"
#include "Board.h"
#include "City.h"
#include <stdlib.h>    
#include <time.h>
#include <stdio.h> 
#include "FileStream.h"
#include "FileSystem.h"

void PlayerCard::playCard()
{

}

std::string PlayerCard::getSurfaceName()
{
	return "";
}

EventCardType PlayerCard::getEventType()
{
	return EventCardType::Airlift;
}

PlayerCardType PlayerCard::getType()
{
	return this->_cardType;
};

void PlayerCard::eventAction(PlayerCard* card) {

}



//Default constructor
PlayerCard::PlayerCard() {};

PlayerCard::~PlayerCard()
{
};


