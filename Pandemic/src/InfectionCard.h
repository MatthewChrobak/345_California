#pragma once
#include "City.h"
#include "InfectionColors.h"
#include "GuiManager.h"

class InfectionCard
{
public:
	InfectionCard();
	~InfectionCard();

	static void infectCityCube(int city);
	void infectCity(int city, int index);
	void infectCityOutBreak(int city);

};

