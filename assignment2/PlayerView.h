//
//

#ifndef PANDEMIC_V2_PLAYERVIEW_H
#define PANDEMIC_V2_PLAYERVIEW_H


#include "Observer.h"
#include "Subject.h"

class PlayerView: public Observer {

private:
    ///one reference card per player
    ReferenceCard *referenceCard;

    ///Role card should have a matching pawn
    RoleCard *roleCard;

    /// pawn show have the name and the current city implemented in a different class
    Pawn *pawn;

    ///max number of player cards = 7, start with 4 for 2 player game.
    ///^NOTE: Change to vector, due to a special rolecard...that player gets to have one more
    std::vector<PlayerCard *> playerCards;

   static int observerID;
    Subject* playerView;


public:
    PlayerView(Subject *playerView);

    void update(Pawn* pwn, RoleCard* rc, ReferenceCard* refC, vector<PlayerCard*> pc);



};


#endif //PANDEMIC_V2_PLAYERVIEW_H
