#pragma once

#include "PlayerCard.h"

class Player;

class PlayerAction {

public:
    virtual void doAction(Player* player)=0;
    virtual  std::string &getName()  =0;


};

class DirectFlightAction1: public PlayerAction{

    std ::string name = "DirectFlight";

public:
    void doAction(Player* player);

     std::string &getName() ;

};

class BuildResearchStation1: public PlayerAction{

    std ::string name = "BuildResearchStation";


public:
    void doAction(Player* player);

    std::string &getName();

};

class TreatDisease1: public PlayerAction{

    std ::string name = "TreatDisease";


public:
    void doAction(Player* player);

     std::string &getName() ;

};

class ShareKnowledge1: public PlayerAction{


    std ::string name = "ShareKnowledge";


public:
    void doAction(Player* player);

     std::string &getName() ;

};

class DiscoverCure1: public PlayerAction{

    std ::string name = "DiscoverCure";


public:
    void doAction(Player* player);

     std::string &getName() ;


};

class Drive1: public PlayerAction{

    std ::string name = "Drive/Ferry";


public:
    void doAction(Player* player);

     std::string &getName() ;


};

class CharterFlight1: public PlayerAction{

    std ::string name = "CharterFlight";


public:
    void doAction(Player* player);

     std::string &getName() ;


};
class ShuttleFlight1: public PlayerAction{

    std ::string name = "ShuttleFlight";


public:
    void doAction(Player* player);

     std::string &getName() ;

};










