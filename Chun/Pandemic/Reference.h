/*
 * This is the Reference class. It only returns the list of references when it is called.
 */

#include <iostream>
#include <string>
#ifndef PANDEMIC6_REFERENCE_H_H
#define PANDEMIC6_REFERENCE_H

using namespace std;

class Reference {

private:
    string referenceList =
            "The reference card lists the different actions you may do.\n"
                    "BASIC ACTIONS:\n"
                    "1) Drive (or Ferry)\n"
                    "Move your pawn to an adjacent city.\n"
                    "2) Direct Flight\n"
                    "Discard a card to move to the city pictured on it.\n"
                    "3) Charter Flight\n"
                    "Discard he card showing your current city and move to any city on the board.\n"
                    "4) Shuttle Flight\n"
                    "Move to a city containing a research station if your pawn is in a city containing a station.\n"
                    "SPECIAL ACTIONS:\n"
                    "5) Build a Research Station\n"
                    "Discard the card showing your current city to build a Research Station there.\n"
                    "\"Discard 5 cards of the same color to cure the disease of that color. Your pawn must be in a city containing a research station.\n"
                    "6) Discover a Cure\n"
                    "Remove a disease cube from the city your pawn occupies. If the cure has been found, remove all the cubes of that color from the city.\n"
                    "7) Treat Disease\n"
                    "Remove a disease cube from the city your pawn occupies. If the cure has been found, remove all the cubes of that color from the city.\n"
                    "8) Share Knowledge\n"
                    "Pass a card from one player to another. Both players' pawns must be in the city pictured on the card that is passed.\n\n";


public: Reference();

public:
    string getReference();

};


#endif //PANDEMIC6_REFERENCE_H
