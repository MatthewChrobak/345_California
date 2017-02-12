#pragma once
#include "ArrayGraphNode.h"
#include "InfectionColors.h"
#include <string>

class City : public ArrayGraphNode
{
public:
	City(std::string name);
	~City();

	int x = 0;
	int y = 0;

private:
	std::string _name;
	InfectionColor _color;
};