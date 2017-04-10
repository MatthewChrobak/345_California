#include "GameResources.h"
#include <iostream>
using namespace std;


GameResources::GameResources()
{

}


GameResources::~GameResources()
{

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
