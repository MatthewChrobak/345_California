#pragma once
#include "PlayerCard.h"
#include <string>

class EpidemicCard : public PlayerCard
{
public:
	EpidemicCard();
	~EpidemicCard();

	void playCard();
	std::string getSurfaceName();
};

