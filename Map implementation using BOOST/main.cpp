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


    //Strategy design pattern starts here
    //Create players cards to to test DirectFlight
    PlayerCard pc1("Montreal");
    PlayerCard pc2("Atlanta");
    PlayerCard pc3("Chicago");
    PlayerCard pc4("Essen");
    PlayerCard pc5("London");
    PlayerCard pc6("Madrid");

    vector <PlayerCard*> pcVector = {&pc1,&pc2,&pc3,&pc4,&pc5,&pc6};
    //setup the current location
    Pawn* pawn1 = new Pawn(pe->getBoard());

    //Objects of the player actions
    DirectFlightAction directFlightAction;
    DiscoverCure discoverCure;
    //array of actions
    PlayerAction* pcArray [] = {&directFlightAction, &discoverCure};
    //new player
    Player* p = new Player;

    //set the variables to player
    p->setCurrentLocation(pawn1);
    p->setPlayerCard(pcVector);
    p->setPlayerAction(pcArray[0]);

    //location before using action
    cout << p->getCurrentLocation()->getCurrentCity()->getCityName() << endl;
    //use action
    p->usePlayerAction();
    //location after using action
    cout << p->getCurrentLocation()->getCurrentCity()->getCityName() << endl;

    //decorator class
    //another player to test the implementation
    Player* p2 = new Player();
    //Decorate player action
    PlayerRoleCard* playerRoleCard = new Scientist(pcArray[1]);
    p2->setPlayerAction(pcArray[1]);
    p->setPlayerAction(playerRoleCard);
    cout << "\nPlayer 1 (Scientist)" << endl;
    p->usePlayerAction();
    cout << "\nPlayer 2 (non-scientist) " << endl;
    p2->usePlayerAction();





    delete playerRoleCard;
    delete p;
    delete p2;
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




