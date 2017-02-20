#include "PlayerCard.h"


PlayerCard::PlayerCard()
{
}


PlayerCard::~PlayerCard()
{
}

void PlayerCard::playCard()
{
	// Throw an exception because this method is virtual and should be overriden.
	throw;
}

std::string PlayerCard::getSurfaceName()
{
	// Throw an exception because this method is virtual and should be overriden.
	throw;
}

PlayerCardType PlayerCard::getType()
{
	return this->_cardType;
}