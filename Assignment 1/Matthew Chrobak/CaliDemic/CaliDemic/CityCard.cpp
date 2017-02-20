#include "CityCard.h"
#include "GraphicsManager.h"
#include "Game.h"
#include <iostream>


CityCard::CityCard(const int cityIndex)
{
	this->_cityIndex = cityIndex;
	this->_cardType = PlayerCardType::City_Card;
}


CityCard::~CityCard()
{
}

void CityCard::playCard()
{
	std::cout << "A city card was played for the city " + Game::getGameBoard()->getCity(this->_cityIndex)->name << "." << std::endl;
}

std::string CityCard::getSurfaceName()
{
	return CARDS_PATH + (Game::getGameBoard()->getCity(this->_cityIndex)->name) + ".png";
}