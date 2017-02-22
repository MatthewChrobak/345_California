//
// Created by Nahian Pathan on 2017-02-11.
//

#ifndef PANDEMIC_1_1_PLAYER_H
#define PANDEMIC_1_1_PLAYER_H

#include <iostream>
#include "ReferenceCard.h"
#include "RoleCard.h"
#include "Pawn.h"
#include "PlayerCards.h"
class Player {


private:

    //
    //attributes (possesions) of a player are as follows
    std :: string playerName ;
    static int numOfActions; //max number of actions allowed per turn is 4
    ReferenceCard* referenceCard; //one reference card per player
    RoleCard* roleCard; //Role card should have a matching pawn
    Pawn* pawn; // pawn show have the name and the current city implemented in a different class
    PlayerCards* pc = new PlayerCards [7]; //max number of player cards = 7, start with 4 for 2 player game.
    //^Change to vector due to increase in size if the player is a


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

    //movement actions
    void drive (); //Move to a city connected by a white line to the one you are in.
    //void drive (Player &p);

    void directFlight (); //Discard a City card to move to the city named on the card.
    void charterFlight (); //Discard the City card that matches the city you are in to move to any city.
    void shuttleFlight (); //Move from a city with a research station to any other city that has a research station.



    //other actions
    void buildRC ();
    void treatDisease ();
    void shareKnowledge ();
    void discoverCure ();

    //helperMethod to indicate the endOfTurn, also outputs the number of actions remaining
   static bool endOfTurn();


    void useRoleCard();


};


#endif //PANDEMIC_1_1_PLAYER_H
