#pragma once
#include "Card.h"
#include "Cities.h"
#include "Pawn.h"
#include <string>
#include <iostream>

//infection Card
Infection_Card::Infection_Card(std::string infectCityNameCard){
	
	this->infectCityNameCard = infectCityNameCard;
}


std::string Infection_Card::getInfectCityNameCard(){
	return this->infectCityNameCard;
}

