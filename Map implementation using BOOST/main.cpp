//pixelsOccupied

#include <boost/graph/adjacency_list.hpp>
#include <iostream>
using namespace boost;
using namespace std;

#include "Vertex.h"
#include "Edge.h"
#include "Board.h"
#include <boost/graph/graphviz.hpp>
#include <boost/graph/erdos_renyi_generator.hpp>
#include <boost/random.hpp>
#include <boost/graph/connected_components.hpp>

typedef MyGraph::vertex_descriptor VertexID;
typedef MyGraph::edge_descriptor EdgeID;
//typedef boost::erdos_renyi_iterator<boost::minstd_rand, MyGraph> ERGen;



int main() {


    Board board;


    //int x = vID2;

    cout << "\nAdding multiple cities - " << endl;
    vector<string> blueCities
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
                    "Montreal",
                    "Washington",
                    "Bogota",       // yellowCities[0]
                    "Buenos Aires",
                    "Johannesburg",
                    "Khartoum",
                    "Kinshasa",     // yellowCities[4]
                    "Lagos",
                    "Lima",
                    "Los Angeles",
                    "Mexico",  // yellowCities[8]
                    "Miami",
                    "Santiago",
                    "Sao Paulo",
                    "Algiers",      // blackCities[0]
                    "Baghdad",
                    "Cairo",
                    "Chennai",
                    "Delhi",        // blackCities[4]
                    "Istanbul",
                    "Karachi",
                    "Kolkata",
                    "Moscow",       // blackCities[8]
                    "Mumbai",
                    "Riyadh",
                    "Tehran",
                    "Bangkok",      // redCities[0]
                    "Beijing",
                    "Ho Chi Minh",
                    "Hong Kong",
                    "Jakarta",      // redCities[4]
                    "Manila",
                    "Osaka",
                    "Seoul",
                    "Shanghai",     // redCities[8]
                    "Sydney",
                    "Taipei",
                    "Tokyo"
            };

    for (int i = 0; i < blueCities.size(); i++) {

        //cout<< "ADDING CITY ->" << blueCities[i] << " to graph" << endl;
        board.addCity(blueCities[i]);


    }







    cout << "\nTotal number vertices ->" << num_vertices(board.getGraph()) << endl;
    cout << "\nTotal number edges ->" << num_edges(board.getGraph()) << endl;




    board.printMapContent();
    board.searchAdjecentCities("Montreal");
    board.cityExists("Atlanta");

    board.addEdges();

    board.searchAdjecentCities("Montreal");
    board.cityExists("Atlanta");


    //write_graphviz(cout, board.getGraph());
    cout << "\nTotal number vertices ->" << num_vertices(board.getGraph()) << endl;
    cout << "\nTotal number edges ->" << num_edges(board.getGraph()) << endl;


    std::vector<int> component(num_vertices(board.getGraph()));
    int num = connected_components(board.getGraph(), &component[0]);

    std::vector<int>::size_type i;
    cout << "Total number of components: " << num << endl;
    /*for (i = 0; i != component.size(); ++i){
        cout << "Vertex " << i <<" is in component " << component[i] << endl;
    cout << endl;
    }*/
    //board.infectCity("Montreal");

    string response;
    cout << "Find the connected cities" << endl;
    getline (std::cin,response);



    int counter =0;
    while (counter<10){


        cout << "Try another one!" << endl;
        getline (std::cin,response);
        board.searchAdjecentCities(response);
        counter++;

    }



    cout << "\nProgram ended" << endl;
    return 0;

}
   // std :: deque <InfectionCard> ic;
   // InfectionCard icc;
   // ic.push_back(icc);

//    icc.useInfectionCard(board);



  //  cout << "\nTotal number vertices ->"<<  num_vertices(board.getGraph()) << endl;

/*
    boost::minstd_rand gen;
    // Create graph with 100 nodes and edges with probability 0.05

    MyGraph m(ERGen(gen, 100, 0.005), ERGen(), 100);
    cout << num_vertices(m) << endl;
    cout << num_edges(m) << endl;
*/

    //write_graphviz(cout, board.getGraph());
   // print_dependencies(std::cout, board.getGraph(), get(vertex_name, board.getGraph()), get(edge_name, board.getGraph()) );



   // return 0;
    //    board.infectCity("Montreal");





///Search if the city exists
/*
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
*/


///USED TO SEARCH ALL THE CITIES AND ALL THE CONNECTIONS
/*  cout << "\nFinding connections again, ONLY MONTREAL [0] is connected to manyCities for now" << endl;

    boost::tie(vertexIt, vertexEnd) = vertices(board.getGraph());
    for (; vertexIt != vertexEnd; ++vertexIt) {
        boost::tie(neighbourIt, neighbourEnd) = adjacent_vertices(*vertexIt, board.getGraph());
        cout << board.getGraph()[*vertexIt].getCityName() << " Connected to ->"<< endl;
        for (; neighbourIt != neighbourEnd; neighbourIt++) {

            cout << board.getGraph()[*neighbourIt].getCityName() << endl;

        }
    }*/






///More codes...might be useful later
/*

    //find vertex with a cityname!
    MyGraph::vertex_iterator vertexIt, vertexEnd;
    */
/*boost::tie(vertexIt, vertexEnd) = vertices(board.getGraph());
    for (; vertexIt != vertexEnd; ++vertexIt){
        VertexID vertexID = *vertexIt; // dereference vertexIt, get the ID
        Vertex & vertex = board.getGraph()[vertexID];
        //cout << vertex.getCityName() << endl;
        if ((vertex.getCityName()).compare("Montreal") ==0){

            cout << " hello there " << endl;

        } // Gotcha
    }*//*


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
*/




