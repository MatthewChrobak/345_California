#include "EventCard.h"
#include "GraphicsManager.h"
#include <iostream>

EventCard::EventCard(EventCardType type)
{
	this->_eventType = type;
	this->_cardType = PlayerCardType::Event_Card;
}


EventCard::~EventCard()
{
}

void EventCard::playCard()
{
	std::cout << "An event card was played." << std::endl;
}

std::string EventCard::getSurfaceName()
{
	std::string file;

	switch (this->_eventType) {
		case EventCardType::Airlift:
			file = "airlift";
			break;
		case EventCardType::Forecast:
			file = "forecast";
			break;
		case EventCardType::GovernmentGrant:
			file = "governmentgrant";
			break;
		case EventCardType::OneQuietNight:
			file = "onequietnight";
			break;
		case EventCardType::ResilientPopulation:
			file = "resilientpopulation";
			break;
	}

	return CARDS_PATH + file + ".png";
}