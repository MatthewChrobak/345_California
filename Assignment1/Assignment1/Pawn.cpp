#pragma once
#include "Pawn.h"
#include <string>

void Pawn::setPawnColor(std::string color){
		this->pawnColor = color;
}

std::string Pawn::getPawnColor(){
	return this->pawnColor;
}
