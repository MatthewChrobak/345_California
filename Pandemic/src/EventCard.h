#pragma once
#include "PlayerCard.h"
#include <vector>


class EventCard : public PlayerCard
{
public:
	EventCardType getEventType();
	EventCard(EventCardType type);
	~EventCard();
	std::string getEventName();
	void playCard();
	std::string getSurfaceName();
	void eventAction(PlayerCard* card);

private:
	EventCardType _eventType;
};

