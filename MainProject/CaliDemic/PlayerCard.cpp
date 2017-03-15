#include "PlayerCard.h"
#include "Game.h"
#include "EventCard.h"
#include "EpidemicCard.h"
#include "Board.h"
#include "InfectionCard.h"
#include "City.h"
#include <stdlib.h>    
#include <time.h>
#include <stdio.h> 
#include "FileStream.h"
#include "FileSystem.h"

vector <string> epidemic
{
	"Epidemic","Epidemic","Epidemic","Epidemic"
};

void PlayerCard::playCard()
{
	// Throw an exception because this method is virtual and should be overriden.
	throw;
}

std::string PlayerCard::getSurfaceName()
{
	// Throw an exception because this method is virtual and should be overriden.
	throw;
}

PlayerCardType PlayerCard::getType()
{
	return this->_cardType;
}

//Default constructor
PlayerCard::PlayerCard() {};

PlayerCard::~PlayerCard()
{
}

//FOR TESTING: Method to test remaining cities in PlayerCards
/*void PlayerCards:: listCities(){
for(int i =0; i< 12; i++)
cout << blueCities[i] << endl;
for(int i =0; i< 12; i++)
cout << redCities[i] << endl;
for(int i =0; i< 12; i++)
cout << blackCities[i] << endl;
for(int i =0; i< 12; i++)
cout << yellowCities[i] << endl;
}*/

//Clearing entire vector for next object
void PlayerCard::clearVector() {
	playerCards.clear();
};

// Returns the size of the vector
int PlayerCard::getVectorSize() {
	return playerCards.size();
}

// Returns the remaining number of cards in the player stack
int PlayerCard::getCardCounter() {
	return cardCounter;
}

// Retrieves all the cards from the player's hand as a string
string PlayerCard::getPlayerCards() {

	if (playerCards.size() > 0) {
		string *tempArray = new string[7]; // A temporary array is created in order to properly format the output
		string listOfCards = playerCards[0];

		if (playerCards.size() > 1) {
			for ( unsigned int i = 1; i < playerCards.size(); i++) {
				tempArray[i] = playerCards[i];
				listOfCards = listOfCards + ", " + tempArray[i];
			}
			return listOfCards;
		}
	}

	if (playerCards.size() == 0) {
		return "You have no more cards to play";
	}

	// TODO: fix this chun.
	return "";
}

// Retrieves a single card from the player's hand
string PlayerCard::getSingleCard(int cardPosition) {
	return playerCards[cardPosition];
}

// Removes a single card from the player's hand
void PlayerCard::removeSingleCard(int cardPosition) {
	playerCards.erase(playerCards.begin() + cardPosition);
}

// Sets a specific number of random cards to the player. A random number generator is used to randomly pick the cards
// that are assigned to a player. A player card that's been assigned from the class to the player is erased from the class.
// As cards are erased from the vector, the size decreases; that is why getRdmValArray retrieves the size of a vector
// rather than a fixed integer.
void PlayerCard::setPlayerCards(int numberOfCards) {

	for (int i = 0; i < numberOfCards; i++) {
		
		srand((unsigned)time(NULL));
		int value = rand() % (playerCardsDeck.size()) + 1;
		
		if (playerCardsDeck[value].substr(0, 2) == "Rd" || "Be" || "Bk" || "Yw")
		{
			cardCounter--;
		}

		playerCards.push_back(playerCardsDeck[value]);
		playerCardsDeck.erase(playerCardsDeck.begin() + value);

	}
}

//Automatically discards en Epidemic card if the player picks one
void PlayerCard::useEpidemic() {
	/*for (unsigned int i = 0; i< playerCards.size(); i++)
	{
		if (playerCards[i] == "Epidemic") {
			playerCards.erase(playerCards.begin() + i);
		}
	}
	*/

	int counter = 0;
	int epidemicInfection =Board::infectionCityCards.back();
	//shrinking the infectionCityCards
	Board::infectionCityCards.shrink_to_fit();

	static const int cityColor = Game::getGameBoard()->getCity(epidemicInfection)->color;
	//infect the draw city three times
	for (int i = 0; i < 3; i++)
	{
		
		if (Game::getGameBoard()->getCity(epidemicInfection)->cube[i] == -1)
		{
			counter++;
			Game::getGameBoard()->getCity(epidemicInfection)->cube[i] = cityColor;
			Game::numOfCubeDecrementor(cityColor);
		}

	}
	//if the draw city is not been infect three times that mean that there is an outbreak
	if (counter < 3)
	{
		City::infectCityOutBreak(epidemicInfection);
	}
}


