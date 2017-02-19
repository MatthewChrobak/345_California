#pragma once
#include "ArrayGraphNode.h"
#include "InfectionColors.h"
#include <string>

class City : public ArrayGraphNode
{
public:
	City();
	~City();

	static void consoleAddNodeAtCoordDialogue(int x, int y);
	static const int RenderWidth;
	static const int RenderHeight;

	int x = 0;
	int y = 0;
	InfectionColor color;
	std::string name;
};