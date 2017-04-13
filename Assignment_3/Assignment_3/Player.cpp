#include "Player.h"


Player::Player()
{
	card = new Card();
}


Player::~Player()
{
}

Card Player::getPlayerCard()
{
	return (*card);
}