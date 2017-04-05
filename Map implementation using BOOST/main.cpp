//pixelsOccupied

#include <boost/graph/adjacency_list.hpp>
#include <iostream>
using namespace boost;
using namespace std;

#include "Player.h"
#include <boost/graph/graphviz.hpp>
#include <boost/graph/erdos_renyi_generator.hpp>
#include <boost/random.hpp>
#include <boost/graph/connected_components.hpp>
#include "PandemicEngine.h"
#include "PlayerRoleCard.h"

typedef MyGraph::vertex_descriptor VertexID;
typedef MyGraph::edge_descriptor EdgeID;

using namespace boost;


int main() {


    PandemicEngine* pe = new PandemicEngine();

    cout << "\nTotal number vertices ->" << num_vertices(pe->getBoard()->getGraph()) << endl;
    cout << "\nTotal number edges ->" << num_edges(pe->getBoard()->getGraph()) << endl;


    PlayerCard pc1("Montreal");
    PlayerCard pc2("Atlanta");
    PlayerCard pc3("Chicago");
    PlayerCard pc4("Essen");
    PlayerCard pc5("London");
    PlayerCard pc6("Madrid");

    vector <PlayerCard*> pcVector = {&pc1,&pc2,&pc3,&pc4,&pc5,&pc6};

    Pawn* pawn1 = new Pawn(pe->getBoard());

    DirectFlightAction directFlightAction;
    DiscoverCure discoverCure;
    PlayerAction* pcArray [] = {&directFlightAction, &discoverCure};

    Player* p = new Player;


    p->setCurrentLocation(pawn1);
    p->setPlayerCard(pcVector);
    p->setPlayerAction(pcArray[0]);

    cout << p->getCurrentLocation()->getCurrentCity()->getCityName() << endl;

    p->usePlayerAction();

    cout << p->getCurrentLocation()->getCurrentCity()->getCityName() << endl;

    //Decorater class
    PlayerRoleCard* playerRoleCard = new Scientist(pcArray[1]);
    p->setPlayerAction(playerRoleCard);
    p->usePlayerAction();






    delete playerRoleCard;
    delete p;
    delete pe;
    cout << "\nProgram ended" << endl;




    return 0;
}












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




