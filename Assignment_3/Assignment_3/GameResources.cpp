#include "GameResources.h"
#include <iostream>
using namespace std;


GameResources::GameResources()
{

}


GameResources::~GameResources()
{

}

void GameResources::attach(Observer* o)
{
	this->observers->push_back(o);
}

void GameResources::detach(Observer* o)
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

void GameResources::notify()
{
	for (unsigned int i = 0; i < this->observers->size(); i++)
	{
		this->observers->at(i)->update();
	}
}

void GameResources::update()
{

}

void GameResources::getNumber()
{
	cout << "GameResources: " << endl;
	cout << "Percentage of Infect RedCube left: " << (this->redCube / 24) * 100 << "%" << endl;
	cout << "Percentage of Infect YellowCube left: " << (this->yellowCube / 24) * 100 << "%" << endl;
	cout << "Percentage of Infect BlackCube left: " << (this->blackCube / 24) * 100 << "%" << endl;
	cout << "Percentage of Infect BlueCube left: " << (this->blueCube / 24) * 100 << "%" << endl;
	cout << "Percentage of available Research Center left: " << (this->availableResearchCenter / 6) * 100 << "%" << endl;
	cout << "Percentage of number of InfectionCard left: " << (this->numberOfInfectionCard / 48) * 100 << "%" << endl;
	cout << "Percentage of number of PlayerCard left: " << (this->numberOfPlayerCards / 59) * 100 << "%" << endl;
}

void GameResources::display()
{

}
