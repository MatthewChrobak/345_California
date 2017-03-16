//
//

#ifndef PANDEMIC_V2_SUBJECT_H
#define PANDEMIC_V2_SUBJECT_H

#include "Observer.h"

//subject interface
class Subject {
public:
    virtual void registerr(Observer* o)=0 ;
    virtual void unregister(Observer* o)=0;
    virtual void notifyObserver()=0;

};


#endif //PANDEMIC_V2_SUBJECT_H
