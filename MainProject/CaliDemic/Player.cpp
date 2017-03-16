#include "Player.h"
#include "PlayerCard.h"

#ifdef DEBUG
#include <assert.h>
#endif	

Player::Player()
{
	this->pawn = new Pawn();
	

	// Make sure all the card pointers point to null.
/*	for (int i = 0; i < maxPlayerCards; i++) {
		this->_playerCards[i] = nullptr;
	}*/
}


Player::~Player()
{
	if (this->pawn != nullptr) {
		delete this->pawn;
		this->pawn = nullptr;
	}
	
	for (int i = 0; i < maxPlayerCards; i++) {
		if (this->_playerCards[i] != nullptr) {
			delete this->_playerCards[i];
		}
	}
}


void Player::addCard(PlayerCard* card) 
{
	for (int i = 0; i < maxPlayerCards; i++) {
		if (this->_playerCards[i] == nullptr) {
			this->_playerCards[i] = card;
			break;
		}
	}
}

void Player::removeCard(int index)
{
#ifdef DEBUG
	// Make sure the index is within the bounds specified.
	assert(index >= 0 && index < maxPlayerCards);
#endif
	if (this->_playerCards[index] != nullptr) {
		delete this->_playerCards[index];
		this->_playerCards[index] = nullptr;
	}
}

PlayerCard* Player::getCard(int index)
{
#ifdef DEBUG
	// Make sure the index is within the bounds specified.
	assert(index >= 0 && index < maxPlayerCards);
#endif
	return this->_playerCards[index];
}

int Player::getNumberOfCards()
{
	return this->_playerCards.size();
}
