//pixelsOccupied

#include "Board.h"
#include "boost/random.hpp"
#include "boost/generator_iterator.hpp"
#include <iomanip>
#include <random>
#include <boost/graph/connected_components.hpp>

using namespace std;
typedef MyGraph::vertex_descriptor VertexID;
typedef MyGraph::edge_descriptor EdgeID;


using namespace std;
using namespace boost;
int Board::infectionRate =0;

void Board::addCity(std::string cityName) {
    //create a temp vertex



    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<> distRed(0, 10);
    std::uniform_int_distribution<> distYellow(5, 15);
    std::uniform_int_distribution<> distGreen(10, 20);
    std::uniform_int_distribution<> distBlue(15, 25);



    int counter = 0;
    pair <int,int> tempPair;

    MyGraph::vertex_iterator vertexIt, vertexEnd;
    boost::tie(vertexIt, vertexEnd) = vertices(graph);
    //Check if the city is already in the map...iterate
    for (; vertexIt != vertexEnd; ++vertexIt) {

        if (graph[*vertexIt].getCityName().compare(cityName) == 0) {
            counter++;
            cout << graph[*vertexIt].getCityName() << " in the map. Try a different Name to add!" << endl;
            break;
        }
    }


    if(counter == 0) {
        //cout << "Adding city..." << endl;
//        Color color = blue;
        VertexID vIDTemp = add_vertex(graph);
        graph[vIDTemp].setCityName(cityName);
     //   graph[vIDTemp].setCityColor(color);

       int x= vIDTemp;
        switch(vIDTemp)
        {
            case 0 ... 11   :
                //std :: cout << " City color set to Red " << endl;
                graph[vIDTemp].setCityColor("Red");
                //add the coordinates depending on the when the vertex is added
                //shouldd be between 0,10
                tempPair.first = distRed(rng);
                tempPair.second = distRed(rng);
                graph[vIDTemp].setCoords(tempPair);



                break;
            case 12 ... 23   :
                //std :: cout << "City color set to Yellow " <<endl;
                graph[vIDTemp].setCityColor("Yellow");
                //shouldd be between 10,20

                tempPair.first = distYellow(rng);
                tempPair.second = distYellow(rng);
                graph[vIDTemp].setCoords(tempPair);
                break;
            case 24 ... 35   :
                //std :: cout << "City color set to Green " << endl;
                graph[vIDTemp].setCityColor("Green");
                //shouldd be between 20,30

                tempPair.first = distGreen(rng);
                tempPair.second = distGreen(rng);
                graph[vIDTemp].setCoords(tempPair);
                break;
            case 36 ... 47   :
                //std :: cout << "City color set to Blue " << endl;
                graph[vIDTemp].setCityColor("Blue");
                //shouldd be between 30,40

                tempPair.first = distBlue(rng);
                tempPair.second = distBlue(rng);
                graph[vIDTemp].setCoords(tempPair);
                break;
            default:
                //cout << "Into cumtom map buidling mode...no color set" << endl;
                break;
        }



        /*cout<< graph[vIDTemp].getCityName() << " added into the map with color " << graph[vIDTemp].getCityColor() <<
            "\nIt has vertexID# "<< x << ", coordinates (x,y) =  (" << graph[vIDTemp].getCoords().first
         << ", " << graph[vIDTemp].getCoords().second <<  ")"<< endl;*/

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

VertexID Board::cityExists(std::string cityName) {

    MyGraph::vertex_iterator vertexIt, vertexEnd;
    boost::tie(vertexIt, vertexEnd) = vertices(graph);
    //Check if the city is already in the map...iterate
    for (; vertexIt != vertexEnd; ++vertexIt) {
        VertexID vertexID = *vertexIt; // dereference vertexIt, get the ID
        Vertex & vertex = graph[vertexID];
        //cout << vertex.getCityName() << endl;
        if ((vertex.getCityName()).compare(cityName) ==0){

            cout << "\nFound " << cityName << endl;
            cout << "Vertex ID# "<< vertexID << endl;


            return vertexID;

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

    //cout << "\nFinding connections -" << endl;
    tie(vertexIt, vertexEnd) = vertices(graph);
    for (; vertexIt != vertexEnd; ++vertexIt) {

        tie(neighbourIt, neighbourEnd) = adjacent_vertices(*vertexIt, graph);

        if (graph[*vertexIt].getCityName().compare(cityName) == 0) {
            //cout << graph[*vertexIt].getCityName() << " in the map. Finding the connected cities now..." << endl;
            //cout << "It is connected to ->" << endl;
            for (; neighbourIt != neighbourEnd; neighbourIt++) {
                cout << graph[*neighbourIt].getCityName() << endl;

            }
        }
    }

}



void Board::infectCity(InfectionCard cityToBeInfected) {
    //find the vertexID with the given name on the infection;



    VertexID tempVert = cityExists(cityToBeInfected.getInfectionCardCity());
    int*  a = graph[tempVert].getCubeCotainer();

   cout << "Current cube of city " << graph[tempVert].getCityName() << " as follows " << endl;

    for (int i =0; i<4; i++){

       // std :: cout << a[i] << std::endl;
        if (i == 3){

            a[i]++;

        }

    }

  graph[tempVert].printCubeContainer();





    //CityInfected








}




Board::Board() {

   // cout << "Intializing a board " << endl;


}

void Board::addEdges() {
    MyGraph::vertex_iterator vertexIt, vertexEnd;
    //MyGraph::vertex_iterator vertexIt2, vertexEnd2;


    int limit = num_vertices(graph);
   // const int edgeCounter = 0;

    boost::tie(vertexIt, vertexEnd) = vertices(graph);
    //boost::tie(vertexIt2, vertexEnd2) = vertices(graph);

    //start iteration of the vertices
    for (; vertexIt != vertexEnd; ++vertexIt) {
        int edgeCounter = 0;
        VertexID vertexID = *vertexIt; // dereference vertexIt, get the ID
        Vertex &vertex = graph[vertexID];
        for (int j =0; j<limit ; j++){
            VertexID vertexID2 = j;
            Vertex &vertex2 = graph[j];

            //avoid conecting to itself
            if(vertexID == vertexID2){
                continue;
            }

            else {

                //check if the vertices are within the specific distance
                if (distance(vertex.getCoords(),vertex2.getCoords()) < vertex.getNearby()){

                    //create edge and join edge
                    EdgeID edge;
                    bool ok;
                    //pair < EdgeID, bool > p1 = boost::edge( vertexID, vertexID2, graph );
                    //pair < EdgeID, bool > p2 = boost::edge( vertexID2, vertexID, graph );

                    //if(p1.second == p2.second)  {
                        tie(edge, ok) = add_edge(vertexID, vertexID2, graph);
                        //cout << "Connected " << vertex.getCityName() << " and " << vertex2.getCityName() << endl;
                        //cout << edge << endl;
                        edgeCounter++;


                    if (edgeCounter > 4){
                        //cout << edgeCounter << endl;
                        break;
                    }

                }

                /*if (edgeCounter == 0){
                    bool ok;
                    tie(edge, ok) = add_edge(vertexID, vertexID2, graph);
                    cout << "Connected " << vertex.getCityName() << " and " << vertex2.getCityName() << endl;
                    cout << edge << endl;
                    edgeCounter++;
                    continue;
                }*/

            }

        }

    }





}

double Board::distance(pair<int, int> lhs, pair<int, int> rhs) {

    return hypot(lhs.first - rhs.first, lhs.second - rhs.second);

}

void Board::initializeCity() {
    //cout << "\nAdding multiple cities - " << endl;


    vector<string> cities
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

    for (int i = 0; i < cities.size(); i++) {

        //cout<< "ADDING CITY ->" << blueCities[i] << " to graph" << endl;
        addCity(cities[i]);


    }

}

Board::~Board() {

    //cout << "Deleting board" << endl;

}











