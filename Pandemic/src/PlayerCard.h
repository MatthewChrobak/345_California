#pragma once
#include "Paths.h"
#include <string>
#include <vector>
#include <iostream>
#include <random>


enum PlayerCardType : int
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


class PlayerCard 
{

private: 
	std::vector<PlayerCard*> _playerWithdrawPile;

public:
	PlayerCardType getType();
	virtual void playCard();
	virtual std::string getSurfaceName();
	virtual EventCardType getEventType();
	virtual void eventAction(PlayerCard* card);


protected:
	PlayerCardType _cardType;

public:
	PlayerCard();
	~PlayerCard();

};

