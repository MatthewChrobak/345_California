#pragma once
#include "Board.h"
#include <string>

#define NUM_OF_STARTING_CUBE 24
#define NUM_OF_MAX_ACTION 4
#define NUM_OF_STARTING_RESEARCH_FACILITY 6

enum GameState : int
{
	MainMenu,
	InGame,
	Closed,
	GameState_Length
};

class Game 
{
public:
	static void loadOrCreate(std::string savename);
	static void destroy();
	static void save();

	static void changeState(GameState state);
	static GameState getState();

	static Board* getGameBoard();
	static void setGameBoard(Board* board);

	/*
	attribute to number of cube for each color
	*/
	static int numOfYellowCube;
	static int numOfBlackCube;
	static int numOfBlueCube;
	static int numOfRedCube;
	static int numOfResearchCenter;

	static void numOfCubeDecrementor(int cityColor);
	static void numOfCubeIncrementor(int cityColor);

	static int actionCounter;

	static void decrementActionCounter();
	static void resetActionCounter();

private:
	static Board* _gameBoard;
	static GameState _state;
	static std::string _saveFolder;
};

