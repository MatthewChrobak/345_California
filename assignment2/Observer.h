//
//

#ifndef PANDEMIC_V2_OBSERVER_H
#define PANDEMIC_V2_OBSERVER_H

#include "Pawn.h"
#include "RoleCard.h"
#include "ReferenceCard.h"
#include "PlayerCard.h"
#include <vector>
class Observer {

public:
    virtual void update(Pawn* pwn, RoleCard* rc, ReferenceCard* refC, vector<PlayerCard*> pc) =0;

};


#endif //PANDEMIC_V2_OBSERVER_H
