#pragma once
#include "Board.h"
#include <string>

#define GAME_SAVES_FOLDER "saves/"

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
	static void save();

	static void changeState(GameState state);
	static GameState getState();

	static Board* getGameBoard();


private:
	static Board* _gameBoard;
	static GameState _state;
	static std::string _saveFolder;


	static void destroy();
	static void checkDirectories();
	static void gameloop();
};

