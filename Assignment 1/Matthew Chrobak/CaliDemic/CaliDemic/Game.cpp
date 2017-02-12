#include "Game.h"
#include "FileSystem.h"

Board* Game::_gameBoard = nullptr;

const std::string Game::SavePath = "saves/";

void Game::startNew()
{
	// Destroy the old game, if one exists.
	Game::destroy();

	Game::load("default");
}

void Game::load(std::string savename)
{
	// Destroy the old game, if one exists.
	Game::destroy();

	// Make sure the game exists.
	std::string fullpath = FileSystem::getStartupPath() + Game::SavePath + savename + "/";
	if (FileSystem::directoryExists(fullpath)) {

		// Load the game board.
		Game::_gameBoard = new Board(fullpath);
	}
}

void Game::save(std::string savename)
{
	// TODO: Finish this.


	// Make sure the game doesn't already exist.
	std::string fullpath = FileSystem::getStartupPath() + Game::SavePath + savename + "/";
	if (!FileSystem::directoryExists(fullpath)) {
		FileSystem::createDirectory(fullpath);
	}

	Game::_gameBoard->Save(fullpath);

	Game::destroy();
}


void Game::destroy()
{
	if (Game::_gameBoard != nullptr) {
		delete Game::_gameBoard;
	}
}

Board* Game::getGameBoard()
{
	return Game::_gameBoard;
}