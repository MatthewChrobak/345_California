#pragma once
#include "Paths.h"
#include <string>

enum PlayerCardType
{
	City_Card,
	Epidemic_Card,
	Event_Card
};

class PlayerCard
{
public:
	PlayerCard();
	~PlayerCard();

	PlayerCardType getType();
	virtual void playCard() = 0;
	virtual std::string getSurfaceName() = 0;

protected:
	PlayerCardType _cardType;
};

