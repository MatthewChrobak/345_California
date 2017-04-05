//
// Created by Nahian Pathan on 2017-03-31.
//

#ifndef BOARD_BOOST_PLAYERACTION_H
#define BOARD_BOOST_PLAYERACTION_H

#include "PlayerCard.h"
class Player;

class PlayerAction {

public:
    virtual void doAction(Player* player)=0;

};

class DirectFlightAction: public PlayerAction{


public:
    void doAction(Player* player);

};

class BuildResearchStation: public PlayerAction{


public:
    void doAction(Player* player);

};

class TreatDisease: public PlayerAction{


public:
    void doAction(Player* player);

};

class ShareKnowledge: public PlayerAction{


public:
    void doAction(Player* player);

};

class DiscoverCure: public PlayerAction{


public:
    void doAction(Player* player);

};









#endif //BOARD_BOOST_PLAYERACTION_H
