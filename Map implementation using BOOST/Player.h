//
// Created by Nahian Pathan on 2017-03-28.
//

#ifndef BOARD_BOOST_PLAYER_H
#define BOARD_BOOST_PLAYER_H

#include "iostream"
#include "Pawn.h"
#include "PlayerCard.h"
#include "PlayerAction.h"
//circular so forward declaration needed
class PlayerAction;

class Player{
private:
    std :: string name;
    Pawn* currentLocation;
    vector <PlayerCard*> playerCard;
    PlayerAction* playerAction;
public:

    Player(const string &name, Pawn *currentLocation, const vector<PlayerCard *, allocator<PlayerCard *>> &playerCard,
           PlayerAction *playerAction);

    void setPlayerAction(PlayerAction *playerAction);

    const string &getName() const;

    void setName(const string &name);

    Pawn *getCurrentLocation() const;

    void setCurrentLocation(Pawn *currentLocation);

    Player();

    virtual ~Player();

    friend ostream &operator<<(ostream &os, const Player &player);

    //used with stretegy pattern
    void usePlayerAction();

    vector<PlayerCard *, allocator<PlayerCard *>> &getPlayerCard();

    void setPlayerCard(const vector<PlayerCard *, allocator<PlayerCard *>> &playerCard);

    PlayerAction *getPlayerAction() const;

    //used for the decorator

};


#endif //BOARD_BOOST_PLAYER_H
