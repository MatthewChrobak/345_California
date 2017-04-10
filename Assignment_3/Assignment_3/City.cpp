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
	cout << "City ID: " << City::getCityID() << endl;
	cout << "Percentage of Infected RedCube in: " << (this->redInfectedCube / 24) * 100 << "%" << endl;
	cout << "Percentage of Infected YellowCube in: " << (this->yellowInfectedCube / 24) * 100 << "%" << endl;
	cout << "Percentage of Infected BlackCube in: " << (this->blackInfectedCube / 24) * 100 << "%" << endl;
	cout << "Percentage of Infected BlueCube in: " << (this->blueInfectedCube / 24) * 100 << "%" << endl;

}


