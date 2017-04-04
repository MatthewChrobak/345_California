#pragma once
#include "Card.h"

class Player : virtual public Decorator
{
private:
	Card *card;

public:
	Player();
	~Player();

	Card getPlayerCard();
	virtual void getNumber();
};

