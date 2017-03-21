//pixelsOccupied

#include "Board.h"
typedef MyGraph::vertex_descriptor VertexID;
typedef MyGraph::edge_descriptor EdgeID;


using namespace std;
void Board::addCity(std::string cityName) {
    //create a temp vertex

    int counter = 0;

    MyGraph::vertex_iterator vertexIt, vertexEnd;
    boost::tie(vertexIt, vertexEnd) = vertices(graph);
    //Check if the city is already in the map...iterate
    for (; vertexIt != vertexEnd; ++vertexIt) {

        if (graph[*vertexIt].getCityName().compare(cityName) == 0) {
            counter++;
            cout << graph[*vertexIt].getCityName() << " in the map. Try a different Name to add!" << endl;
        }
    }


    if(counter == 0) {
        VertexID vIDTemp = add_vertex(graph);
        graph[vIDTemp].setCityName(cityName);
        cout << "Adding cities" << endl;
        //cout << " hello there " << endl;
    }

}



void Board::printMapContent() {

    cout << "\nPrinting all the current Cities" << endl;

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

bool Board::cityExists(std::string cityName) {

    MyGraph::vertex_iterator vertexIt, vertexEnd;
    boost::tie(vertexIt, vertexEnd) = vertices(graph);
    //Check if the city is already in the map...iterate
    for (; vertexIt != vertexEnd; ++vertexIt) {
        VertexID vertexID = *vertexIt; // dereference vertexIt, get the ID
        Vertex & vertex = graph[vertexID];
        //cout << vertex.getCityName() << endl;
        if ((vertex.getCityName()).compare(cityName) ==0){

            //SHOULD GIVE TWO ATALNTAS!
            cout << "\nFound " << cityName << endl;
            cout << "Vertex ID# "<< vertexID << endl;
            return true;
        } // Gotcha
    }


return false;
}

void Board::searchAdjecentCities(MyGraph mg) {

  /*  cout << "\nFinding connections -" << endl;
    boost::tie(vertexIt, vertexEnd) = vertices(board.getGraph());
    for (; vertexIt != vertexEnd; ++vertexIt) {
        boost::tie(neighbourIt, neighbourEnd) = adjacent_vertices(*vertexIt, board.getGraph());
        cout << board.getGraph()[*vertexIt].getCityName() << " Connected to ->"<< endl;
        for (; neighbourIt != neighbourEnd; neighbourIt++) {

            cout << board.getGraph()[*neighbourIt].getCityName() << endl;

        }
    }*/

}

void Board::searchAdjecentCities(std::string cityName) {

    MyGraph::vertex_iterator vertexIt, vertexEnd;
    MyGraph::adjacency_iterator neighbourIt, neighbourEnd;

    cout << "\nFinding connections -" << endl;
    tie(vertexIt, vertexEnd) = vertices(graph);
    for (; vertexIt != vertexEnd; ++vertexIt) {

        tie(neighbourIt, neighbourEnd) = adjacent_vertices(*vertexIt, graph);

        if (graph[*vertexIt].getCityName().compare(cityName) == 0) {
            cout << graph[*vertexIt].getCityName() << " in the map. Finding the connected cities now..." << endl;
            cout << "It is connected to ->" << endl;
            for (; neighbourIt != neighbourEnd; neighbourIt++) {
                cout << graph[*neighbourIt].getCityName() << endl;

            }
        }
    }

}
