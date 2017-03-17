#include "ActionCounter.h"
#include "Player.h"
#include "Board.h"
#include "Game.h"
//Initialize as 4 actions
int actionCounter = 4;

//Decrements number of actions whenever this is called
extern void decrementActionCounter() {
	actionCounter--;
	if (actionCounter <= 0){
		Board* board = Game::getGameBoard();
		bool test = board->playerTurnChange();
		std::cout << "Players switched -> " << test << std::endl;
	}

}

//Resets the number of actions
extern void resetActionCounter() {
	actionCounter = 4;
}