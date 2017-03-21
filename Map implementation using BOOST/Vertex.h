//pixelsOccupied


#ifndef BOARD_BOOST_VERTEX_H
#define BOARD_BOOST_VERTEX_H

#include <iostream>

class Vertex {

    std :: string cityName;
public:
    const std::string &getCityName() const;

    void setCityName(const std::string &cityName);

};


#endif //BOARD_BOOST_VERTEX_H
