//
//pixelsOccupied

#include "PlayerRoleCard.h"
#include "GuiManager.h"
#include "CityCard.h"

PlayerRoleCard::PlayerRoleCard(PlayerAction *playerAction) : playerAction(playerAction) {}

PlayerRoleCard::PlayerRoleCard() {}

void PlayerRoleCard::doAction(Player *player) {

    GuiManager::showMsgBox("Inside PlayerRoleCard Class");

}


void Scientist::doAction(Player *player) {

    std :: cout << "needs 4 cards" << std::endl;

    //main thread is here becuase 4 same color cards
    //get the player's current location
    int playerCurrentLocation = player->pawn->cityIndex;
    //Find if the city has a RC
    City* currentCity = Game::getGameBoard()->getCity(playerCurrentLocation);
    //if true discover something cool
    if (currentCity->research){
        //get the color of the cards selected
        City* cityToGetCardColor = Game::getGameBoard()->getCity(player->getCardsSelected()[0]);
        //Get rid of all the cubes with respect to card's color
        currentCity->cube[cityToGetCardColor->color] = -1;
        player->getCardsSelected().clear();
    }
    else
    {
        GuiManager::showMsgBox("There's not RC in your current city!...you're gonna need that ");

    }









}

Scientist::Scientist(PlayerAction *playerAction) : playerAction(playerAction) {}

const std::string &Scientist::getName() const {
    return name;
}



OperationsExpert::OperationsExpert(PlayerAction *playerAction) : playerAction(playerAction) {}


void OperationsExpert::doAction(Player *player) {
    PlayerRoleCard::doAction(player);

    int cardIndex = player->getCardsSelected()[0];
    PlayerCard* card = player->getCard(cardIndex);
    CityCard *cityCard = (CityCard *) card;
    int cityIndex = cityCard->cityIndex;
    //if there's a a RC in the current City

    //check if there's a RC is already in there
    if (!Game::getGameBoard()->getCity(player->pawn->cityIndex)->research) {

        if (player->pawn->cityIndex == cityIndex) {
            Game::getGameBoard()->getCity(player->pawn->cityIndex)->research = true;
            GuiManager::showMsgBox("You're operations expert! This is worth one action, and the card is not played!");
            Game::decrementActionCounter();
            Game::numOfResearchCenter--;
            Game::decrementActionCounter();
            Board::checkTurn();


            player->getCardsSelected().clear();

        } else {
            GuiManager::showMsgBox("You need a matching card");
            player->getCardsSelected().clear();

        }
    }

    //set the list of Action
else {

    GuiManager::showMsgBox("The research facility is already built in this city.");
}




}

const std::string &OperationsExpert::getName() const {
    return "OperationsExpert";
}


Medic::Medic(PlayerAction *playerAction) : PlayerRoleCard(playerAction) {

}

void Medic::doAction(Player *player) {
    PlayerRoleCard::doAction(player);
    //get the current city
    City* city = Game::getGameBoard()->getCity(player->pawn->cityIndex);

    GuiManager::showMsgBox("You're a medic!...Removing all matching cubes! Counts as one action.");

    //find the highest number of cubes of anyColor
    //let the first index be a
    int highest = city->cube[0];
    //simple for loop to find the highest

    for (int i=0; i< 5; i++){
        if (city->cube[i] > highest){
            highest = city->cube[i];
        }
    }

    //clear out all the cubes
    for (int i=0; i< 5; i++){
        if (city->cube[i] == highest){
           city->cube[i] = -1;
        }
    }

    GuiManager::showMsgBox("Removed the type with most cubes!");
    Game::decrementActionCounter();
    Board::checkTurn();




}

const std::string &Medic::getName() const {
    return "Medic";
}
