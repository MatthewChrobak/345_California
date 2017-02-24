/*
COMMON PART (PLAYER CLASS)
DISTINCT PART -> ROLE CARD AND REFERENCE CARD CLASSES.
*/
#include "ReferenceCard.h"

ReferenceCard::ReferenceCard(RoleCard *r): super(*r)
{

}





void ReferenceCard::display() {



    std :: cout << "\nREFERENCE CARD"
            "\n-Drive (or Ferry)-\n"
            "Move your pawn to an adjacent city. Cities are adjacent if they are connected by a red line.\n"
            "Red lines that go off the edge of the board “wrap around” to the opposite board edge and continue to the indicated city."
            "\n(For example, Sydney and Los Angeles are considered to be adjacent)\n"
            "\n-Direct Flight-\n"
            "Play a card from your hand and move your pawn to the pictured city.\n "
            "Discard the card to the Player Discard pile.\n"
            "\n-Charter Flight-\n"
            "Play the card corresponding to your pawn’s current location, and move to any city on the board. "
            "\nDiscard the card to the Player Discard pile.\n"
            "\n-Shuttle Flight-\n"
            "If your pawn is in a city with a Research Station, move it to any other city with a Research Station. "
            "(See below for details on building Research Stations.)\n"
            "\n-Build A Research Station-\n"
            "Building Research Stations helps your team move from place to place.\n"
            "Research Stations are also required for discovering cures.\n"
            "Play the card corresponding to the city your pawn currently occupies, "
            "then place a Research Station in that city. Discard the card to the Player Discard Pile.\n"
            "If there aren’t any Research Stations left in the supply, select one of the Research Stations "
            "already in play and transfer it to the city your pawn occupies.\n"
            "\n-Treat Disease-\n"
            "Remove a disease cube from the city your pawn occupies. (Each removed cube costs one action.)\n"
            "Place the removed cube back into the stock by the side of the board. If players have discovered a cure,\n"
            "instead of one cube, remove all cubes of a cured disease in your current city for one action.\n"
            "\n-Discover A Cure-\n"
            "Once your team has discovered all four cures, you win!\n"
            "If your pawn is in a city with a Research Station, discard 5 cards of the same color to cure the corresponding disease.\n"
            "Take a Cure marker and place it (vial-side up) on the Discovered Cures area of the board to indicate which disease has been cured.\n"
            "Place the spent cards into the Player Discard Pile.\n"
            "\n-Share Knowledge-\n"
            "Sometimes it’s hard for one player to get the cards necessary to discover a cure. "
            "The Share Knowledge action (while difficult to perform) can be useful in these cases.\n"
            "Transfer a card from one player to another. Every card transferred costs 1 action.\n"
            "Both your pawn and your fellow player’s pawn must be in the same city,\n"
            "and you may only transfer the card of the city that you are in together.\n"
            "(For example, if you are together in Moscow, only the Moscow card may be transferred from one player to the other.) "
            "If either player holds more than 7 cards as the result of a transfer,\n"
            "the excess cards must be immediately discarded to the Player Discard Pile.\n"<< std :: endl;





    //std :: cout << "Also since you're "  << super::getRoleCardname() << " , you have the following ability - " << std :: endl;

    //this->roleCardDesc();
    if (super::getRoleCardVal() >= 0) {

        //std :: string name =

        std::cout << "Also since you're " << super::getRoleCardname() << " , you have the following ability - \n"
                  << std::endl;
        super::roleCardDesc();


    }


    std:: cout << "---------------------------------------" << std:: endl;
}

