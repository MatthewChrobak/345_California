/*
 * This is the driver of the program. The players are both first set up with initial values by calling out objects.
 * The players then goes through a menu, allowing them to interact with their possessions. Player One is called
 * first, and should be allowed 4 actions (mainly to play or give a card, or build a station). Player Two is called afterwards
 * and similarly, is allowed 4 actions too. The cycle repeats afterwards; player One has 4 actions again, until.
 * the player cards are exhausted (do-while loop that loops until a counter = 0, meaning there are no more cards).
 * Only two actions are permitted per player because the program is currently incomplete.
 */

#include <iostream>
#ifndef PANDEMIC6_TESTING_H
#define PANDEMIC6_TESTING_H
#include "Player.h"

using namespace std;

static void gameMenu()
{
    cout << "Game menu\n"
            "1) Play a single card.\n"
            "2) Build a research station (using your cards).\n"
            "3) Obtain information about your event card (if any).\n"
            "4) Check your current hand.\n"
            "5) Read the reference card.\n"
            "6) Obtain information about an epidemic card.\n"
            "7) Give a city card to your teammate\n";
}

int main(){

    // Creating objects
    Role *randomRole = new Role(); // Creates a Role object
    Pawn *randomPawn = new Pawn(); // Creates a Pawn object
    Player *playerOne = new Player(); // Creates a first Player object
    Player *playerTwo = new Player(); // Creates a second Player object
    Reference *initializeReference = new Reference(); // Creates a Reference object
    PlayerCards *addingCities = new PlayerCards();    // Creates a PlayerCards object

    //Player 1 setup
    cout << "Welcome to Pandemic's player setup.\n"
            "Player 1, please enter your name. Your role will be randomly selected right afterwards." << endl;

    addingCities->setPlayerCards(4);                    // Assigns 4 cities to the PlayerCards object
    string playerOneName;                               // String to contain player 1's name
    string playerTwoName;                               // String to contain player 2's name
    cin >> playerOneName;                               // Player's name input
    randomRole -> setRole(randomRole -> randomValue()); // Assigning a random role to the player
    randomPawn -> setColor(randomRole->getRoles());     //Assigning the player's pawn color
    //Setting attributes to player 1
    playerOne -> setPlayerName (playerOneName);
    playerOne -> setRole(*randomRole);
    playerOne -> setColor(*randomPawn);
    playerOne -> setReference(*initializeReference);
    playerOne -> setPlayerCard(addingCities);           // Adds the cities to playerOne
    addingCities -> clearVector();                      // Clears the content of the PlayerCards object

    cout << "We hope you are ready to save the world " << playerOne -> getPlayerName() << ". You are the " << playerOne -> getRoles().getRoles() << " and your pawn color is " << playerOne -> getColor().getColor() << "." << endl;
    cout << "You will start with the following cards: " << playerOne -> getPlayerCards().getPlayerCards() << endl;

    //Player 2 setup
    cout << "Player 2, please enter your name. Your role will be randomly selected right afterwards." << endl;

    cin >> playerTwoName;                               // Player's name input
    randomRole -> setRole(randomRole -> randomValue()); // Assigning a random role to the player
    randomPawn -> setColor(randomRole -> getRoles());   // Assigning the player's pawn color

    //Setting values to player 2
    addingCities->setPlayerCards(4);                    // Assigns 4 other cities to the PlayerCards object
    playerTwo -> setPlayerName (playerTwoName);
    playerTwo -> setRole(*randomRole);
    playerTwo -> setColor(*randomPawn);
    playerTwo -> setReference(*initializeReference);
    playerTwo -> setPlayerCard(addingCities);           // Adds the cities to playerTwo
    addingCities -> clearVector();

    cout << "We hope you are ready to save the world " << playerTwo -> getPlayerName() << ". Your role is: " << playerTwo -> getRoles().getRoles() << " and your pawn color is " << playerTwo -> getColor().getColor() << "." << endl;
    cout << "You will start with the following cards: " << playerTwo -> getPlayerCards().getPlayerCards() << endl;
    cout << "Good luck!" << endl << endl << endl;

    delete randomRole;
    delete randomPawn;
    delete initializeReference;

    cout << "******************** GAME START ********************" << endl;

    // INTEGER "TESTING" IS FOR TESTING PURPOSES. For the sake of this assignment, "testing" will cause the following
    // loop, to loop only twice rather than until the PlayerCards pack is exhausted since a "DrawCard" function
    // has not yet been implemented.
    int testing = 0;

    do {
        int actionCounter = 2; // Actions have been set to 2 per round for the sake of the assignment. They should be 4.

        //Player 1 starts
        do {
            gameMenu();
            cout << endl;

            playerOne->removeEpidemic(); // Discards any epidemic card the player may have picked

            cout << "Player One, please choose an option from the menu: ";
            int menuChoice;
            cin >> menuChoice;

            //Play a single card
            if (menuChoice == 1) {
                playerOne->playCard();
                actionCounter--;
            }

            //Build a research station
            else if (menuChoice == 2) {
                //If city doesn't already have a station, build a station at the player's location.
                playerOne -> buildStationP();
                actionCounter--;
            }

            //Obtain information about an event card
            else if (menuChoice == 3) {
                playerOne->getPlayerCards().getEventDescription();
            }

            //Check current hand
            else if (menuChoice == 4) {
                cout << playerOne->getPlayerCards().getPlayerCards() << endl;
            }

            //Read Reference Card
            else if (menuChoice == 5) {
                cout << playerOne->getReference().getReference() << endl;
            }

            //Obtain information about an epidemic card
            else if (menuChoice == 6) {
                playerOne->getPlayerCards().getEpidemicDescription();
            }

            else if (menuChoice == 7) {
                cout << "This section should allow one player who's in the same city as the other player to give that city's card.";
                actionCounter --;
            }

            else{
                cout << "The choice you made does not exist." << endl;
            }

        }while(actionCounter > 0);

        cout << "END OF PLAYER 1'S TURN." << endl << endl;

        actionCounter = 2; // Resets the counter for number of actions

        //Player 2 starts
        do {
            gameMenu();
            cout << endl;

            playerTwo->removeEpidemic();

            cout << "Player Two, please choose an option from the menu: ";
            int menuChoice;
            cin >> menuChoice;

            //Play a single card
            if (menuChoice == 1) {
                playerTwo->playCard();
                actionCounter --;
            }

            //Build a research station
            if (menuChoice == 2) {
                //If city doesn't already have a station, build a station at the player's location.
                playerTwo -> buildStationP();
                actionCounter--;
            }

            //Obtain information about an event card
            if (menuChoice == 3) {
                playerTwo->getPlayerCards().getEventDescription();
            }

            //Check current hand
            if (menuChoice == 4) {
                cout << playerTwo->getPlayerCards().getPlayerCards() << endl;
            }

            //Read Reference Card
            if (menuChoice == 5) {
                cout << playerTwo->getReference().getReference() << endl;
            }

            //Obtain information about an epidemic card
            if (menuChoice == 6) {
                playerTwo->getPlayerCards().getEpidemicDescription();
            }

            if (menuChoice == 7) {
                cout << "This section should allow one player who's in the same city as the other player to give that city's card.";
                actionCounter --;
            }

        }while(actionCounter > 0);

        cout << "END OF PLAYER 2'S TURN." << endl << endl;

        testing ++;

    }while(testing < 2);

    //The external while loop only loops twice for the sake of testing. It should loop as long as there are still cards in playerCards
    cout << "END OF CODE." << endl;

    delete addingCities;
    delete playerOne;
    delete playerTwo;
};

#endif //PANDEMIC6_TESTING_H
