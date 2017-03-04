#pragma once
#include <string>

class Pawn{
private:
	std::string pawnColor;

public: 
	Pawn();
	~Pawn();
	void setPawnColor(std::string color);
	std::string getPawnColor();
};