//Get the description of an event card (if in possession)
void PlayerCard::getEventDescription() {

	int counter = 0; // Counter remains 0 if no event card is found in a player's hand

	for (unsigned int i = 0; i < playerCards.size(); i++) {
		if (playerCards[i] == "Government Grant") {
			cout << "Government Grant: Add 1 research station to any city (no discard needed)." << endl;
			counter++;
		}

		if (playerCards[i] == "Airlift") {
			cout << "Airlift: Move any 1 pawn to any city. Get permission before moving another player's pawn." << endl;
			counter++;
		}

		if (playerCards[i] == "Resilient Population") {
			cout
				<< "Resilient Population: Remove any 1 card in the Infection Discard Pile from the game. You may play this between the Infect and Intensify steps of an epidemic."
				<< endl;
			counter++;
		}

		if (playerCards[i] == "Forecast") {
			cout
				<< "Forecast: Draw, look at, and rearrange the top 6 cards of the Infection Deck. Put them back on top."
				<< endl;
			counter++;
		}
		if (playerCards[i] == "One Quiet Night") {
			cout << "One Quiet Night: Skip the next Infect Cities step (do not flip over any Infection cards)." << endl;
			counter++;
		}
	}

	if (counter == 0) {
		cout << "You do not have any event card." << endl;
	}

	cout << endl;
}

//Creates the initial player deck. City cards are initialized with a color abbreviation to facilitate identification
void PlayerCard::setPlayerCardDeck() {

	int numCities = Game::getGameBoard()->getNumCities();

	for (int i = 0; i < numCities; i++) {
		City* city = Game::getGameBoard()->getCity(i);

		if (city->color == InfectionColor::Blue) {
			this->playerCardsDeck.push_back("Be - " + city->name);
		}

		if (city->color == InfectionColor::Red) {
			this->playerCardsDeck.push_back("Rd - " + city->name);
		}

		if (city->color == InfectionColor::Yellow) {
			this->playerCardsDeck.push_back("Yw - " + city->name);
		}

		if (city->color == InfectionColor::Black) {
			this->playerCardsDeck.push_back("Bl - " + city->name);
		}
	}

	auto fs = FileStream::Open(FileSystem::getStartupPath() + "doesn't matter right now", FileMode::Read);
	
	// TODO: fix this chun.
	//for (int i = 0; i < 5; i++) {
	//	std::string value = this->playerCardsDeck.at(this->playerCardsDeck.size() - 1);
	//	fs->write(value);
	//}

	//auto gs = FileStream::Open(FileSystem::getStartupPath() + "doesn't matter once again...", FileMode::Read);

	//for (int i = 0; i < 4; i++) {
	//	gs->write(this->playerCardsDeck.pop_back());
	//}
}

//Get the description of an epidemic card
void PlayerCard::getEpidemicDescription() {

	cout << "EPIDEMIC\n"
		"1-INCREASE\n"
		"Move the infection rate marker forward 1 space.\n"
		"2-INFECT\n"
		"Draw the bottom card from the infection deck and put 3 cubes on that city. Discard that card.\n"
		"3-INTENSIFY\n"
		"Shuffle the cards in the infection discard pile and put them on top of the infection deck."
		<< endl;

	cout << endl;
}

//Discarding cards to create a research center if possible
void PlayerCard::buildStationPC() {

	int blueCounter = 0;
	int redCounter = 0;
	int blackCounter = 0;
	int yellowCounter = 0;

	string red = "Rd";
	string yellow = "Yw";
	string blue = "Be";
	string black = "Bk";

	//Adds up the counters for every colored car the player possesses
	for (unsigned int i = 0; i < playerCards.size(); i++)
	{
		if (playerCards[i].substr(0, 2) == red) // Checks the first two letters of a city to see if color corresponds
		{
			redCounter++;
		}

		if (playerCards[i].substr(0, 2) == yellow)
		{
			yellowCounter++;
		}

		if (playerCards[i].substr(0, 2) == blue)
		{
			blueCounter++;
		}

		if (playerCards[i].substr(0, 2) == black)
		{
			blackCounter++;
		}
	}

	// Checks if there are 5 of the same colored cards
	if (blackCounter >= 5 || redCounter >= 5 || blueCounter >= 5 || yellowCounter >= 5)
	{
		string counterColor; // Will be used to check that the card chosen by the player is of appropriate color

		if (blackCounter >= 5)
		{
			counterColor = black;
		}
		else if (redCounter >= 5)
		{
			counterColor = red;
		}
		else if (blueCounter >= 5)
		{
			counterColor = blue;
		}
		else
		{
			counterColor = yellow;
		}

		//Create a research center at player location
		cout << "Select a card which you wish to discard for the creation of your research center (enter an integer): " << endl;
		cout << "Your current cards are: " << getPlayerCards() << endl;
		int counter2 = 0; // Increments until 5 to ensure that there are 5 cards discarded

						  //The player chooses which cards to use for the construction of a research station
		for (int i = 0; i < 5; i++) {
			int input;
			cin >> input;

			if (playerCards[input - 1].substr(0, 2) == counterColor) {
				playerCards.erase(playerCards.begin() + input - 1);

				counter2++;

				if (counter2 < 5) {
					cout << "Select the next card which you wish to discard: " << endl;
					cout << "Your current cards: " << getPlayerCards() << endl;
				}
			}

			else {
				cout << "The card you've chosen is not of the right color. Try again." << endl;
				i--;
			}
		}
		cout << "A research center has been created at your location." << endl;
	}

	else {
		cout << "You do not have enough cards to create a research center." << endl;
	}

	cout << endl;

}

