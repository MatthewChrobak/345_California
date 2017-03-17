#pragma once
#include "Pawn.h"
#include "PlayerCard.h"
#include "RoleCard.h"

#define MAX_PLAYER_CARDS 7

class Player
{
public:
	Pawn* pawn;
	
	Player();
	~Player();

	void addCard(PlayerCard* card);
	PlayerCard* getCard(int index);
	void removeCard(int index);
	RoleCard *getRoleCard() const;
	void setRoleCard(RoleCard* rc);
	


private:
	PlayerCard* _playerCards[MAX_PLAYER_CARDS];
    RoleCard* rc;
};

