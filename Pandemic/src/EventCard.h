#pragma once
#include <vector>
#include "PlayerCard.h"


class EventCard : public PlayerCard
{
public:
	EventCard(EventCardType type);
	~EventCard();
	std::string getEventName();
	std::string getSurfaceName();
	EventCardType getEventType();
	void playCard();
	void eventAction(PlayerCard* card);

protected:
	EventCardType _eventType;
};

