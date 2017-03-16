//
//

#include "Player.h"

Player::Player() {}

Player::Player(const string &playerName, int numOfActions, ReferenceCard *referenceCard, RoleCard *roleCard, Pawn *pawn,
               const vector<PlayerCard *> &playerCards) : playerName(playerName), numOfActions(numOfActions),
                                                          referenceCard(referenceCard), roleCard(roleCard), pawn(pawn),
                                                          playerCards(playerCards) {}

Player::~Player() {

}

const string &Player::getPlayerName() const {
    return playerName;
}

void Player::setPlayerName(const string &playerName) {
    Player::playerName = playerName;
}

int Player::getNumOfActions() const {
    return numOfActions;
}

void Player::setNumOfActions(int numOfActions) {
    Player::numOfActions = numOfActions;
}

ReferenceCard *Player::getReferenceCard() const {
    return referenceCard;
}

void Player::setReferenceCard(ReferenceCard *referenceCard) {
    Player::referenceCard = referenceCard;
    notifyObserver();
}

RoleCard *Player::getRoleCard() const {
    return roleCard;
}

void Player::setRoleCard(RoleCard *roleCard) {
    Player::roleCard = roleCard;
    notifyObserver();

}

Pawn *Player::getPawn() const {
    return pawn;
}

void Player::setPawn(Pawn *pawn) {
    Player::pawn = pawn;
    notifyObserver();

}

const vector<PlayerCard *> &Player::getPlayerCards() const {
    return playerCards;
}

void Player::setPlayerCards(const vector<PlayerCard *> &playerCards) {
    Player::playerCards = playerCards;
    notifyObserver();

}

void Player::registerr(Observer *newObs) {

    observerList.push_back(newObs);

}

void Player::unregister(Observer *delObs) {


    long pos = std::find(observerList.begin(), observerList.end(), delObs) - observerList.begin();

    if( pos < observerList.size())
    {
        observerList.erase (observerList.begin()+pos);

    }

    else
        std::cout <<  "not found";


}

void Player::notifyObserver() {

    //iterate through the observers

    for (auto &o : observerList){

        //update everyObserver index

       o->update(pawn,roleCard,referenceCard,playerCards);


    }



}

Player::Player(const vector<Observer*> &observerList) : observerList(observerList) {}
