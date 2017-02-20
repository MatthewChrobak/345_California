#pragma once
#include "PlayerCard.h"

class EpidemicCard : public PlayerCard
{
public:
	EpidemicCard();
	~EpidemicCard();

	void playCard();
	std::string getSurfaceName();
};

