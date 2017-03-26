//
// Created by Nahian Pathan on 2017-03-22.
//

#ifndef BOARD_BOOST_INFECTIONCARD_H
#define BOARD_BOOST_INFECTIONCARD_H

#include "iostream"
class InfectionCard {

    std::string infectionCardCity;
    std::string infectionCardColor;
public:
    const std::string &getInfectionCardColor() const;

    void setInfectionCardColor(const std::string &infectionCardColor);

public:
    const std::string &getInfectionCardCity() const;

    void setInfectionCardCity(const std::string &infectionCardCity);

   // void useInfectionCard(Board &board);

};


#endif //BOARD_BOOST_INFECTIONCARD_H
