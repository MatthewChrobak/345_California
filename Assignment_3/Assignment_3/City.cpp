#include "City.h"
#include <iostream>
using namespace std;

City::City()
{
	this->observers = new vector <Observer*>;
	this->IDcityNumber++;
}


City::~City()
{
	delete this->observers;
}

void City::attach(Observer* o)
{
	this->observers->push_back(o);
}

void City::detach(Observer* o)
{
	for (unsigned int i = 0; i < this->observers->size(); i++)
	{
		if ((this->observers->at(i)) == o)
		{
			cout << "Observer " << (this->observers->at(i)) << " is deleted" << endl;
			this->observers->erase(this->observers->begin() + i);
		}
	}
}

void City::notify()
{
	for (unsigned int i = 0; i < this->observers->size(); i++)
	{
		this->observers->at(i)->update();
	}
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


