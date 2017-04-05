//
// Created by Nahian Pathan on 2017-03-22.
//

#ifndef BOARD_BOOST_PANDEMICENGINE_H
#define BOARD_BOOST_PANDEMICENGINE_H
#include "Board.h"
#include "Player.h"

class PandemicEngine {

    Board* board;
    vector <Player*> playerList;
    Player* currentPlayer;

public:
    PandemicEngine();

    virtual ~PandemicEngine();

    PandemicEngine(Board *board, const vector<Player *, allocator<Player *>> &playerList);

    void initializePlayers();

    Board *getBoard() const;

    void setBoard(Board *board);

    const vector<Player *, allocator<Player *>> &getPlayerList() const;

    void setPlayerList(const vector<Player *, allocator<Player *>> &playerList);

    void playRound();
};


#endif //BOARD_BOOST_PANDEMICENGINE_H
