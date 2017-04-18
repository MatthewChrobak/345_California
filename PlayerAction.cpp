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

    cout << "Direct FLIGHT" << endl;
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

        //clear out the vector after selecting
        player->getCardsSelected().clear();

    }

    else
    {
        GuiManager::showMsgBox("Card was null.");
    }

}

 string &DirectFlightAction1::getName()  {

    return name;
}

void BuildResearchStation1::doAction(Player *player) {
    Board* board;

    int cardIndex = player->getCardsSelected()[0];
    PlayerCard* card = player->getCard(cardIndex);
    CityCard *cityCard = (CityCard *) card;
    int cityIndex = cityCard->cityIndex;
    City* tempCity = board->getCity(cityIndex);

    if(!Game::getGameBoard()->getCity(player->pawn->cityIndex)->research) {

        std::cout << "Build RC" << std::endl;
        GuiManager::showMsgBox("Got a new Research Station");

        Game::getGameBoard()->getCity(player->pawn->cityIndex)->research = true;
        player->removeCard(cardIndex);
        Game::numOfResearchCenter--;
        Game::decrementActionCounter();
        Board::checkTurn();
        //reset player actions
        GameFrame::PlayerAction = PlayerActions::NoPlayerAction;

    }
    else
    {
        GuiManager::showMsgBox("There's already an RC");

    }



}

 string &BuildResearchStation1::getName()  {
    return name;
}

void TreatDisease1::doAction(Player *player) {


    std :: cout <<"Treated Disease" << std::endl;


    City* city = Game::getGameBoard()->getCity(player->pawn->cityIndex);

    GuiManager::showMsgBox("Removing one cube!");

    //find the highest number of cubes of anyColor
    //let the first index be a
    int highest = city->cube[0];
    //simple for loop to find the highest
    cout << city->cube[0] << endl;

    for (int i=0; i< 5; i++){
        cout << city->cube[i] << endl;
        if (city->cube[i] > highest){
             highest = city->cube[i]   ;
        }
    }

    cout << highest << endl;

    //clear out all the cubes
    //get a temp i value to figure out which cube got taken away
    int temp = 0;
    for (int i=0; i< 5; i++){
        if (city->cube[i] == highest){
            city->cube[i]--;
            GuiManager::showMsgBox("An infection cube has been remove in the current city");
            temp = i;
            break;
        }
    }

    


    Game::numOfCubeIncrementor(city->cube[temp]);
    Game::decrementActionCounter();
    Board::checkTurn();
    GameFrame::PlayerAction = PlayerActions::NoPlayerAction;



}

 string &TreatDisease1::getName()  {
    return name;
}

void ShareKnowledge1::doAction(Player *player) {

    std :: cout <<"Shared Knowledge" << std::endl;


}

 string &ShareKnowledge1::getName()  {
    return name;
}

void DiscoverCure1::doAction(Player *player) {
    // Card selection is handled in the Buttons cpp

    //main thread is here becuase 5 same colored
    //get the player's current location
    int playerCurrentLocation = player->pawn->cityIndex;
    //Find if the city has a RC
    City* currentCity = Game::getGameBoard()->getCity(playerCurrentLocation);
    //if true discover something cool
    if (currentCity->research){
        //get the color of the cards selected
        City* cityToGetCardColor = Game::getGameBoard()->getCity(player->getCardsSelected()[0]);
        //check it already cured

        if (Game::getGameBoard()->isCured[cityToGetCardColor->color]) {
            GuiManager::showMsgBox("This disease has already been cured!");
            player->getCardsSelected().clear();
            return;
        }
        else {
            Game::getGameBoard()->isCured[cityToGetCardColor->color] = true;
            //Get rid of all the cubes with respect to card's color
            currentCity->cube[cityToGetCardColor->color] = -1;
        }

    }
    else
    {
        GuiManager::showMsgBox("There's not RC in your current city!...you're gonna need that ");

    }




}

 string &DiscoverCure1::getName()  {
    return name;
}

 string &Drive1::getName()  {
    return name;
}

void Drive1::doAction(Player *player) {

    std :: cout <<"Drove" << std::endl;


}

 string &CharterFlight1::getName()  {
    return name;
}

void CharterFlight1::doAction(Player *player) {

    //int clickedCityIndex = City::getCityIndexFromXY(x, y);



    //INDEX OF THE CARD SELECTED
    int cardIndex = player->getCardsSelected()[0];
    // MATCH THE CARD WITH A  PLAYERCARD
    PlayerCard* card = player->getCard(cardIndex);
    //find the city card
    CityCard *cityCard = (CityCard *) card;
    int cityIndex = cityCard->cityIndex;

    ///GUI INPUT COMING IN FROM BOARD.CPP

   int input = player->getCitySelected();

    // current index of player matches the card selected
    if(player->pawn->cityIndex == player->getCardsSelected()[1])
    {

        player->pawn->cityIndex = input;
        player->removeCard(cardIndex);
        Game::decrementActionCounter();
        Board::checkTurn();
        GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = false;
        //reset player Actions


    //clear out the vector after selecting
        player->getCardsSelected().clear();
        GameFrame::PlayerAction = PlayerActions::NoPlayerAction;


    }
    std :: cout <<"Charter flight" << std::endl;


}

 string &ShuttleFlight1::getName()  {
    return name;
}

void ShuttleFlight1::doAction(Player *player) {

    std :: cout <<"Shuttle FLight" << std::endl;

    Board* board = Game::getGameBoard();


    //check if the player is in a city with RC
    // find the city
    City* curentCity = board->getCity(player->pawn->cityIndex);

    if (curentCity->research){
        //search for a city RC
        for (int i=0; i < board->getNumCities(); i++){
            City* city = board->getCity(i);
            if(city->research){

                player->pawn->cityIndex = i;
                GuiManager::showMsgBox("Player just moved");


            }



        }
    }
    else
        GuiManager::showMsgBox("You're not in a city with RC");


}
