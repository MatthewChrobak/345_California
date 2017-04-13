#include "EpidemicCard.h"
#include "GraphicsManager.h"
#include <iostream>

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