#include "Player.h"

Player:: Player(){};

string Player:: getPlayerName(){
    return playerName;
};

void Player:: setPlayerName(string modifiedPlayerName)
{
    playerName = modifiedPlayerName;
};

Role Player:: getRoles(){
    return playerRole;
};

void Player:: setRole(Role modifiedPlayerRole)
{
    playerRole = modifiedPlayerRole;
};

Pawn Player:: getColor(){
    return playerColor;
};

void Player:: setColor(Pawn modifiedColor){
    playerColor = modifiedColor;
};

Reference Player:: getReference(){
    return playerReference;
};

void Player:: setReference(Reference setPlayerReference) {
    playerReference = setPlayerReference;
};

PlayerCards Player:: getPlayerCards(){
    return playerCards;
}

void Player:: setPlayerCard(PlayerCards *modifiedPlayerCards) {
    playerCards = *modifiedPlayerCards;
}

void Player:: playCard(){

    if(playerCards.getVectorSize() > 0){

        cout << "You currently have the following cards: " << playerCards.getPlayerCards() << "." << endl;
        cout << "Enter the number of the card which you wish to play." << endl;

        int cardToPlay;
        cin >> cardToPlay;

        cout << "The card you played is: " << playerCards.getSingleCard(cardToPlay- 1) << "." << endl;

        //Methods for using card to be implemented

        playerCards.removeSingleCard(cardToPlay - 1);

        cout << "Your current hand is: " << getPlayerCards().getPlayerCards() << "." << endl;
        cout << endl;
    }

    else{
        cout << "You do not have any cards" << endl;
    }
}

void Player:: buildStationP(){
    playerCards.buildStationPC();
}

void Player::removeEpidemic() {
    playerCards.useEpidemic();
}