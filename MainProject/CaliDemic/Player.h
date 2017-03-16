#pragma once
#include "Pawn.h"
#include "PlayerCard.h"

static const int maxPlayerCards = 7;

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


private:
	vector <PlayerCard*> _playerCards;
};

