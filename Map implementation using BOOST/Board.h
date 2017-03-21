//pixelsOccupied

#ifndef BOARD_BOOST_BOARD_H
#define BOARD_BOOST_BOARD_H
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/astar_search.hpp>
#include <iostream>
#include "Vertex.h"
#include "Edge.h"
#include "vector"
using namespace boost;
typedef boost::adjacency_list<  // adjacency_list is a template depending on :
boost::listS,               //  The container used for egdes : here, std::list.
boost::vecS,                //  The container used for vertices: here, std::vector.
boost::directedS,           //  directed or undirected edges ?.
Vertex,                     //  The type that describes a Vertex.
Edge                        //  The type that describes an Edge
> MyGraph;
typedef MyGraph::vertex_descriptor VertexID;



class Board {
private:
     MyGraph graph;
public:
     MyGraph &getGraph()  ;

    void setGraph( MyGraph &graph);

public:
    void addCity(std:: string cityName);
    void printMapContent();
    bool cityExists(std :: string cityName);
    void searchAdjecentCities(std:: string cityName);
    void searchAdjecentCities(MyGraph mg);

};


#endif //BOARD_BOOST_BOARD_H
