#pragma once
#include "ArrayGraphNode.h"
#include "InfectionColors.h"
#include <string>

#define CITY_RENDER_WIDTH 30
#define CITY_RENDER_HEIGHT 30

class City : public ArrayGraphNode
{
public:
	City();
	~City();

	static void consoleAddNodeAtCoordDialogue(int x, int y);
	void infectCity();

	int x = 0;
	int y = 0;
	InfectionColor color;
	std::string name;
	int cube[3];
	bool research;
	bool infected = false;
};