//
// Created by Nahian Pathan on 2017-03-16.
//

#ifndef PANDEMIC_V2_CITY_H
#define PANDEMIC_V2_CITY_H

#include "iostream"

class City {
private:
    std :: string cityName;
    std :: string cityColour;
    //Cube cube;
    bool isResearchCentre;
public:
    City(const std::string &cityName);

    virtual ~City();

};


#endif //PANDEMIC_V2_CITY_H
