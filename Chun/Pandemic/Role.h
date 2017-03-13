/*
 * This is the Role class. A player is randomly assigned a role.
 */

#include <iostream>
#include <cstring>
#include <string>
#include <random>
#ifndef PANDEMIC6_ROLE_H
#define PANDEMIC6_ROLE_H


using namespace std;


class Role{

private:
    string* roles = new string[7]{"Contingency Planner", "Dispatcher", "Medic", "Operations Expert", "Quarantine Specialist", "Researcher", "Scientist"};
    //string * roles = new string [7] {"Empty","Empty","Empty","Empty","Empty","Empty","empty" }; //FOR TESTING THE ROLE CLASS

    string role;

public:
    Role();

public:
    string getRoles();
    void setRole(int roleNumber);
    int randomValue();

};

#endif //PANDEMIC6_ROLE_H
