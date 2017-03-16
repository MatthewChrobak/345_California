#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include "Player.h"
#include "CityCard.h"
#include "PlayerView.h"

int main() {
   // std::cout << "Hello, World!" << std::endl;

    //srand(time(0));

    //int x = rand() % 200

    //initialising objects

    Player *p1 = new Player();
    Player *p2 = new Player();

    PlayerView* pv1 = new PlayerView(p1);


    std::string name1 = "John";
    std::string name2 = "Jacob";

    RoleCard *role1 = new RoleCard("Scientist");
    RoleCard *role2 = new RoleCard("Medic");


    Pawn *pwn1 = new Pawn();
    Pawn *pwn2 = new Pawn();

    PlayerCard *pc1 = new CityCard();


    PlayerCard *pc2;
    PlayerCard *pc3;
    PlayerCard *pc4;

    vector <PlayerCard*> playerc1 = {pc1, pc2};
    vector <PlayerCard*> playerc2 = {pc3, pc4};



    ReferenceCard *r1 = new ReferenceCard();
    ReferenceCard *r2 = new ReferenceCard();


    //setting attributes
    p1->setPlayerName(name1);
    p1->setRoleCard(role1);
    p1->setReferenceCard(r1);
    p1->setPawn(pwn1);
    p1->setPlayerCards(playerc1);


    PlayerView* pv2 = new PlayerView(p1);



    p1->setPlayerName(name2);
    p1->setRoleCard(role2);
    p1->setReferenceCard(r2);
    p1->setPawn(pwn2);
    p1->setPlayerCards(playerc2);

    p1->unregister(pv1);

    std::cout << "\nWould like to see the reference card along with the rolecard's ability? Y for yes, N for no"
              << std::endl;

    std::string response;

    std::cin >> response;

    std::vector<Player *> pv{p1, p2};

/*
    while (response[0] != 'n' && response[0] != 'N') {

        for (int i = 0; i < pv.size(); i++) {
            pv[i]->getReferenceCard()->display();
        }


        std::cout << "Press any 'n' to exit the loop" << std::endl;
        std::cin >> response;


    }

    */





    std::cout << "Deleting all the object pointers..." << std::endl;
    delete role1;
    delete role2;
    delete pwn1;
    delete pwn2;

    delete r1;
    delete r2;


    delete p1;
    delete p2;




    std::cout << "Bye!" << std::endl;


    return 0;
}