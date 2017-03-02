#include "Player.h"
#include <iostream>
using namespace std;

class Player{

};
Player::Player(Role_Card* roleCard, Player_Card* playerCard, Reference_Card* referenceCard)
{
	this->roleCard = roleCard;
	this->playerCard = playerCard;
	this->referenceCard = referenceCard;
}

void Player::display()
{
	cout << roleCard;
	cout << playerCard;
	cout << referenceCard;
}








