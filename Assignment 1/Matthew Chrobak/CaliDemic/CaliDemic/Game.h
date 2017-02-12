#pragma once
#include "Board.h"
#include <string>

class Game
{
public:
	static void startNew();
	static void load(std::string savename);
	static void save(std::string savename);

	static const std::string SavePath;

	static Board* getGameBoard();

private:
	static Board* _gameBoard;

	static void destroy();
};

