#pragma once
#include "City.h"
#include "InfectionColors.h"

class InfectionCard
{
public:
	InfectionCard();
	~InfectionCard();
	static void infectCityCube(int city);
	static void infectLastCity(int city);
	static void infectCityCubeThree(int city);
	static void infectCityCubeTwo(int city);
};

