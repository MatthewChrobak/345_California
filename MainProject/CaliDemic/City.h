#pragma once
#include "ArrayGraphNode.h"
#include "InfectionColors.h"
#include <string>

/*
every city is label has integer so we can work on
number instead of string.
we decide this design because it is easier to implement 
our game engine.
*/
#define CITY_RENDER_WIDTH 30
#define CITY_RENDER_HEIGHT 30

class City : public ArrayGraphNode
{
public:
	City();
	~City();

	static void consoleAddNodeAtCoordDialogue(int x, int y);
	void infectCity(int city,int index);
	static void infectCityOutBreak(int city);
	void buildResearchFacility();

	//attributes of City class
	int x = 0;
	int y = 0;
	static const int cubeMaxSize = 3;
	InfectionColor color;
	std::string name;
	int cube[cubeMaxSize];
	bool research = false;
	bool infected = false;
};


