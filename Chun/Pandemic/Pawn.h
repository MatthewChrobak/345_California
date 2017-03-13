/*
 * This is the pawn class. Each pawn has a color (which will be assigned based on the player's role), and has a current
 * city (which will be implemented later on).
 */


#include <string>
#include <iostream>
#ifndef PANDEMIC6_PAWN_H
#define PANDEMIC6_PAWN_H

using namespace std;

class Pawn {

private:
    const string * colorList = new string [7] {"Teal", "Pink", "Orange", "Light Green", "Dark Green", "Brown", "White"};
    string color;
    string currentCity;

public:
    Pawn()
    {
        currentCity = "Atlanta";
    }

public:
    void setColor(string playerRole);
    string getColor();

    void setCurrentCity(string newCurrentCity);
    string getCurrentCity();

};

#endif //PANDEMIC6_PAWN_H

