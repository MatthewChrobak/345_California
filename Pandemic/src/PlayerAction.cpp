#pragma once
#include "PlayerCard.h"

#include "PlayerAction.h"
#include "Player.h"
#include "Frames.h"
#include "CityCard.h"
#include "Game.h"
#include "GuiManager.h"

void DirectFlightAction::doAction(Player *player) {

    ///TODO GET CARD CLICKED DATA FROM THE GUI!
/*
   // We should only have one card selected here.
    if (this->_cardData->size() == 1) {

        // Get the card index.
        int cardIndex = this->_cardData->at(0);
        PlayerCard* card = player.getCard(cardIndex);


        // Make sure the card is not null.
        if (card != nullptr) {

            // Make sure it's a city card.
            if (card->getType() == PlayerCardType::City_Card) {
                CityCard* cityCard = (CityCard*)card;
                int cityIndex = cityCard->cityIndex;

                // Remove it, move the player, and hide the player cards.
                player->removeCard(cardIndex);
                player->pawn->cityIndex = cityIndex;
                board.decrementActionCounter();
                Board::checkTurn();
                GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = false;
                // Reset the player action.
                GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
            }
            else {
                GuiManager::showMsgBox("Please select a city card.");
            }
        }
        else {
            GuiManager::showMsgBox("Card was null.");
        }
    }
    else {
        GuiManager::showMsgBox("Please select only one card.");
    }
*/

}

const string &DirectFlightAction::getName() const {






    return name;
}

void BuildResearchStation::doAction(Player *player) {


    std :: cout <<"Build RC" << std::endl;



}

const string &BuildResearchStation::getName() const {
    return name;
}

void TreatDisease::doAction(Player *player) {


    std :: cout <<"Treated Disease" << std::endl;


}

const string &TreatDisease::getName() const {
    return name;
}

void ShareKnowledge::doAction(Player *player) {

    std :: cout <<"Shared Knowledge" << std::endl;


}

const string &ShareKnowledge::getName() const {
    return name;
}

void DiscoverCure::doAction(Player *player) {

    cout << "Needs 5 mathcing cards" << endl;

}

const string &DiscoverCure::getName() const {
    return name;
}

const string &Drive::getName() const {
    return name;
}

void Drive::doAction(Player *player) {

    std :: cout <<"Drove" << std::endl;


}

const string &CharterFlight::getName() const {
    return name;
}

void CharterFlight::doAction(Player *player) {

    std :: cout <<"Charter flight" << std::endl;


}

const string &ShuttleFlight::getName() const {
    return name;
}

void ShuttleFlight::doAction(Player *player) {

    std :: cout <<"Shuttle FLight" << std::endl;


}
