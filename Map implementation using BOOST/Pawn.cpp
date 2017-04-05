//
// Created by Nahian Pathan on 2017-03-28.
//

#include "Pawn.h"

const string &Pawn::getColor() const {
    return color;
}

void Pawn::setColor(const string &color) {
    Pawn::color = color;
}

Vertex *Pawn::getCurrentCity() const {
    return currentCity;
}

void Pawn::setCurrentCity(Vertex *currentCity) {
    Pawn::currentCity = currentCity;
}

Pawn::Pawn() {



}

Pawn::~Pawn() {

}

ostream &operator<<(ostream &os, const Pawn &pawn) {
    os << "color: " << pawn.color << " currentCity: " << pawn.currentCity;
    return os;
}

Pawn::Pawn(Board *boardForPawn) : boardForPawn(boardForPawn) {

    cout << "Intiating pawn" << endl;

    color = "Blue";
    VertexID temp;
    temp =boardForPawn->cityExists("Atlanta");
    cout << temp << endl;
    Vertex *defaultAtlanta = &boardForPawn->getGraph()[temp];
    currentCity = defaultAtlanta;


}

Board *Pawn::getBoardForPawn() const {
    return boardForPawn;
}

void Pawn::setBoardForPawn(Board *boardForPawn) {
    Pawn::boardForPawn = boardForPawn;
}
