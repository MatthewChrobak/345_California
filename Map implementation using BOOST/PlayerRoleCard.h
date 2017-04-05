//
//pixelsOccupied
//

#ifndef BOARD_BOOST_PLAYERROLECARD_H
#define BOARD_BOOST_PLAYERROLECARD_H
#include "PlayerAction.h"


//modify playactions
class PlayerRoleCard: public PlayerAction{
    PlayerAction* playerAction;
public:
    PlayerRoleCard(PlayerAction *playerAction);

    PlayerRoleCard();

     void doAction(Player* player);

};


class Scientist: public PlayerRoleCard {
PlayerAction* playerAction;
public:
    Scientist(PlayerAction *playerAction);

    void doAction(Player* player);


};




#endif //BOARD_BOOST_PLAYERROLECARD_H
