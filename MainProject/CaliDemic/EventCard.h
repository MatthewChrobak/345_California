#pragma once
#include "PlayerCard.h"
#include <vector>;

enum EventCardType
{
	Airlift,
	OneQuietNight,
	ResilientPopulation,
	GovernmentGrant,
	Forecast
};


class EventCard : public PlayerCard
{
public:
	EventCard(EventCardType type);
	~EventCard();
	std::string getEventName();
	void playCard();
	std::string getSurfaceName();

private:
	EventCardType _eventType;
};

