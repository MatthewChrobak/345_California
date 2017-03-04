//
// Created by Tse-Chun Lau on 2017-02-11.
//

#include "Role.h"


// Returns the role as a string
string Role:: getRoles(){
    return role;
}

// Takes an int value roleNumber and retrieves the string in the "roles" array at the position of roleNumber
void Role:: setRole(int roleNumber) {
    // To ensure that no 2 player gets the same role, the role is replaced by "Empty" once taken.
    // Recursive method that calls until finding a non-"Empty" element. Also, string converted to const char*.
    if (strcmp(roles[roleNumber].c_str(), "Empty") == 0){
        setRole(randomValue());
        cout << "5" << endl;
    }

    else {
        this->role = this->roles[roleNumber];
        roles[roleNumber] = "Empty";
    }
}

// Mersenne generator to generate random integers
int Role:: randomValue(){
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution< int > distribution(1,7);
    return distribution(generator) - 1;
}

Role::Role()
{
    this->role = "null";
}
