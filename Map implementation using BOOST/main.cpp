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

//    board.graph;
    vector<VertexID> v1;

    VertexID vID1 = add_vertex(board.graph);
    VertexID vID2= add_vertex(board.graph);
    VertexID vID3= add_vertex(board.graph);


    board.graph[vID1].setCityName("Montreal");
    board.graph[vID2].setCityName("Atlanta");
    board.graph[vID3].setCityName("Tunis");



    v1.push_back(vID1);
    v1.push_back(vID2);
    EdgeID edge;
    bool ok;
    boost::tie(edge, ok) = boost::add_edge(vID1,vID2, board.graph);
    boost::tie(edge, ok) = boost::add_edge(vID1,vID3, board.graph); // boost::add_edge gives a std::pair<EdgeID,bool>. It's complicated to write, so boost::tie does it for us.

    // boost::add_edge gives a std::pair<EdgeID,bool>. It's complicated to write, so boost::tie does it for us.
    if (ok)  // make sure there wasn't any error (duplicates, maybe)
        board.graph[edge].setDistance(4);


    //find vertex with a cityname!
    MyGraph::vertex_iterator vertexIt, vertexEnd;
    boost::tie(vertexIt, vertexEnd) = vertices(board.graph);
    for (; vertexIt != vertexEnd; ++vertexIt){
        VertexID vertexID = *vertexIt; // dereference vertexIt, get the ID
        Vertex & vertex = board.graph[vertexID];
        //cout << vertex.getCityName() << endl;
        if ((vertex.getCityName()).compare("Montreal") ==0){

            cout << " hello there " << endl;

        } 
    }

    //find neigbours!
    MyGraph::adjacency_iterator neighbourIt, neighbourEnd;
    MyGraph::vertex_iterator i, end;
    //MyGraph::vertex_iterator vertexIt, vertexEnd;

    boost::tie(vertexIt, vertexEnd) = vertices(board.graph);
    for (; vertexIt != vertexEnd; ++vertexIt) {
        boost::tie(neighbourIt, neighbourEnd) = adjacent_vertices(*vertexIt, board.graph);
        cout << board.graph[*vertexIt].getCityName() << " Connected to ->"<< endl;
        for (; neighbourIt != neighbourEnd; neighbourIt++) {

            cout << board.graph[*neighbourIt].getCityName() << endl;

        }
    }


    //MyGraph::vertex_iterator vertexIt, vertexEnd;
    boost::tie(vertexIt, vertexEnd) = vertices(board.graph);

    for (; vertexIt != vertexEnd; ++vertexIt) {

        cout << "-------------------------" << endl;
        board.graph[*vertexIt];

    }

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

        cout<< "ADDING CITY ->" << blueCities[i] << " to graph" << endl;
        board.addCity(blueCities[i]);


    }






    boost :: tie (edge, ok) = add_edge(vertex(0,board.graph),vertex(5,board.graph),board.graph);
    boost :: tie (edge, ok) = add_edge(vertex(0,board.graph),vertex(6,board.graph),board.graph);
    boost :: tie (edge, ok) = add_edge(vertex(0,board.graph),vertex(7,board.graph),board.graph);






    cout << num_vertices(board.graph) << endl;







    for (; vertexIt != vertexEnd; ++vertexIt) {

        boost::tie(neighbourIt, neighbourEnd) = adjacent_vertices(*vertexIt, board.graph);
        cout << board.graph[*vertexIt].getCityName() << " Connected to ->"<< endl;
        for (; neighbourIt != neighbourEnd; neighbourIt++) {

            cout << board.graph[*neighbourIt].getCityName() << endl;

        }
    }

    board.printMapContent();

   // MyGraph::vertex_iterator vertexIt, vertexEnd;
    boost::tie(vertexIt, vertexEnd) = vertices(board.graph);
    for (; vertexIt != vertexEnd; ++vertexIt){
        VertexID vertexID = *vertexIt; // dereference vertexIt, get the ID
        Vertex & vertex = board.graph[vertexID];
        //cout << vertex.getCityName() << endl;
        if ((vertex.getCityName()).compare("Atlanta") ==0){

            //SHOULD GIVE TWO ATALNTAS!
            cout << " Found Atanta! " << endl;
            cout << vertexID << endl;

        } 
    }


    cout << "bUE" << endl;
    //boost::tie(neighbourIt, neighbourEnd) = adjacent_vertices( vID1, graph );

  //  MyGraph::vertex_iterator i, end;

   /* for (boost::tie(i, end) = boost::vertices(graph); i != end; i++) {
       // AdjacencyIterator ai, a_end;
*/

       // }
   // }




















    return 0;
}
