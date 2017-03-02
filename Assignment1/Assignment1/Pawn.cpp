#pragma once
#include "Pawn.h"
#include <string>

class Pawn{
private:
	std::string pawnColor = "";
public:
	void setPawnColor(std::string color){
		Pawn::pawnColor = color;
	}
};