//
// Created by Nahian Pathan on 2017-03-20.
//

#include "Vertex.h"

const std::string &Vertex::getCityName() const {
    return cityName;
}

void Vertex::setCityName(const std::string &cityName) {
    Vertex::cityName = cityName;
}
