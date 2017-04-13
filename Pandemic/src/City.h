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

	void infectCity(int city,int index);
	void infectCityTwo(int city, int index);
	void infectCityThree(int city, int index);
	static void infectCityOutBreak(int city);
	void buildResearchFacility();

	// Determines whether or not the city index is within the adjacency list.
	bool isAdjacent(int index);

	//attributes of City class
	int x = 0;
	int y = 0;

	InfectionColor color;
	std::string name;
	int cube[InfectionColor::InfectionColor_Length];
	bool research = false;
	bool inverseAngle = false;
	static int outbreakCount;

	// Retrieves the city if the x/y coordniate hits the city.
	// Intended to be used with the UI system and mouseclicks.
	static City* getCityFromXY(int x, int y);

	// Retrieves the city index if the x/y coordinate hits the city.
	// Intended to be used with the UI system and mouseclicks.
	static int getCityIndexFromXY(int x, int y);
};


