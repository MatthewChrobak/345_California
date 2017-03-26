//
// Created by Nahian Pathan on 2017-03-22.
//

#include "InfectionCard.h"

const std::string &InfectionCard::getInfectionCardCity() const {
    return infectionCardCity;
}

void InfectionCard::setInfectionCardCity(const std::string &infectionCardCity) {
    InfectionCard::infectionCardCity = infectionCardCity;
}

const std::string &InfectionCard::getInfectionCardColor() const {
    return infectionCardColor;
}

void InfectionCard::setInfectionCardColor(const std::string &infectionCardColor) {
    InfectionCard::infectionCardColor = infectionCardColor;
}

/*
void InfectionCard::useInfectionCard(Board &board) {

        std::string tempInfectionCard = infectionCardCity;
        VertexID tempVertex = board.cityExists(tempInfectionCard);
        Vertex & vertex = board.getGraph()[tempVertex];

    std ::vector <int> tempVector = vertex.getCubeCotainer();

    tempVector[3]++;

    vertex.setCubeCotainer(tempVector);


}
*/
