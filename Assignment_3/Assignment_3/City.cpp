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

void City::update()
{

}

void City::getNumber()
{
	cout << "City ID: " << City::getCityID() << endl;
	cout << "Percentage of Infected RedCube in: " << (this->redInfectedCube / 24) * 100 << "%" << endl;
	cout << "Percentage of Infected YellowCube in: " << (this->yellowInfectedCube / 24) * 100 << "%" << endl;
	cout << "Percentage of Infected BlackCube in: " << (this->blackInfectedCube / 24) * 100 << "%" << endl;
	cout << "Percentage of Infected BlueCube in: " << (this->blueInfectedCube / 24) * 100 << "%" << endl;

}

void City::setRedInfectedCube()
{
	this->redInfectedCube++;
	update();
}

void City::setYellowInfectedCube()
{
	this->yellowInfectedCube++;
	update();
}

void City::setBlueInfectedCube()
{
	this->blueInfectedCube++;
	update();
}

void City::setBlackInfectedCube()
{
	this->blackInfectedCube++;
	update();
}

void City::cityInfected()
{

}

