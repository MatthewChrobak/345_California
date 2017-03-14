#pragma once
#include "Pawn.h"
#include "PlayerCard.h"

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

private:
	PlayerCard* _playerCards[MAX_PLAYER_CARDS];
};

