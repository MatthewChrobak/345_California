#include "Board.h"
#include "FileStream.h"
#include "FileSystem.h"
#include "PlayerActions.h"

#include "InfectionCard.h"
#include "GuiManager.h"
#include "Game.h"
#include <iostream>
#include <vector>
#include <string>
#include "CityCard.h"
#include "RandomNumberGenerator.h"
#include "RoleCard.h"
#include "EventCard.h"
#include "Frames.h"
#include "EpidemicCard.h"
#include "RandomNumberGenerator.h"

#ifdef DEBUG
#include <assert.h>
#endif

int Board::_infectionRate = INFECTION_RATE;

void Board::generateGameContentAtStartOfGame()
{
	this->generatePlayerCards();

	// Give each player four cards, while we have cards.
	for (int playerIndex = 0; playerIndex < this->getNumberOfPlayers(); playerIndex++) {
		for (int i = 0; i < 4; i++) {
			if (this->playerWithdrawPile.size() == 0) {
				break;
			}
			else {
				this->getPlayer(playerIndex).addCard(this->playerWithdrawPile.at(this->playerWithdrawPile.size() - 1));
				this->playerWithdrawPile.pop_back();
			}
		}
		int i = RandomNumberGenerator::next(0, 6);
		// Give each player a random role card.
		RoleCard *p = new RoleCard(RoleCard::roleCardNames[i]);
		this->getPlayer(playerIndex).setRoleCard(p);
		
	}
	/*
	show the role for every players
	*/
	for (int i = 0; i < getNumberOfPlayers(); i++)
	{
		string role = this->getPlayer(i).getRoleCard()->roleCardNames[this->getPlayer(i).getRoleCard()->getRoleCardVal()];
		GuiManager::showMsgBox("Player " + std::to_string(i) + " role is: " + role);
	}

	

	//===========================================================
	//Adding epidemic cards to the player deck
	for (int i = 0; i < NUMBER_OF_EPIDEMIC; i++) {
		int rng = RandomNumberGenerator::next(0, playerWithdrawPile.size());
		EpidemicCard* epidemicCard = new EpidemicCard();
		this->playerWithdrawPile.insert(this->playerWithdrawPile.begin() + rng, epidemicCard);
	}

	//===========================================================
	//intializing infectionCardDeck
	Board::infectionCityCardsInitializor();

	//starting the infection with 9 cities (required 9 cities if not null exception)
	//(TEMPORARY IMPLEMENTATION): First three cities have three cubes, next three have
	//two cubes and last three have 1 cube.


	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			InfectionCard::infectCityCube(infectionCityCards.at(0));
		}
		Board::discardInfectionCard.push_back(infectionCityCards.at(0));
		Board::infectionCityCards.erase(infectionCityCards.begin());
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			InfectionCard::infectCityCube(infectionCityCards.at(0));
		}
		Board::discardInfectionCard.push_back(infectionCityCards.at(0));
		Board::infectionCityCards.erase(infectionCityCards.begin());
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			InfectionCard::infectCityCube(infectionCityCards.at(0));
		}
		Board::discardInfectionCard.push_back(infectionCityCards.at(0));
		Board::infectionCityCards.erase(infectionCityCards.begin());
	}
	
	
}

/*
This will initialize the infectionCard deck
*/
void Board::infectionCityCardsInitializor()
{
	infectionCityCards.push_back(0);
	int rng;
	//Changed to 0
	for (int i = 1; i < this->getNumCities(); i++)
	{
		rng = RandomNumberGenerator::next(0, infectionCityCards.size());
		infectionCityCards.insert(infectionCityCards.begin() + rng, i);
	}
	infectionCityCards.shrink_to_fit();
}

Board::Board()
{
	this->_cities = new CityGraph();
}

void Board::addPlayer(Player* player)
{
	this->_players.push_back(player);
}

Board::~Board()
{
	for (unsigned int i = 0; i < this->_players.size();i++)
		delete this->_players.at(i);

	while (!this->playerWithdrawPile.empty()) {
		delete this->playerWithdrawPile.at(this->playerWithdrawPile.size()-1);
		this->playerWithdrawPile.pop_back();
	}

	delete this->_cities;
}


//Draw 2 cards
void Board::drawCards()
{
	if (this->playerWithdrawPile.size() <= 0)
	{
		GuiManager::showMsgBox("no more player's card, you lost!");
		GuiManager::handleWindowClose();
	}
	for (int i = 0; i < 2; i++)
	{
		if (this->playerWithdrawPile.size() != 0) {

			//If the card drawn is an epidemic card, play it and remove it from the player's hand
			if (this->playerWithdrawPile.back()->getType() == Epidemic_Card)
			{
				EpidemicCard::drawingEpidemicCard();
				this->playerWithdrawPile.pop_back();
			}

			else {

				this->getCurrentTurnPlayer().addCard(this->playerWithdrawPile.at(this->playerWithdrawPile.size() - 1));
				this->playerWithdrawPile.pop_back();
				this->playerWithdrawPile.shrink_to_fit();
			}

		}
	}
}

