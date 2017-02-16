#pragma once
#include "ArrayGraphNode.h"
#include "InfectionColors.h"
#include <string>

class City : public ArrayGraphNode
{
public:
	City();
	~City();

	static const int Width;
	static const int Height;

	int X = 0;
	int Y = 0;
	InfectionColor Color;
	std::string Name;
};