//
// Created by Nahian Pathan on 2017-02-11.
//

#include "Player.h"

#include <iostream>
using namespace std;

int Player::numOfActions = 0;

Player::Player(const string &playerName, ReferenceCard *referenceCard, RoleCard *roleCard, Pawn *pawn, PlayerCards *pc)
        : playerName(playerName), referenceCard(referenceCard), roleCard(roleCard), pawn(pawn), pc(pc) {

    cout << "INSIDE PLAYER PARAMETRIZED CONSTRUCTOR" << endl;


}

Player::Player() {

    cout << "INSIDE PLAYER DEFAULT CONSTRUCTOR" << endl;


}

Player::~Player() {

    cout << "INSIDE PLAYER DESTRUCTOR" << endl;

}

const string &Player::getPlayerName() const {
    return playerName;
}

void Player::setPlayerName(const string &playerName) {

    cout << "\nSetting player name to - " << playerName << endl;
    Player::playerName = playerName;
}

int Player::getNumOfActions() {
    return numOfActions;
}

void Player::setNumOfActions(int numOfActions) {
    Player::numOfActions = numOfActions;
}

ReferenceCard *Player::getReferenceCard() const {

    return referenceCard;
}

void Player::setReferenceCard(ReferenceCard *referenceCard) {
    cout << "Setting referencecard..." << endl;
    Player::referenceCard = referenceCard;
}

RoleCard *Player::getRoleCard() const {
    return roleCard;
}

void Player::setRoleCard(RoleCard *roleCard) {

    cout << "Setting rolecard..." << endl;
    Player::roleCard = roleCard;
}

Pawn *Player::getPawn() const {
    return pawn;
}

void Player::setPawn(Pawn *pawn) {
    cout << "Setting pawn..." << endl;
    Player::pawn = pawn;
}

PlayerCards *Player::getPc() const {
    return pc;
}

void Player::setPc(PlayerCards *pc) {
    cout << "Setting playercards..." << endl;
    Player::pc = pc;
}

ostream &operator<<(ostream &os, const Player &player) {
    os << "playerName: " << player.playerName << " referenceCard: " << &player.referenceCard << " roleCard: "
       << player.roleCard << " pawn: " << player.pawn << " pc: " << player.pc;
    return os;
}

void Player::drive() {

    numOfActions--;

    endOfTurn();
}

void Player::directFlight() {

}

void Player::charterFlight() {

}

void Player::shuttleFlight() {

}

void Player::buildRC() {

}

void Player::treatDisease() {
   if(this->getRoleCard()->getRoleCardVal() == 5){

       //check if 5 of the same cards




   }



}

void Player::shareKnowledge() {

}

void Player::discoverCure() {




}

 bool Player::endOfTurn() {
    if (getNumOfActions() >=1 || getNumOfActions() <= 3) {
        std::cout << "Number of actions remaining " << (4-getNumOfActions()) << std::endl;
        return true;
    }
    else
        std :: cout << "End Of turn"<< std:: endl;
     return false;
}


