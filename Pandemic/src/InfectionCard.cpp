#include "InfectionCard.h"
#include "City.h"
#include "InfectionColors.h"
#include "Game.h"
#include "Board.h"
#include <iostream>



InfectionCard::InfectionCard()
{
}


InfectionCard::~InfectionCard()
{
}

void InfectionCard::infectCityCube(int cityIndex)
{
    Board* board = Game::getGameBoard();
    City* city = board->getCity(cityIndex);
    int color = city->color;

    // Is there less than three cubes for the color?
    if (city->cube[color] < 3) {
        city->infectCity(cityIndex, color);
        Game::numOfCubeDecrementor(color);
    }
    else {
        city->infectCityOutBreak(cityIndex);
    }
}