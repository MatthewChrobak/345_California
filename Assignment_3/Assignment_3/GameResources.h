#pragma once
#include "Decorator.h"

#define NUM_CUBE 24

class GameResources : virtual public Decorator	
{
private:
	int redCube = NUM_CUBE;
	int yellowCube = NUM_CUBE;
	int blackCube = NUM_CUBE;
	int blueCube = NUM_CUBE;
	int availableResearchCenter = 6;
	int numberOfInfectionCard = 48;
	int numberOfPlayerCards = 59;


public:
	GameResources();
	~GameResources();

	virtual void getNumber();
};

