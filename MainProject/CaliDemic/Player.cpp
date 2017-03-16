#include "Player.h"
#include "PlayerCard.h"

#ifdef DEBUG
#include <assert.h>
#endif	

Player::Player()
{
	this->pawn = new Pawn();
	playerCardCounter = 0;

	// Make sure all the card pointers point to null.
	for (int i = 0; i < MAX_PLAYER_CARDS; i++) {
		this->_playerCards[i] = nullptr;
	}
}


Player::~Player()
{
	if (this->pawn != nullptr) {
		delete this->pawn;
		this->pawn = nullptr;
	}
	
	for (int i = 0; i < MAX_PLAYER_CARDS; i++) {
		if (this->_playerCards[i] != nullptr) {
			delete this->_playerCards[i];
		}
	}
}


void Player::addCard(PlayerCard* card) 
{
	for (int i = 0; i < MAX_PLAYER_CARDS; i++) {
		if (this->_playerCards[i] == nullptr) {
			this->_playerCards[i] = card;
			playerCardCounter++;
			break;
		}
	}
}

void Player::removeCard(int index)
{
#ifdef DEBUG
	// Make sure the index is within the bounds specified.
	assert(index >= 0 && index < MAX_PLAYER_CARDS);
#endif
	if (this->_playerCards[index] != nullptr) {
		delete this->_playerCards[index];
		this->_playerCards[index] = nullptr;
		playerCardCounter--;
	}
}

PlayerCard* Player::getCard(int index)
{
#ifdef DEBUG
	// Make sure the index is within the bounds specified.
	assert(index >= 0 && index < MAX_PLAYER_CARDS);
#endif
	return this->_playerCards[index];
}

int Player::getNumberOfCards()
{
	return playerCardCounter;
}
