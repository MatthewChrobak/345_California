//
//pixelsOccupied

#include "PlayerRoleCard.h"




PlayerRoleCard::PlayerRoleCard(PlayerAction *playerAction) : playerAction(playerAction) {}

PlayerRoleCard::PlayerRoleCard() {}

void PlayerRoleCard::doAction(Player *player) {

}


void Scientist::doAction(Player *player) {

    std :: cout << "needs 4 cards" << std::endl;

}

Scientist::Scientist(PlayerAction *playerAction) : playerAction(playerAction) {}