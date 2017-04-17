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
    std :: string name = "Scientist";

public:
    Scientist(PlayerAction *playerAction);

    void doAction(Player* player);

    const std::string &getName() const;

};


class OperationsExpert: public PlayerRoleCard {
    PlayerAction* playerAction;
    std :: string name = "OperationsExpert";

public:
    OperationsExpert(PlayerAction *playerAction);

    void doAction(Player* player);

    const std::string &getName() const;

};


class Medic: public PlayerRoleCard {
    PlayerAction* playerAction;
    std :: string name = "Medic";

public:
    Medic(PlayerAction *playerAction);

    void doAction(Player* player);

    const std::string &getName() const;

};