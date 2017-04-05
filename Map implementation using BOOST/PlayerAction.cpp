//
// Created by Nahian Pathan on 2017-03-31.
//

#include "PlayerAction.h"
#include "Player.h"
void DirectFlightAction::doAction(Player *player) {
    std :: cout << "Where would like to fly to?, input the corresponding integer" << std::endl;

   const int size = player->getPlayerCard().size();

    for (int i=0; i<size; i++){

        std :: cout << "i#" << i << " " << player->getPlayerCard()[i]->getCardName() << std :: endl;

    }
    int input;
    cin >> input;
    string cardTobeDiscarded = player->getPlayerCard()[input]->getCardName();

    cout << "Card selected " << cardTobeDiscarded << endl;

    Board* b = player->getCurrentLocation()->getBoardForPawn();
   // b->printMapContent();

    VertexID temp;
    temp = player->getCurrentLocation()->getBoardForPawn()->cityExists(cardTobeDiscarded);
    Vertex *newLocation = &player->getCurrentLocation()->getBoardForPawn()->getGraph()[temp];
    player->getCurrentLocation()->setCurrentCity(newLocation);

    cout << "Player's new location is set to " << player->getCurrentLocation()->getCurrentCity()->getCityName() << endl;

    cout << "Card dicarded" << endl;

    player->getPlayerCard().erase(player->getPlayerCard().begin() + input);


    std :: cout <<"Player just flew" << std::endl;

}

void BuildResearchStation::doAction(Player *player) {


 std :: cout <<"Build RC" << std::endl;



}

void TreatDisease::doAction(Player *player) {


 std :: cout <<"Treated Disease" << std::endl;


}

void ShareKnowledge::doAction(Player *player) {

 std :: cout <<"Shared Knowledge" << std::endl;


}

void DiscoverCure::doAction(Player *player) {

    cout << "Needs 5 mathcing cards" << endl;

}
