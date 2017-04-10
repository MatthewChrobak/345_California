#pragma once
#include "Decorator.h"
#include "Subject.h"
#include "InfectionCard.h"

class Player : virtual public Decorator, public Observer
{
private:
	InfectionCard *card;

public:
	Player();
	~Player();

	InfectionCard getPlayerCard();
	virtual void getNumber();
	void update();
};

