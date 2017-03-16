#pragma once
#include "PlayerCard.h"

class CityCard : public PlayerCard
{
public:
	CityCard(const int cityIndex);
	~CityCard();

	void playCard();
	std::string getSurfaceName();

private:
	int _cityIndex;
};