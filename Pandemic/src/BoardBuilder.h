#pragma once
#include "Board.h"
#include <string>

class BoardBuilder
{
public:
	Board* loadNewGame(int numberOfPlayers);
	Board* loadFromSave(std::string savename);
	void save(std::string savename, Board& board);

private:
	void loadBoardData(std::string file, Board& board);
	void loadCities(std::string file, Board& board);
	void loadPlayers(std::string file, Board& board);

	void saveBoardData(std::string file, Board& board);
	void saveCities(std::string file, Board& board);
	void savePlayers(std::string file, Board& player);
};