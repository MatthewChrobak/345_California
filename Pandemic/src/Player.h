#pragma once
#include "Pawn.h"
#include "PlayerCard.h"
#include "RoleCard.h"

#define MAX_PLAYER_CARDS 7
#define MAX_PLAYER_CARDS_IN_HAND 9

class Player
{
public:
	Pawn* pawn;
	Player();
	~Player();

	void addCard(PlayerCard* card);
	PlayerCard* getCard(int index);
	void removeCard(int index);
	int getNumberOfCards();
	RoleCard *getRoleCard() const;
	void setRoleCard(RoleCard* rc);

private:
  RoleCard* rc;
	PlayerCard* _playerCards [MAX_PLAYER_CARDS];
};

