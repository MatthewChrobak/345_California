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

    std :: cout << "Initiated -> " << this->getRoleCardname() <<"\nIts set to #" << this->getRoleCardVal() <<
                "\nRolecard has the color -> " << this->getRoleCardColour() <<std :: endl;

}

RoleCard::~RoleCard() {

    std :: cout << "INSIDE RC DESTRUCTOR "<< std :: endl;



}

RoleCard::RoleCard() {}

 std::ostream &operator<<(std::ostream &os, const RoleCard &card) {
    os << "rrrroleCardname: " << card.getRoleCardname();
    return os;
}

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



void RoleCard::roleCardDesc() {

    int switchto = this->getRoleCardVal();

    switch (switchto) {
        case 0:
            std::cout << "The Contingency Planner"
                    "\nPickup 1 event card from the discarded pile. Place itDo not add to total cards in hand."
                    "\nWhen that card is played, remove it from the game. +1 action" << std::endl;
            break;
        case 1:

            std::cout
                    << "\nResearcher\nAs an action, the Researcher may give any City card from her hand to another player in the same city as her, "
                            "\nwithout this card having to match her city. "
                            "\nThe transfer must be from her hand to the other player’s hand, but it can occur on either player’s turn."
                    << std::endl;
            break;

        case 2:

            std::cout
                    << "Scientist\n-Needs only 4 (not 5) City cards of the same disease color to Discover a Cure for that disease."
                    << std::endl;
            break;
        case 3:

            std::cout << "Dispatcher\n The Dispatcher may, as an action, either:\n"
                    "Move any pawn, it its owner agrees, to any city containing another pawn, or \n"
                    "Move another player's pawn, it its owner agrees, as if it were his own" << std::endl;
            break;
        case 4:

            std::cout << "Operations Expert\nAs an action \n"
                    "-Build a research station in his current city without discarding(or using) a city card, or"
                    "\n Once per turn, move from a research station to any city " << std::endl;
            break;
        case 5:

            std::cout
                    << "Medic\n-The Medic removes all cubes, not 1, of the same color when doing the Treat Disease action.\n"
                            "-If a disease has been cured, he automatically removes all cubes of that color from a city, simply by entering it or being there. "
                            "\nThis does not take an action." << std::endl;
            break;
        case 6:

            std::cout
                    << "\nQuarantine Specialist\n"
                            "The Quarantine Specialist prevents both outbreaks and the placement of disease cubes in the\n"
                            "city she is in and all cities connected to that city.\n"
                            "She does not affect cubes placed during setup."
                    << std::endl;
            break;


        default:
            std::cout << "DEFAULT SWITCH STATEMENT!" << std::endl;
            break;


    }


}

void RoleCard::useRoleCard() {


    int switchto = this->getRoleCardVal();

    switch (switchto) {
        case 0:
            std::cout << "You are - The Contingency Planner " << std::endl;
            this->useTheContingencyPlanner();
            break;
        case 1:

            std::cout << "You are - Researcher " << std::endl;
            this->useResearcher();
            break;

        case 2:

            std::cout << "You are - Scientist " << std::endl;
            this->useScientist();
            break;
        case 3:

            std::cout << "You are - Dispatcher " << std::endl;
            this->useDispatcher();
            break;
        case 4:

            std::cout << "You are - Operations Expert " << std::endl;
            this->useOperationsExpert();
            break;
        case 5:

            std::cout << "You are - Medic " << std::endl;
            this->useMedic();
            break;
        case 6:

            std::cout << "You are - Containment Specialist " << std::endl;
            this->useContainmentSpecialist();
            break;


        default:
            std::cout << "DEFAULT SWITCH STATEMENT!" << std::endl;
            break;

    }

    }

void RoleCard::useTheContingencyPlanner() {

}

void RoleCard::useResearcher() {

}

void RoleCard::useScientist() {
    std :: cout << "Needs only 4 (not 5) City cards of the same disease color to Discover a Cure for that disease.\n"
                << "Please use \"Discover Cure\" (counts as 1 action) to see the effects" << std :: endl;

}

void RoleCard::useDispatcher() {

}

void RoleCard::useOperationsExpert() {

}

void RoleCard::useMedic() {

}

void RoleCard::useContainmentSpecialist() {

}

const std::string &RoleCard::getRoleCardColour() const {
    return roleCardColour;
}

void RoleCard::setRoleCardColour(const std::string &roleCardColour) {
    RoleCard::roleCardColour = roleCardColour;
}
