#pragma once
#include "Player.h"
#include "Card.h"
#include "Cities.h"
#include <iostream>
#include <string>

using namespace std;

//list of all the cities
std::string bankOfCityName[48] = {
	"Hong Kong", "Bangkok", "Chennai", "Kolkata", "Delhi", "Ho Chi Minh City", "Manila", "Jakarta"
	, "Karachi", "Baghdad", "Taipei", "Mumbai", "Tehran", "Shanghai", "Istanbul", "Cairo", "Sydney"
	, "riyadh", "San Francisco", "Algiers", "Tokyo", "Paris", "Moscow", "Los Angeles", "Madrid", "Chicago"
	, "Milan", "Seoul", "St. Petersburg", "Essen", "London", "Mexico City", "Osaka", "Beijing", "New York"
	, "Khartoum", "Bogota", "Miami", "Washington", "Sao Paulo", "Montreal", "Atlanta", "Lima", "Lagos", "Kinshasa"
	, "Buenos Aires", "Johannesburg", "Santiago"
};
std::string generateCityName(){
	//assignment a a city to the infection Card
	std::string name = bankOfCityName[rand() % 47];
	return name;

}


int main(){
	//to ensure the numbers are random everytime
	srand((unsigned)time(0));
	//initiating all cities
	Cities* city[48];
	for (int i = 0; i < 48; i++){
		city[i] = new Cities(bankOfCityName[i]);
	}
	//initiating all the objects for player1
	Role_Card* roleCard = new Role_Card();
	Player_Card* playerCard = new Player_Card();
	Reference_Card* referenceCard = new Reference_Card();

	//initiating all the objects for player2
	Role_Card* roleCard1 = new Role_Card();
	Player_Card* playerCard1 = new Player_Card();
	Reference_Card* referenceCard1 = new Reference_Card();

	//initiating all the players
	Player* player1 = new Player(roleCard, playerCard, referenceCard);
	Player* player2 = new Player(roleCard1, playerCard1, referenceCard1);

	//create infection card
	Infection_Card* infect1 = new Infection_Card(generateCityName());
	Infection_Card* infect2 = new Infection_Card(generateCityName());
	Infection_Card* infect3 = new Infection_Card(generateCityName());

	/*
	*asking the player to infect the require city shown on the card
	*showing the current infection card the player has to infect
	*/
	int counter = 0;
	bool infectedAlreadyCity[3] = { true, true, true };
	do{
		//outputing the infection card
		cout << "City to be Infected: \n"
			<< "1." + infect1->getInfectCityNameCard() << "\n" << "2." + infect2->getInfectCityNameCard() << "\n"
			<<"3." + infect3->getInfectCityNameCard() << endl;

		//player decides which card he wants to infect first
		int kb;
		bool statement = true;

		do{
			cout << "which city do you want to infect first? " << endl;
			cin >> kb;
			switch (kb)
			{
			case 1:
				//if already used
				if (infectedAlreadyCity[0] == false)
					goto invalid;

				player1->setPlayerInfectionCard(infect1);
				statement = false;
				infectedAlreadyCity[0] = false;
				break;
			case 2:
				//if already used
				if (infectedAlreadyCity[1] == false)
					goto invalid;

				player1->setPlayerInfectionCard(infect2);
				statement = false;
				infectedAlreadyCity[1] = false;
				break;
			case 3:
				//if already used
				if (infectedAlreadyCity[2] == false)
					goto invalid;

				player1->setPlayerInfectionCard(infect3);
				statement = false;
				infectedAlreadyCity[2] = false;
				break;
			default:
				invalid:
				cout << "Invalid selection, the card is either used or not drawn yet.\n" << endl;
				break;
			}
		} while (statement);

		//player now decide which city is the correct one to infect
		do{
			statement = true;
			cout << "you are currently holding <" + player1->getPlayerInfectionCard() + "> infection Card" << endl;
			cout << "Which city do you have to infect? " << endl;
			for (int i = 0; i < 48; i++){
				cout << i << ") ";
				cout << city[i]->getCityName() << endl;
			}

			/*
			*taking input from player
			*if the input is correct, the city will be infected
			*/
			cin >> kb;

			if (city[kb]->getCityName() == player1->getPlayerInfectionCard()){
				player1->infectCity(city[kb]);
				counter++;
				statement = false;
			}
			else
				cout << "Invalid city, you need the infection Card of that city.\n" << endl;
		} while (statement);
	

	} while (counter < 3);

	
	//display all the cities with current infection
	for (int i = 0; i < 48; i++){
		cout << "The city of " << city[i]->getCityName()
			<< "\t is been infected with " << city[i]->getCube() << " cube(s)." << endl;
	}
	
	/*
	delete all the pointers
	*/
	delete roleCard;
	delete playerCard;
	delete referenceCard;
	delete roleCard1;
	delete playerCard1;
	delete referenceCard1;
	delete player1;
	delete player2;
	delete infect1;
	delete infect2;
	delete infect3;
	//system will be pause at that point
	system("PAUSE");
}


