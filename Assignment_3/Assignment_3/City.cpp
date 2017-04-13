#include "City.h"
#include <iostream>
using namespace std;

City::City()
{
	this->IDcityNumber++;
}


City::~City()
{
}

int City::getCityID()
{
	return this->IDcityNumber;
}

void City::getNumber()
{
	
}


