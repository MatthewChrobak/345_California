//pixelsOccupied

#ifndef BOARD_BOOST_BOARD_H
#define BOARD_BOOST_BOARD_H
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/astar_search.hpp>
#include <iostream>
#include "Vertex.h"
#include "Edge.h"
#include "InfectionCard.h"
#include <vector>
#include <deque>
using namespace boost;
typedef adjacency_list<  // adjacency_list is a template depending on :
listS,               //  The container used for egdes : here, std::list.
vecS,                //  The container used for vertices: here, std::vector.
directedS,           //  directed or undirected edges ?.
Vertex,                     //  The type that describes a Vertex.
Edge                        //  The type that describes an Edge
> MyGraph;

typedef MyGraph::vertex_descriptor VertexID;



class Board {
private:

     //board contains a map
     MyGraph graph;
    //infection rate marker
    static int infectionRate;
    //std :: deque <InfectionCard> infectionCardQue;
public:

    MyGraph &getGraph()  ;

    void setGraph( MyGraph &graph);

    Board();

    virtual ~Board();

    void initializeCity();
    void addCity(std:: string cityName);
    void printMapContent();
    VertexID cityExists(std :: string cityName);
    void searchAdjecentCities(std:: string cityName);
    void searchAdjecentCities(MyGraph mg);
    void infectCity(InfectionCard cityToBeInfected);
    double distance(pair<int, int> lhs, pair<int, int> rhs);
    void addEdges();


};


#endif //BOARD_BOOST_BOARD_H
