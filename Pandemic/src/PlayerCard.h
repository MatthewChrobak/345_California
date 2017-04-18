#pragma once
#include "Paths.h"
#include <string>
#include <vector>
#include <iostream>
#include <random>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

enum PlayerCardType
{
	City_Card,
	Epidemic_Card,
	Event_Card
};

enum EventCardType
{
	Airlift,
	OneQuietNight,
	ResilientPopulation,
	GovernmentGrant,
	Forecast
};


class PlayerCard {

private: std::vector<PlayerCard*> _playerWithdrawPile;

public:
	PlayerCardType getType();
	virtual void playCard() = 0;
	virtual std::string getSurfaceName() = 0;

protected:
	PlayerCardType _cardType;

public:
	PlayerCard();
	~PlayerCard();
	virtual EventCardType getEventType();
	virtual void eventAction(PlayerCard* card);

};

