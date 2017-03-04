/*
 * This is the player class. The attributes of the player are set using this class. The class also has a "playCard" function
 * which removes a card from the player's hand when the player chooses to play it, and a "buildStation" function, which discards
 * every same colored card from the player when the player decides to build a station at a certain location.
*/

#include <iostream>
#include <string>
#ifndef PANDEMIC6_REFERENCE_H
#define PANDEMIC6_REFERENCE_H

#include "Reference.h"
#include "Role.h"
#include "Pawn.h"
#include "PlayerCards.h"

using namespace std;

class Player{

private:
    Role playerRole;
    string playerName;
    Pawn playerColor;
    Reference playerReference;
    PlayerCards playerCards;

public:

    Player(Role newPlayerRole, string newPlayerName, Pawn newPlayerColor, Reference newPlayerReference){
        playerRole = newPlayerRole;
        playerName = newPlayerName;
        playerColor = newPlayerColor;
        playerReference = newPlayerReference;
    }

    Player(Role newPlayerRole){
        playerRole = newPlayerRole;
    }

    Player();

public:
    string getPlayerName();
    void setPlayerName(string modifiedPlayerName);

    Role getRoles();
    void setRole(Role modifiedPlayerRole);

    Pawn getColor();
    void setColor(Pawn modifiedColor);

    Reference getReference();
    void setReference(Reference setPlayerReference);

    PlayerCards getPlayerCards();
    void setPlayerCard(PlayerCards *modifiedPlayerCards);

    void playCard();        //Discards a card after a player "plays" it
    void buildStationP();   //Invokes the buildStationPC function from PlayerCards
    void removeEpidemic();  //Invokes the useEpidemic function from PlayerCards
};
#endif //UNTITLED2_MAIN_H
