#include <vector>
#include <iostream>
#include "Player.h"

int main() {



    srand(time(0));

    int x = rand() % 200;

   //initialising objects
    Player* p1 = new Player();
    Player* p2 = new Player ();


   std:: string name1 = "John";
   std:: string name2 = "Jacob";

    RoleCard* role1 = new RoleCard ("Scientist");
    RoleCard* role2 = new RoleCard ("Medic");


    Pawn* pwn1 = new Pawn();
    Pawn* pwn2= new Pawn();

    PlayerCards* pc1 = {};
    PlayerCards* pc2 = {};

    ReferenceCard* r1 = new ReferenceCard(role1);
    ReferenceCard* r2 = new ReferenceCard(role2);


    //setting attributes
    p1->setPlayerName(name1);
    p1->setRoleCard(role1);
    p1->setReferenceCard(r1);
    p1->setPawn(pwn1);
    p1->setPc(pc1);


    p2->setPlayerName(name2);
    p2->setRoleCard(role2);
    p2->setReferenceCard(r2);
    p2->setPawn(pwn2);
    p2->setPc(pc2);

    std :: cout << "\nWould like to see the reference card along with the rolecard's ability? Y for yes, N for no" << std :: endl;

    std :: string response;

    std :: cin >> response;

    std ::vector <Player*> pv {p1, p2};





    while (response[0] != 'n'){

        for(int i=0; i < pv.size(); i++){
          pv[i]->getReferenceCard()->display();
        }



     std :: cout << "Press any key to exit the loop" << std :: endl;
     std :: cin >> response;



    }






   std :: cout << "Deleting all the pointer objects..." << std :: endl;
    delete role1;
    delete role2;
    delete pwn1;
    delete pwn2;
    delete pc1;
    delete pc2;
    delete r1;
    delete r2;



    delete p1;
    delete p2;







 std :: cout << "Thanks!" << std :: endl;


 return 0;
}