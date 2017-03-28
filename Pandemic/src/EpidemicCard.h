#pragma once
#include "PlayerCard.h"
#include <string>

#define NUMBER_OF_EPIDEMIC 6

class EpidemicCard : public PlayerCard
{
public:
	EpidemicCard();
	~EpidemicCard();

	void playCard();
	std::string getSurfaceName();
};

