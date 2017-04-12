#pragma once

#include "PlayerCard.h"

class Player;

class PlayerAction {

public:
    virtual void doAction(Player* player)=0;
    virtual const std::string &getName() const =0;


};

class DirectFlightAction: public PlayerAction{

    std ::string name = "DirectFlightAction";

public:
    void doAction(Player* player);

    const std::string &getName() const;

};

class BuildResearchStation: public PlayerAction{

    std ::string name = "BuildResearchStation";


public:
    void doAction(Player* player);

    const std::string &getName() const;

};

class TreatDisease: public PlayerAction{

    std ::string name = "TreatDisease";


public:
    void doAction(Player* player);

    const std::string &getName() const;

};

class ShareKnowledge: public PlayerAction{


    std ::string name = "ShareKnowledge";


public:
    void doAction(Player* player);

    const std::string &getName() const;

};

class DiscoverCure: public PlayerAction{

    std ::string name = "DiscoverCure";


public:
    void doAction(Player* player);

    const std::string &getName() const;


};

class Drive: public PlayerAction{

    std ::string name = "Drive/Ferry";


public:
    void doAction(Player* player);

    const std::string &getName() const;


};

class CharterFlight: public PlayerAction{

    std ::string name = "CharterFlight";


public:
    void doAction(Player* player);

    const std::string &getName() const;


};
class ShuttleFlight: public PlayerAction{

    std ::string name = "ShuttleFlight";


public:
    void doAction(Player* player);

    const std::string &getName() const;

};