//Generates the playerCards deck
void Board::generatePlayerCards()
{
	// Create a vector of city indexes.
	std::vector<int> cityIds;
	for (int i = 0; i < this->getNumCities(); i++) {
		cityIds.push_back(i);
	}

	while (cityIds.size() != 0) {
		int rng = RandomNumberGenerator::next(0, cityIds.size());

		//Add the city to the withdraw pile.
		CityCard* card = new CityCard(cityIds.at(rng));
		this->playerWithdrawPile.push_back(card);

		//Remove the id from the vector.
		cityIds.erase(cityIds.begin() + rng);
	}

	//Temporarily hard-coding event cards and add them in the deck
	EventCard* card1 = new EventCard(Airlift);
	EventCard* card2 = new EventCard(OneQuietNight);
	EventCard* card3 = new EventCard(ResilientPopulation);
	EventCard* card4 = new EventCard(GovernmentGrant);
	EventCard* card5 = new EventCard(Forecast);

	std::vector<EventCard*> tempEventVector {card1, card2, card3, card4, card5};

	for (unsigned int i = 0; i < tempEventVector.size(); i++) {

		int rng = RandomNumberGenerator::next(0, playerWithdrawPile.size());
		this->playerWithdrawPile.insert(this->playerWithdrawPile.begin() + rng, tempEventVector[i]);
	}

}


City* Board::getCity(int index)
{
	if (index < 0 || index >= this->getNumCities()) {
		return nullptr;
	}
	return (City*)(this->_cities->getNode(index));
}

void Board::addCity(City* city)
{
	this->_cities->addNode(city);
}

int Board::getNumCities()
{
	return this->_cities->getNumNodes();
}

Player& Board::getCurrentTurnPlayer()
{
#ifdef DEBUG
	assert(this->_players.size() > 0);
#endif
	return *this->_players[Board::currentTurnPlayer];
}

Player& Board::getPlayer(int index)
{
#ifdef DEBUG
	assert(index >= 0 && index < (int)this->_players.size());
#endif
	return *this->_players[index];
}

int Board::getNumberOfPlayers()
{
	return this->_players.size();
}

/*
this will check the number of action and change turn if it reaches 
4 actions
*/
bool Board::playerTurnChange()
{
	bool turnChanged = false;
	if (Game::actionCounter == 0)
	{
		this->currentTurnPlayer = ((this->currentTurnPlayer) + 1) % _players.size();
		Game::resetActionCounter();
		turnChanged = true;
	}

	return turnChanged;
}

int Board::getInfectionRate()
{
	if (this->_infectionRate <= 2) {
		return 2;
	}

	if (this->_infectionRate <= 4) {
		return 3;
	}

	return 4;
}

void Board::incrementInfectionRate()
{
	_infectionRate += 1;
}

//draw infections card at the end of the turn
void Board::drawInfectionCard()
{
	for (int i = 0; i < this->getInfectionRate(); i++)
	{
		if (infectionCityCards.size()<=2)
		{
			GuiManager::showMsgBox("Less than 2 infection cards in the infection deck, you lost!");
			GuiManager::handleWindowClose();
		}
		else if (infectionCityCards.size() != 0)
		{
			// Pick up the card only if it's not cured.
			if (isCured[Game::getGameBoard()->getCity(infectionCityCards.at(0))->color] != true)
			{
				InfectionCard::infectCityCube(infectionCityCards.at(0));
			}
	
			// Remove it from the pile.
			Board::discardInfectionCard.push_back(infectionCityCards.at(0));
			Board::infectionCityCards.erase(infectionCityCards.begin());
			Board::infectionCityCards.shrink_to_fit();
		}
	}
}

//Function to draw the last infection card (to be used with epidemic card)
void Board::drawLastInfectionCard()
{
	if (infectionCityCards.size() != 0)
	{
		InfectionCard::infectLastCity(infectionCityCards.size()-1);
	}
	Board::discardInfectionCard.push_back(infectionCityCards.back());
	Board::infectionCityCards.erase(infectionCityCards.begin() + infectionCityCards.size()-1);
	Board::infectionCityCards.shrink_to_fit();
}

//Function to shuffle the discarded infection cards (to be used when epidemic card is drawn)
void Board::shuffleDiscardedInfectionDeck() 
{
	//At every loop, take a random card in the discarded pile and insert it at the beginning of the original deck
	for (int i = 0; i < this->discardInfectionCard.size(); i++)
	{
		int rng = RandomNumberGenerator::next(0, this->discardInfectionCard.size());
		infectionCityCards.insert(this->infectionCityCards.begin(), this->discardInfectionCard[rng]);
	}

	std::string g = std::to_string(infectionCityCards.size());
	GuiManager::showMsgBox("SIZE OF INFECTIONCITYCARDS AFTER EPIDEMIC" + g);

	//Clear the discarded infection cards deck after all cards have been placed back in the original deck.
	this->discardInfectionCard.clear();
	std::string h = std::to_string(discardInfectionCard.size());
	GuiManager::showMsgBox("SIZE OF DISCARDCARDS AFTER EPIDEMIC" + h);
}


void Board::checkTurn()
{
	Board* board = Game::getGameBoard();
	Player& player = board->getCurrentTurnPlayer();

	if (board->playerTurnChange() == true)
	{
		string name = player.getRoleCard()->roleCardNames[player.getRoleCard()->getRoleCardVal()];
		GuiManager::showMsgBox("My role is: " + name);
		board->drawCards();
		GuiManager::showMsgBox("Your current hand after picking two cards.");
		GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = true;

		int numberOfCards = player.getNumberOfCards();

		if (numberOfCards > 7) //You only excess cards if you have more than 7 cards after drawing
		{
			GuiManager::showMsgBox("Please discard " + std::to_string((numberOfCards + 2) % 7) + " cards.");
			GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = true;// show message that we have to discard.
			GameFrame::PlayerAction = PlayerActions::DiscardCards;

		}
		//draw infection card and the game will do the infection automatically
		Game::getGameBoard()->drawInfectionCard();
		GuiManager::showMsgBox("End of your turn.");
	}
}

int Board::getActualInfectionRate()
{
	return this->_infectionRate;
}

void Board::setActualInfectionRate(int value)
{
	this->_infectionRate = value;

}