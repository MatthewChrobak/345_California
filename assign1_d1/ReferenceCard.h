/*
COMMON PART (PLAYER CLASS)
DISTINCT PART -> ROLE CARD AND REFERENCE CARD CLASSES.
*/
#ifndef PANDEMIC_1_1_REFERENCECARD_H
#define PANDEMIC_1_1_REFERENCECARD_H

#include <iostream>
#include "ReferenceCard.h"
#include "RoleCard.h"

///Only prints the reference and Rolecard's special ability

class ReferenceCard: public RoleCard{
private:
    typedef RoleCard super;

public:
    ReferenceCard(RoleCard *r);

public:
    void display();
};


#endif //PANDEMIC_1_1_REFERENCECARD_H
