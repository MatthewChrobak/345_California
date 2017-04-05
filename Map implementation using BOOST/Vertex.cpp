//pixelsOccupied

#include "Vertex.h"

const std::string &Vertex::getCityName() const {
    return cityName;
}

void Vertex::setCityName(const std::string &cityName) {
    Vertex::cityName = cityName;
}


bool Vertex::isHasResearchCentre() const {
    return hasResearchCentre;
}

void Vertex::setHasResearchCentre(bool hasResearchCentre) {
    Vertex::hasResearchCentre = hasResearchCentre;
}

int *Vertex::getCubeCotainer() const {
    return cubeCotainer;
}

void Vertex::setCubeCotainer(int *cubeCotainer) {
    Vertex::cubeCotainer = cubeCotainer;
}

Vertex::Vertex() {
    //intializing cube counter
    for (int i =0; i<4; i++){
        cubeCotainer[i] =0;
    }


}

void Vertex::printCubeContainer() {

    for (int i =0; i<4; i++){
       // std::cout<< cubeCotainer[i] << std::endl;

            switch(i)
            {
                case 0   : std :: cout << "Red# " << cubeCotainer[0] <<"\n"; break;
                case 1   : std :: cout << "Yellow# " << cubeCotainer[1] <<"\n"; break;
                case 2   : std :: cout << "Green# " << cubeCotainer[2]<<"\n"; break;
                case 3   : std :: cout << "Blue# " << cubeCotainer[3]<<"\n"; break;
                default    : break;
            }


    }

}

const std::string &Vertex::getCityColor() const {
    return cityColor;
}

void Vertex::setCityColor(const std::string &cityColor) {
    Vertex::cityColor = cityColor;
}

const double Vertex::getNearby() {
    return nearby;
}

const pair<int, int> &Vertex::getCoords() const {
    return coords;
}

void Vertex::setCoords( pair<int, int> &coords) {
    Vertex::coords = coords;
}

ostream &operator<<(ostream &os, const Vertex &vertex) {
    os << "cityName: " << vertex.cityName << " cityColor: " << vertex.cityColor << " cubeCotainer: " << vertex.cubeCotainer << " hasResearchCentre: " << vertex.hasResearchCentre;
    return os;
}


