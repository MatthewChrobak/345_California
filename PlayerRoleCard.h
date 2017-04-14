#pragma once
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
    std :: string name = "Scientist - requires 4 matching player cards instead of 5";

public:
    Scientist(PlayerAction *playerAction);

    void doAction(Player* player);

    const std::string &getName() const;

};

