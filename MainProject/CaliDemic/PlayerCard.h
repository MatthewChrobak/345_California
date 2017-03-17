#pragma once
#include "Paths.h"
#include <string>
#include <vector>
#include <iostream>

enum PlayerCardType
{
	City_Card,
	Epidemic_Card,
	Event_Card
};


class PlayerCard {

public:
	PlayerCardType getType();
	virtual void playCard() = 0;
	virtual std::string getSurfaceName() = 0;

protected:
	PlayerCardType _cardType;

public:
	std::vector <std::string> playerCardsDeck;

public:
	PlayerCard();
	~PlayerCard();

public:

	void useEpidemic();

};
