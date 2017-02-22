//
// Created by Nahian Pathan on 2017-02-11.
//

#ifndef PANDEMIC_1_1_REFERENCECARD_H
#define PANDEMIC_1_1_REFERENCECARD_H

#include <iostream>
#include "ReferenceCard.h"
#include "RoleCard.h"


class ReferenceCard: public RoleCard{
private:
    typedef RoleCard super;

public:
    ReferenceCard(RoleCard *r);

public:
    void display();
};


#endif //PANDEMIC_1_1_REFERENCECARD_H
