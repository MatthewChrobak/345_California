#include "Player.h"
#include "PlayerCard.h"

#ifdef DEBUG
#include <assert.h>
#endif

Player::Player()
{
    this->pawn = new Pawn();


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

    if (this->rc != nullptr) {
        delete this->rc;
        this->rc = nullptr;
    }
}


void Player::addCard(PlayerCard* card)
{
    for (int i = 0; i < MAX_PLAYER_CARDS; i++) {
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
	assert(index >= 0 && index < MAX_PLAYER_CARDS);
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
	assert(index >= 0 && index < MAX_PLAYER_CARDS);
#endif
    return this->_playerCards[index];
}

int Player::getNumberOfCards()
{
    int counter = 0;
    for (int i = 0; i < MAX_PLAYER_CARDS; i++)
    {
        if (this->_playerCards[i] != nullptr)
        {
            counter++;
        }
    }
    return counter;
}

//define getters and setters for roleCard

RoleCard *Player::getRoleCard() const {
    return rc;
}

void Player::setRoleCard(RoleCard* newRc) {
    Player::rc = newRc;
}

void Player::usePlayerAction() {

    this->playerAction->doAction(this);


}
PlayerAction *Player::getPlayerAction() const {
    return playerAction;
}

void Player::setPlayerAction(PlayerAction *playerAction) {
    Player::playerAction = playerAction;
}

void Player::usePlayerAction(std::string actionChoice) {



    //match the name of the action to be performed
        for (int i = 0; i < playerActionList.size(); i++) {
            if (playerActionList[i]->getName().compare(actionChoice) == 0) {
                this->setPlayerAction(playerActionList[i]);
                break;
            }

        }
   // int x = this->getCardsSelected()[0];


    //use the corresponding method
    this->playerAction->doAction(this);

}

 vector<PlayerAction *, std::allocator<PlayerAction *>> &Player::getPlayerActionList()  {
    return playerActionList;
}

void Player::setPlayerActionList( vector<PlayerAction *, std::allocator<PlayerAction *>> &playerActionList) {
    Player::playerActionList = playerActionList;
}

 vector<int, std::allocator<int>> &Player::getCardsSelected()  {
    return cardsSelected;
}

void Player::setCardsSelected( vector<int, std::allocator<int>> &cardsSelected) {
    Player::cardsSelected = cardsSelected;
}

int Player::getCitySelected() const {
    return citySelected;
}

void Player::setCitySelected(int citySelected) {
    Player::citySelected = citySelected;
}
