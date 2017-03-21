//pixelsOccupied

#include "Board.h"
typedef MyGraph::vertex_descriptor VertexID;
typedef MyGraph::edge_descriptor EdgeID;


using namespace std;
void Board::addCity(std::string cityName) {

    VertexID vIDTemp = add_vertex(graph);

//        vertexVector.push_back(vIDTemp);

        //VertexID vIDTemp = add_vertex(graph);
        graph[vIDTemp].setCityName(cityName);
        //graph[vIDTemp].setCityValue(vIDTemp);

        cout << "Adding cities" << endl;





}



void Board::printMapContent() {

    cout << "inside print method!" << endl;

    MyGraph::vertex_iterator vertexIt, vertexEnd;
    boost::tie(vertexIt, vertexEnd) = vertices(graph);

    for (; vertexIt != vertexEnd; ++vertexIt) {

        cout << graph[*vertexIt].getCityName() << " in the map" <<endl;

    }



}

MyGraph &Board::getGraph() {
    return graph;
}

void Board::setGraph(MyGraph &graph) {
    Board::graph = graph;
}
