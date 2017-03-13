#pragma once
#include "Player.h"
#include "Cities.h"
#include "Card.h"
#include <iostream>
using namespace std;


/*
this is the constructor
*/
Player::Player(Role_Card* roleCard, Player_Card* playerCard, Reference_Card* referenceCard)
{
	this->roleCard = roleCard;
	this->playerCard = playerCard;
	this->referenceCard = referenceCard;
}

/*
display the player contents
*/
void Player::display()
{
	cout << this->roleCard
		<< " "
		<< this->playerCard
		<< " "
		<< this->referenceCard 
		<< " "
		<< this->infectionCard->getInfectCityNameCard() << endl;

}

void Player::setPlayerInfectionCard(Infection_Card* infectionCard){
	this->infectionCard = infectionCard;
}

std::string Player::getPlayerInfectionCard(){
	return this->infectionCard->getInfectCityNameCard();
}

void Player::infectCity(Cities* targetCity){
	targetCity->infectCube();
	std::cout << targetCity->getCityName() << " is been infected.\n" << std::endl;
}


	









