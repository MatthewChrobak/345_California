#pragma once
#include "PlayerCard.h"

#include "PlayerAction.h"
#include "Player.h"
#include "Frames.h"
#include "CityCard.h"
#include "Game.h"
#include "GuiManager.h"

void DirectFlightAction1::doAction(Player *player) {

    ///TODO GET CARD CLICKED DATA FROM THE GUI!

    int cardIndex = player->getCardsSelected()[0];

    PlayerCard* card = player->getCard(cardIndex);

    // Make sure the card is not null.
    if (card != nullptr) {


        CityCard *cityCard = (CityCard *) card;
        int cityIndex = cityCard->cityIndex;
        //move to the city
        player->pawn->cityIndex = cityIndex;
        Game::decrementActionCounter();
        Board::checkTurn();
        // Reset the player action.
        player->removeCard(cardIndex);

    }

    else
    {
        GuiManager::showMsgBox("Card was null.");
    }

}

const string &DirectFlightAction1::getName() const {






    return name;
}

void BuildResearchStation1::doAction(Player *player) {


    std :: cout <<"Build RC" << std::endl;



}

const string &BuildResearchStation1::getName() const {
    return name;
}

void TreatDisease1::doAction(Player *player) {


    std :: cout <<"Treated Disease" << std::endl;


}

const string &TreatDisease1::getName() const {
    return name;
}

void ShareKnowledge1::doAction(Player *player) {

    std :: cout <<"Shared Knowledge" << std::endl;


}

const string &ShareKnowledge1::getName() const {
    return name;
}

void DiscoverCure1::doAction(Player *player) {

    cout << "Needs 5 mathcing cards" << endl;

}

const string &DiscoverCure1::getName() const {
    return name;
}

const string &Drive1::getName() const {
    return name;
}

void Drive1::doAction(Player *player) {

    std :: cout <<"Drove" << std::endl;


}

const string &CharterFlight1::getName() const {
    return name;
}

void CharterFlight1::doAction(Player *player) {

    std :: cout <<"Charter flight" << std::endl;


}

const string &ShuttleFlight1::getName() const {
    return name;
}

void ShuttleFlight1::doAction(Player *player) {

    std :: cout <<"Shuttle FLight" << std::endl;


}
