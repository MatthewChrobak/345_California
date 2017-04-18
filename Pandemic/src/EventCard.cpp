#include "EventCard.h"
#include "GraphicsManager.h"
#include <iostream>
#include "Board.h"
#include "GuiManager.h"
#include "PlayerActions.h"
#include "City.h"
#include "Player.h"


EventCard::~EventCard()
{

}

EventCard::EventCard(EventCardType type)
{
	this->_eventType = type;
	this->_cardType = PlayerCardType::Event_Card;
}

EventCardType EventCard::getEventType() {

	return this->_eventType;
}

std::string EventCard::getEventName()
{
	switch (this->_eventType) {
	
	
	case EventCardType::Airlift:
		return "Airlift";
		break;
	
	
	case EventCardType::Forecast:
		return "Forecast";
		break;


	case EventCardType::GovernmentGrant:
		return "Government Grant";
		break;


	case EventCardType::OneQuietNight:
		return "One Quiet Night";
		break;
	
	case EventCardType::ResilientPopulation:
		return "Resilient Population";
		break;
	}
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

void EventCard::playCard()
{
	std::cout << "An event card was played." << std::endl;
}

//Take the event card and check what type of event it is; proceed with the appropriate action

