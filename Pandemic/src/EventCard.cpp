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

EventCardType EventCard::getEventType() {
	return this->_eventType;
}


EventCard::EventCard(EventCardType type)
{
	this->_eventType = type;
	this->_cardType = PlayerCardType::Event_Card;
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

void EventCard::eventAction(PlayerCard* card)
{
	Board* board = Game::getGameBoard();

	switch (card->getEventType())
	{

		//Examine the top 6 cards of the infection draw pile, rearrange them to your liking and put them back
	case EventCardType::Forecast:
	{
		return;
		//Temporary array to hold the 6 cards
		std::vector <int> temporary;

		//Push the first 6 cards of the infection deck into the temporary deck
		for (int i = 0; i < 6; i++)
		{
			temporary.push_back(board->drawTopInfectionCard());
		}

		//Display the first 6 infection cards

		//From an input from the user, add the cards back into the infection deck accordingly
		for (int i = 0; i < 6; i++)
		{
			int input = 0;
			if (temporary[input] >= 0)
			{
				board->infectionCityCards.insert(board->infectionCityCards.begin(), temporary[input]);
				temporary[input] = -1;
			}
		}
		break;
	}

	//The next player to begin the playing the infector phase on their turn may skip the phaes entirely
	case EventCardType::OneQuietNight:
	{
		//The Attributed boolean becomes true, preventing cards from being drawn that night
		board->oneQuietNight = true;
		break;
	}
	case EventCardType::Airlift:
	{
		/*
		* Ask user which city will have a new research center
		*/

		std::string cityName = "";
		int cityIndex = -1;

		std::cout << "Please enter a city name that you want to move to: ";

		try {
			std::getline(std::cin, cityName);

			for (int i = 0; i < board->getNumCities(); i++) {
				if (cityName == board->getCity(i)->name) {
					cityIndex = i;
					throw 0;
				}
			}

			throw "";
		}
		catch (const char* e)
		{
			std::cout << "Something went wrong. Try again." << std::endl;
			board->getCurrentTurnPlayer().addCard(new EventCard(EventCardType::Airlift));
			return;
		}
		catch (int e)
		{

		}

		board->getCurrentTurnPlayer().pawn->cityIndex = cityIndex;

		break;
	}

	//Move a pawn (yours or another palyer's) to any city.
	case EventCardType::GovernmentGrant:
	{
		/*
		 * Ask user which city will have a new research center		
		 */

		std::string cityName = "";
		int cityIndex = -1;

		std::cout << "Please enter a city name that you want to have a research center: ";

		try {
			std::getline(std::cin, cityName);

			for (int i = 0; i < board->getNumCities(); i++) {
				if (cityName == board->getCity(i)->name) {
					cityIndex = i;
					break;
				}
			}

			throw "";
		}
		catch (const char* e)
		{
			std::cout << "Something went wrong. Try again." << std::endl;
			return;
		}

		//Gets the city
		City* city = board->getCity(cityIndex);

		//Build a research center if the city doesn't already have one
		city->buildResearchFacility();

		break;
	}

	//Take a card from the infection discard pile and remove it from the game
	case EventCardType::ResilientPopulation :
	{
		/*
		 *Display all discarded infection cards
		 */

		int inputDiscard = -1;//User inputs a value of the card he wishes to discard

		for (int i = 0; i < board->discardInfectionCard.size(); i++) {
			std::cout << i << ": " << (board->getCity(board->discardInfectionCard.at(i))->name) << std::endl;
		}

		try {
			std::cout << "Please enter a card index [0-" << (board->discardInfectionCard.size() - 1) << "]:";
			std::cin >> inputDiscard;

			if (inputDiscard < 0 || inputDiscard >= board->discardInfectionCard.size()) {
				throw "";
				inputDiscard = -1;
			}
		}
		catch (const char* e)
		{
			std::cout << "Something went wrong. Try again." << std::endl;
			return;
		}

		//Permanently discard the card
		board->discardInfectionCard.erase(board->discardInfectionCard.begin() + inputDiscard);
		board->discardInfectionCard.shrink_to_fit();
		break;
	}

	}
}

