//
// Created by Nahian Pathan on 2017-03-28.
//

#ifndef BOARD_BOOST_PAWN_H
#define BOARD_BOOST_PAWN_H

#include <ostream>
#include "Vertex.h"
#include "Board.h"


class Pawn {
    string color;
    Vertex* currentCity;
    Board* boardForPawn;


public:
    const string &getColor() const;

    void setColor(const string &color);

    Vertex *getCurrentCity() const;

    void setCurrentCity(Vertex *currentCity);

    Board *getBoardForPawn() const;

    void setBoardForPawn(Board *boardForPawn);

    Pawn();

    virtual ~Pawn();

    friend ostream &operator<<(ostream &os, const Pawn &pawn);

    Pawn(Board *boardForPawn);
};


#endif //BOARD_BOOST_PAWN_H
