#include "ActionCounter.h"

//Initialize as 4 actions
int actionCounter = 4;

//Decrements number of actions whenever this is called
extern void decrementActionCounter() {
	actionCounter--;
}

//Resets the number of actions
extern void resetActionCounter() {
	actionCounter = 4;
}