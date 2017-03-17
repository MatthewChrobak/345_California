/*
COMMON PART (PLAYER CLASS)
DISTINCT PART -> ROLE CARD AND REFERENCE CARD CLASSES.
*/
#include <iostream>
#include "RoleCard.h"

std::string RoleCard::roleCardNames[7] = { "The Contingency Planner", "Researcher", "Scientist", "Dispatcher", "Operations Expert", "Medic", "Quarantine Specialist", };


RoleCard::RoleCard(const std::string &roleCardname) : roleCardname(roleCardname)
{
    int roleValue = this->getRoleCardNum();
    this->setRoleCardVal(roleValue);

	this->setRoleCardColour((RoleCardColors)roleValue);
}

RoleCard::~RoleCard() {}

RoleCard::RoleCard() {}

const std::string &RoleCard::getRoleCardname() const {
    return roleCardname;
}

void RoleCard::setRoleCardname(const std::string &roleCardname) {
    this->roleCardname = roleCardname;
}

int RoleCard::getRoleCardNum()
{
	for (int i = 0; i < 7; i++) {
		if (roleCardNames[i].compare(this->getRoleCardname()) == 0) {
			return i;
		}
	}

	return -1;
}


int RoleCard::getRoleCardVal() const {
    return this->roleCardVal;
}
void RoleCard::setRoleCardVal(int roleCardVal) {
    this->roleCardVal = roleCardVal;
}


void RoleCard::setRoleCardColour(const RoleCardColors& roleCardColour)
{
	this->roleCardColour = roleCardColour;
}

RoleCardColors RoleCard::getRoleCardColour() const
{
	return roleCardColour;
}