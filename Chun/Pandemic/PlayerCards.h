/*
 * This is the PlayerCards class (also distinct part 3 of assignment #1). The cities are named after the first two letters
 * of their assigned colors to facilitate the retrieval of their specified color (in the appropriate circumstances). The purpose
 * of all the functions are stated next to the functions. Please note that the random number generator function used in the
 * setPlayerCard function is far from perfect.
 */

#include <string>
#include <vector>
#include <iostream>
#include <random>


#ifndef PANDEMIC6_CITY_H
#define PANDEMIC6_CITY_H
using namespace std;

static class PlayerCards{

private:
    vector <string> playerCards;

    int cardCounter = 49;   //This value will decrease as more cards are played.

    vector <string> blueCities
            {
                    "Be - Atlanta",      // blueCities[0]
                    "Be - Chicago",
                    "Be - Essen",
                    "Be - London",
                    "Be - Madrid",       // blueCities[4]
                    "Be - Milan",
                    "Be - New York",
                    "Be - Paris",
                    "Be - San Francisco",// blueCities [8]
                    "Be - St Petersburg",
                    "Be - Montreal",
                    "Be - Washington"
            };

    vector <string> yellowCities
            {
                    "Yw - Bogota",       // yellowCities[0]
                    "Yw - Buenos Aires",
                    "Yw - Johannesburg",
                    "Yw - Khartoum",
                    "Yw - Kinshasa",     // yellowCities[4]
                    "Yw - Lagos",
                    "Yw - Lima",
                    "Yw - Los Angeles",
                    "Yw - Mexico",  // yellowCities[8]
                    "Yw - Miami",
                    "Yw - Santiago",
                    "Yw - Sao Paulo"
            };

    vector <string> blackCities
            {
                    "Bk - Algiers",      // blackCities[0]
                    "Bk - Baghdad",
                    "Bk - Cairo",
                    "Bk - Chennai",
                    "Bk - Delhi",        // blackCities[4]
                    "Bk - Istanbul",
                    "Bk - Karachi",
                    "Bk - Kolkata",
                    "Bk - Moscow",       // blackCities[8]
                    "Bk - Mumbai",
                    "Bk - Riyadh",
                    "Bk - Tehran"
            };

    vector <string> redCities
            {
                    "Rd - Bangkok",      // redCities[0]
                    "Rd - Beijing",
                    "Rd - Ho Chi Minh",
                    "Rd - Hong Kong",
                    "Rd - Jakarta",      // redCities[4]
                    "Rd - Manila",
                    "Rd - Osaka",
                    "Rd - Seoul",
                    "Rd - Shanghai",     // redCities[8]
                    "Rd - Sydney",
                    "Rd - Taipei",
                    "Rd - Tokyo"
            };

    vector <string> events
            {
                    "Airlift",
                    "One Quiet Night",
                    "Resilient Population",
                    "Government Grant",
                    "Forecast"
            };

   vector <string> epidemic
            {
                    "Epidemic",
                    "Epidemic",
                    "Epidemic",
                    "Epidemic"
            };

public:
    PlayerCards();

public:

    string getPlayerCards();
    string getBlueCity(int blue);
    string getYellowCity(int yellow);
    string getBlackCity(int black);
    string getRedCity(int red);
    string getEvents(int eventCard);
    string getEpidemic(int epidemicCard);
    string getSingleCard(int cardPosition);

    int getRdmValArray(int arraySize);  //Retrieves a random value depending on the size of the array
    int getCardCounter();               //Counter for number of cards left in PlayerCards
    int getVectorSize();                //Retrieves the size of a vector

    void removeSingleCard(int cardPosition);             //Removes a single card from a vector at a specific position
    void setPlayerCards(int numberOfCards);              //Sets a number of cards to a player
    void clearVector();                                  //Clears a vector from all its values
    void getEventDescription();                          //Retrieves the description of an event card
    void getEpidemicDescription();                       //Retrieves the description of an epidemic card
    void buildStationPC();                               //Discards enough cards to build a research station
    void useEpidemic();                                  //Discards Epidemic cards if player picks one


    //void listCities(); //To test the list of cities remaining in PlayerCards.
};

#endif //UNTITLED6_CITY_H
