#include "EpidemicCard.h"
#include "Board.h"
#include "InfectionCard.h"
#include <iostream>
#include "Game.h"


EpidemicCard::EpidemicCard()
{
	this->_cardType = PlayerCardType::Epidemic_Card;
}


EpidemicCard::~EpidemicCard()
{
}

void EpidemicCard::playCard()
{
	std::cout << "An epidemic card was played." << std::endl;
}

std::string EpidemicCard::getSurfaceName()
{
	std::string file = "epidemic.png";
	return CARDS_PATH + file;
}

//When an epidemic card is drawn, do the following steps
void EpidemicCard::drawingEpidemicCard()
{
	//Increment the infection rate
	Board::incrementInfectionRate();

	auto board = Game::getInstance().getBoard();

	//Draw the last infection card and place 3 cubes on it
	board.drawLastInfectionCard();

	//Shuffle the discarded pile and place it back in the original deck
	board.shuffleDiscardedInfectionDeck();
}

