/*
COMMON PART (PLAYER CLASS)
DISTINCT PART -> ROLE CARD AND REFERENCE CARD CLASSES.
*/

#ifndef PANDEMIC_1_1_PLAYER_H
#define PANDEMIC_1_1_PLAYER_H

#include <iostream>
#include "ReferenceCard.h"
#include "RoleCard.h"
#include "Pawn.h"
#include "PlayerCards.h"
class Player {


private:
    ///attributes (possesions) of a player are as follows
    std :: string playerName ;

    ///max number of actions allowed per turn is 4
    static int numOfActions;

    ///one reference card per player
    ReferenceCard* referenceCard;

    ///Role card should have a matching pawn
    RoleCard* roleCard;

    /// pawn show have the name and the current city implemented in a different class
    Pawn* pawn;

    ///max number of player cards = 7, start with 4 for 2 player game.
    ///^NOTE: Change to vector, due to a special rolecard...that player gets to have one more
    PlayerCards* pc = new PlayerCards [7];



public:

    Player(const std::string &playerName, ReferenceCard *referenceCard, RoleCard *roleCard, Pawn *pawn,
           PlayerCards *pc);

    Player();

    virtual ~Player();

    const std::string &getPlayerName() const;

    void setPlayerName(const std::string &playerName);

    static int getNumOfActions();

    static void setNumOfActions(int numOfActions);

    ReferenceCard *getReferenceCard() const;

    void setReferenceCard(ReferenceCard *referenceCard);

    RoleCard *getRoleCard() const;

    void setRoleCard(RoleCard *roleCard);

    Pawn *getPawn() const;

    void setPawn(Pawn *pawn);

    PlayerCards *getPc() const;

    void setPc(PlayerCards *pc);

    friend std::ostream &operator<<(std::ostream &os, const Player &player);

    //methods for player

    ///movement actions

    ///Move to a city connected by a white line to the one you are in.
    ///@param
    void drive ();

    ///Discard a City card to move to the city named on the card.
    ///@param
    void directFlight ();

    ///Discard the City card that matches the city you are in to move to any city.
    ///@param
    void charterFlight ();

    ///Move from a city with a research station to any other city that has a research station.
    ///@param
    void shuttleFlight ();



    ///other actions
    void buildRC ();
    void treatDisease ();
    void shareKnowledge ();
    void discoverCure ();

    static bool endOfTurn();
    ///helperMethod to indicate the endOfTurn, also outputs the number of actions remaining


    void useRoleCard();


};


#endif //PANDEMIC_1_1_PLAYER_H
