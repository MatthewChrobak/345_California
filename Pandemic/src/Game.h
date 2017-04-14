/*!
	Author: Matthew Chrobak
	Contributors:

	Purpose: Provides a single instance of a game through the singleton pattern.
*/

#pragma once
#include "Controller.h"
#include "Board.h"

enum GameState : int
{
	Startup_GameState,
	MainMenu_GameState,
	InGame_GameState,
	Closed_GameState,
	GameState_Length // TODO: Only exists for backward compatability. Remove later on.
};

class Game
{
public:
	static Game& getInstance();
	Controller& getController();
	Board& getBoard();

	GameState getState();
	void changeState(GameState state);

	int numOfCubes[4];
	int numOfResearchCenter;

	void numOfCubeDecrementor(int cityColor);
	void numOfCubeIncrementor(int cityColor);

	int actionCounter;

	void decrementActionCounter();
	void resetActionCounter();



private:
	// The static variable containing the game instance.
	static Game* _game;
	// A private constructor to prevent any instantiation.
	Game();
	void SwapController(Controller* controller);

	// Instance fields pertaining to the game.
	Board* _board;
	Controller* _controller;
	GameState _state;
};