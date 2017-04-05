//
// Created by Nahian Pathan on 2017-03-22.
//

#include "PandemicEngine.h"
#include "boost/graph/connected_components.hpp"
#include "vector"
PandemicEngine::PandemicEngine() {


    board = new Board();
    board->initializeCity();
    board->addEdges();


    int counter=0;

    std::vector<int> component(num_vertices(board->getGraph()));
    int num = connected_components(board->getGraph(), &component[0]);
    while (num != 1){

        board->getGraph().clear();
        delete board;
        counter++;
        board = new Board();
        board->initializeCity();
        board->addEdges();
        num = connected_components(board->getGraph(), &component[0]);

    }



    cout << "Number of tries #" << counter << endl;
    cout << "Component total ->" << num << endl;
    currentPlayer = nullptr;

    cout << "GAME IS READY" << endl;

    initializePlayers();
}

PandemicEngine::PandemicEngine(Board *board, const vector<Player *, allocator<Player *>> &playerList) : board(board),
                                                                                                        playerList(
                                                                                                                playerList) {



}

void PandemicEngine::initializePlayers() {


   Pawn* pawn = new Pawn (board);

    cout << "How many players?" << endl;
    int numberOfPlayers;
    cin >> numberOfPlayers;
    for (int i =0; i< numberOfPlayers; i++){

        //initialize a player
        playerList.push_back(new Player);
        //set current location
        playerList[0]->setCurrentLocation(pawn);

    }

    playRound();


}

Board *PandemicEngine::getBoard() const {
    return board;
}

void PandemicEngine::setBoard(Board *board) {
    PandemicEngine::board = board;
}

const vector<Player *, allocator<Player *>> &PandemicEngine::getPlayerList() const {
    return playerList;
}

void PandemicEngine::setPlayerList(const vector<Player *, allocator<Player *>> &playerList) {
    PandemicEngine::playerList = playerList;
}

PandemicEngine::~PandemicEngine() {

}

void PandemicEngine::playRound() {

    //if the the current player is not initialized set it to the first player of the player vector
    if(currentPlayer == nullptr){

        cout <<"Setting the current player now" << endl;
        currentPlayer = playerList[0];

    }

    cout <<"Ready for some player actions! Please select from the following choices!" << endl;
    cout <<"0) drive or Fly; \n1) build a research station;\n2) treat a disease, \n3) Share Knowledge" << endl;

    //initialized all the methods
    DirectFlightAction directFlightAction;
    BuildResearchStation buildResearchStation;
    TreatDisease treatDisease;
    ShareKnowledge shareKnowledge;

    int i;
    cin >> i;

    PlayerAction* pcArray [] = {&directFlightAction, &buildResearchStation, &treatDisease, &shareKnowledge};

    currentPlayer->setPlayerAction(pcArray[i]);
    currentPlayer->usePlayerAction();






}
