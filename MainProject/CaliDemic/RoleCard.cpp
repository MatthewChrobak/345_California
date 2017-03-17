/*
COMMON PART (PLAYER CLASS)
DISTINCT PART -> ROLE CARD AND REFERENCE CARD CLASSES.
*/
#include <iostream>
#include "RoleCard.h"


RoleCard::RoleCard(const std::string &roleCardname)
        : roleCardname(roleCardname){

    int roleValue = this->getRoleCardNum();

    this->setRoleCardVal(roleValue);

    std :: string roleCardC [] = {"Teel", "Brown", "White", "Pink", "Light Green", "Orange", "Dark Green"};

    this->setRoleCardColour(roleCardC[roleValue]);

    std :: cout << "\nInitiating RoleCard..." << std:: endl;

  

}

RoleCard::~RoleCard() {

    std :: cout << "INSIDE RC DESTRUCTOR "<< std :: endl;



}

RoleCard::RoleCard() {}

const std::string &RoleCard::getRoleCardname() const {
    return roleCardname;
}

void RoleCard::setRoleCardname(const std::string &roleCardname) {
    RoleCard::roleCardname = roleCardname;
}



int RoleCard::getRoleCardNum() {

    std :: string roleCardNames [] = {"The Contingency Planner", "Researcher", "Scientist", "Dispatcher", "Operations Expert"
            , "Medic" , "Quarantine Specialist", };
    int switchNum = 0;

    for (int i=0; i<7; i++) {

        if(roleCardNames[i].compare(this->getRoleCardname())==0){

            switchNum = i;
            //std :: cout << switchNum << std :: endl;

            break;
        }

    }
    return switchNum;
}


int RoleCard::getRoleCardVal() const {
    return roleCardVal;
}
void RoleCard::setRoleCardVal(int roleCardVal) {
    RoleCard::roleCardVal = roleCardVal;
}






void RoleCard::setRoleCardColour(const std::string& roleCardColour)
{
	this->roleCardColour = roleCardColour;
}