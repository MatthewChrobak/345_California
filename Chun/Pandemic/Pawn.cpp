//
// Created by Tse-Chun Lau on 2017-02-16.
//

#include "Pawn.h"

//Assigns a color to the Pawn, based on the player's role
void Pawn:: setColor(string playerRole){
    if(playerRole == "Contingency Planner")
    {
        color = colorList[0];
    }

    else if(playerRole == "Dispatcher")
    {
        color = colorList[1];
    }

    else if(playerRole == "Medic")
    {
        color = colorList [2];
    }

    else if(playerRole == "Operations Expert")
    {
        color = colorList [3];
    }

    else if (playerRole == "Quarantine Specialist")
    {
        color = colorList [4];
    }

    else if (playerRole == "Researcher")
    {
        color = colorList [5];
    }

    else{
        color = colorList [6];
    }

};
string Pawn:: getColor(){
    return color;
};

void Pawn:: setCurrentCity(string newCurrentCity){
    currentCity = newCurrentCity;
};

string Pawn:: getCurrentCity(){
    return currentCity;
};
