#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/astar_search.hpp>
#include <iostream>
using namespace boost;
using namespace std;

#include "vector"
#include "Vertex.h"
#include "Edge.h"
#include "Board.h"

typedef MyGraph::vertex_descriptor VertexID;
typedef MyGraph::edge_descriptor EdgeID;



int main()
{
    //MyGraph graph;


    Board board;

//    board.getGraph();
    vector<VertexID> v1;

    VertexID vID1 = add_vertex(board.getGraph());
    VertexID vID2= add_vertex(board.getGraph());
    VertexID vID3= add_vertex(board.getGraph());


    board.getGraph()[vID1].setCityName("Montreal");
    board.getGraph()[vID2].setCityName("Atlanta");
    board.getGraph()[vID3].setCityName("Tunis");



    v1.push_back(vID1);
    v1.push_back(vID2);
    EdgeID edge;
    bool ok;
    boost::tie(edge, ok) = boost::add_edge(vID1,vID2, board.getGraph());
    boost::tie(edge, ok) = boost::add_edge(vID1,vID3, board.getGraph()); // boost::add_edge gives a std::pair<EdgeID,bool>. It's complicated to write, so boost::tie does it for us.

    // boost::add_edge gives a std::pair<EdgeID,bool>. It's complicated to write, so boost::tie does it for us.
    if (ok)  // make sure there wasn't any error (duplicates, maybe)
        board.getGraph()[edge].setDistance(4);


    //find vertex with a cityname!
    MyGraph::vertex_iterator vertexIt, vertexEnd;
    boost::tie(vertexIt, vertexEnd) = vertices(board.getGraph());
    for (; vertexIt != vertexEnd; ++vertexIt){
        VertexID vertexID = *vertexIt; // dereference vertexIt, get the ID
        Vertex & vertex = board.getGraph()[vertexID];
        //cout << vertex.getCityName() << endl;
        if ((vertex.getCityName()).compare("Montreal") ==0){

            cout << " hello there " << endl;

        } // Gotcha
    }

    //find neigbours!
    MyGraph::adjacency_iterator neighbourIt, neighbourEnd;
    MyGraph::vertex_iterator i, end;
    //MyGraph::vertex_iterator vertexIt, vertexEnd;

    cout << "\nFinding connections -" << endl;
    boost::tie(vertexIt, vertexEnd) = vertices(board.getGraph());
    for (; vertexIt != vertexEnd; ++vertexIt) {
        boost::tie(neighbourIt, neighbourEnd) = adjacent_vertices(*vertexIt, board.getGraph());
        cout << board.getGraph()[*vertexIt].getCityName() << " Connected to ->"<< endl;
        for (; neighbourIt != neighbourEnd; neighbourIt++) {

            cout << board.getGraph()[*neighbourIt].getCityName() << endl;

        }
    }


    //MyGraph::vertex_iterator vertexIt, vertexEnd;

    int x = vID2;
    cout << x << endl;

    vector <string> blueCities
            {
                    "Atlanta",      // blueCities[0]
                    "Chicago",
                    "Essen",
                    "London",
                    "Madrid",       // blueCities[4]
                    "Milan",
                    "New York",
                    "Paris",
                    "San Francisco",// blueCities [8]
                    "St Petersburg",
                    "Montreal-2",
                    "Washington"
            };

    for (int i=0; i<12; i++){

        //cout<< "ADDING CITY ->" << blueCities[i] << " to graph" << endl;
        board.addCity(blueCities[i]);


    }






    boost :: tie (edge, ok) = add_edge(vertex(0,board.getGraph()),vertex(5,board.getGraph()),board.getGraph());
    boost :: tie (edge, ok) = add_edge(vertex(0,board.getGraph()),vertex(6,board.getGraph()),board.getGraph());
    boost :: tie (edge, ok) = add_edge(vertex(0,board.getGraph()),vertex(7,board.getGraph()),board.getGraph());






    cout << "\nTotal number vertices ->"<<  num_vertices(board.getGraph()) << endl;







    cout << "\nFinding connections again, ONLY MONTREAL [0] is connected to manyCities for now" << endl;

    boost::tie(vertexIt, vertexEnd) = vertices(board.getGraph());
    for (; vertexIt != vertexEnd; ++vertexIt) {
        boost::tie(neighbourIt, neighbourEnd) = adjacent_vertices(*vertexIt, board.getGraph());
        cout << board.getGraph()[*vertexIt].getCityName() << " Connected to ->"<< endl;
        for (; neighbourIt != neighbourEnd; neighbourIt++) {

            cout << board.getGraph()[*neighbourIt].getCityName() << endl;

        }
    }


    cout << "\nPrinting all the current Cities" << endl;
    board.printMapContent();

   // MyGraph::vertex_iterator vertexIt, vertexEnd;
    boost::tie(vertexIt, vertexEnd) = vertices(board.getGraph());
    for (; vertexIt != vertexEnd; ++vertexIt){
        VertexID vertexID = *vertexIt; // dereference vertexIt, get the ID
        Vertex & vertex = board.getGraph()[vertexID];
        //cout << vertex.getCityName() << endl;
        if ((vertex.getCityName()).compare("Atlanta") ==0){

            //SHOULD GIVE TWO ATALNTAS!
            cout << " Found Atanta! " << endl;
            cout << vertexID << endl;

        } // Gotcha
    }


    cout << "bUE" << endl;





    return 0;
}