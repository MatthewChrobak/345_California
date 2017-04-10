#include "Player.h"


Player::Player()
{
	card = new InfectionCard();
}

Player::~Player()
{
}

InfectionCard Player::getPlayerCard()
{
	return (*card);
}

void Player::getNumber()
{

}

void Player::update()
{
}
