//
// Created by Nahian Pathan on 2017-03-28.
//

#include "Player.h"

const string &Player::getName() const {
    return name;
}

void Player::setName(const string &name) {
    Player::name = name;
}

Pawn *Player::getCurrentLocation() const {
    return currentLocation;
}

void Player::setCurrentLocation(Pawn *currentLocation) {
    Player::currentLocation = currentLocation;
}

Player::Player() {


    //default name
    name = "Jocob";
    currentLocation = new Pawn();

   cout << "Initiated player" << endl;

}

Player::~Player() {

}

ostream &operator<<(ostream &os, const Player &player) {
    //Pawn* pawn = currentLocation;
    os << "name: " << player.name << " currentLocation: " << *player.currentLocation;
    return os;
}

void Player::setPlayerAction(PlayerAction *playerAction) {
    Player::playerAction = playerAction;
}

Player::Player(const string &name, Pawn *currentLocation,
               const vector<PlayerCard *, allocator<PlayerCard *>> &playerCard, PlayerAction *playerAction) : name(
        name), currentLocation(currentLocation), playerCard(playerCard), playerAction(0) {}

void Player::usePlayerAction() {

    this->playerAction->doAction(this);


}

 vector<PlayerCard *, allocator<PlayerCard *>> &Player::getPlayerCard()  {
    return playerCard;
}

void Player::setPlayerCard(const vector<PlayerCard *, allocator<PlayerCard *>> &playerCard) {
    Player::playerCard = playerCard;
}

PlayerAction *Player::getPlayerAction() const {
    return playerAction;
}




