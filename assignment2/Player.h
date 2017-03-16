//
//

#ifndef PANDEMIC_V2_PLAYER_H
#define PANDEMIC_V2_PLAYER_H


#include <vector>
#include <iostream>
#include "ReferenceCard.h"
#include "RoleCard.h"
#include "Pawn.h"
#include "PlayerCard.h"
#include "Subject.h"
#include "Observer.h"
#include "PlayerView.h"

using namespace std;
class Player: public Subject {

private:
    ///attributes (possesions) of a player are as follows
    std::string playerName;

    ///max number of actions allowed per turn is 4
    int numOfActions;

    ///one reference card per player
    ReferenceCard *referenceCard;

    ///Role card should have a matching pawn
    RoleCard *roleCard;

    /// pawn show have the name and the current city implemented in a different class
    Pawn *pawn;

    ///max number of player cards = 7, start with 4 for 2 player game.
    ///^NOTE: Change to vector, due to a special rolecard...that player gets to have one more
    std::vector<PlayerCard *> playerCards;

    //observer vector
    vector <Observer*> observerList;

public:

    Player();

    Player(const string &playerName, int numOfActions, ReferenceCard *referenceCard, RoleCard *roleCard, Pawn *pawn,
           const vector<PlayerCard *> &playerCards);

    Player(const vector<Observer*> &observerList);

    virtual ~Player();

    const string &getPlayerName() const;

    void setPlayerName(const string &playerName);

    int getNumOfActions() const;

    void setNumOfActions(int numOfActions);

    ReferenceCard *getReferenceCard() const;

    void setReferenceCard(ReferenceCard *referenceCard);

    RoleCard *getRoleCard() const;

    void setRoleCard(RoleCard *roleCard);

    Pawn *getPawn() const;

    void setPawn(Pawn *pawn);

    const vector<PlayerCard *> &getPlayerCards() const;

    void setPlayerCards(const vector<PlayerCard *> &playerCards);

     void registerr(Observer* newObs);
     void unregister(Observer* delObs);
     void notifyObserver();






};

#endif //PANDEMIC_V2_PLAYER_H
