#include "CityCard.h"

#include "Game.h"
#include <iostream>


CityCard::CityCard(const int cityIndex)
{
	this->cityIndex = cityIndex;
	this->_cardType = PlayerCardType::City_Card;
}


CityCard::~CityCard()
{
}

void CityCard::playCard()
{
	
}

std::string CityCard::getSurfaceName()
{
	return "";
}