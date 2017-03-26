//pixelsOccupied


#ifndef BOARD_BOOST_VERTEX_H
#define BOARD_BOOST_VERTEX_H

#include <iostream>
#include "Color.h"
#include "vector"
using namespace std;
class Vertex {

    std :: string cityName;
    std :: string cityColor;
    constexpr static double nearby = 5;
    pair<int, int> coords;
public:
    static const double getNearby();

    const pair<int, int> &getCoords() const;

    void setCoords( pair<int, int> &coords);

public:
    const std::string &getCityColor() const;

    void setCityColor(const std::string &cityColor);

private:
    int* cubeCotainer = new int[4];
    bool hasResearchCentre;


public:

    Vertex();

    bool isHasResearchCentre() const;

    void setHasResearchCentre(bool hasResearchCentre);

    const std::string &getCityName() const;

    void setCityName(const std::string &cityName);

    int *getCubeCotainer() const;

    void setCubeCotainer(int *cubeCotainer);

    void printCubeContainer();


};


#endif //BOARD_BOOST_VERTEX_H
