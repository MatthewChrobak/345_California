#include "Game.h"
#include "FileSystem.h"
#include "GraphicsManager.h"
#include <ctime>

#ifdef DEBUG
#include <assert.h>
#endif

Board* Game::_gameBoard = nullptr;
GameState Game::_state = GameState::Closed;
std::string Game::_saveFolder = "";

void Game::loadOrCreate(std::string savename)
{
#ifdef DEBUG
	assert(Game::getState() == GameState::Closed);
#endif

	// Assign the new name to the game.
	Game::_saveFolder = FileSystem::getStartupPath() + GAME_SAVES_FOLDER + savename + "/";

	// Make sure the proper folders exist.
	Game::checkDirectories();

	// Initialize the graphics system.
	GraphicsManager::initialize();

	Game::changeState(GameState::InGame);

	// Load the game board.
	Game::_gameBoard = new Board(Game::_saveFolder);

	Game::gameloop();
}

void Game::save()
{
	Game::_gameBoard->save(Game::_saveFolder);
}

void Game::destroy()
{
#ifdef DEBUG
	// Only destroy the game if we're flagged to.
	assert(Game::getState() == GameState::Closed);
#endif
	GraphicsManager::destroy();

	if (Game::_gameBoard != nullptr) {
		delete Game::_gameBoard;
	}
}

void Game::gameloop()
{
	int tick = 0, tmrGraphics = 0;

	// Continue to loop while the game is not closed.
	while (Game::getState() != GameState::Closed) {

		tick = std::clock();

		if (tmrGraphics < tick) {
			GraphicsManager::draw();
			tmrGraphics = tick + 16;
		}
	}

	Game::destroy();
}

void Game::checkDirectories()
{
	// Ensure the saves folder exists.
	if (!FileSystem::directoryExists(FileSystem::getStartupPath() + GAME_SAVES_FOLDER)) {
		FileSystem::createDirectory(FileSystem::getStartupPath() + GAME_SAVES_FOLDER);
	}

	// Ensure the savegame folder exists.
	if (!FileSystem::directoryExists(Game::_saveFolder)) {
		FileSystem::createDirectory(Game::_saveFolder);
	}

	// Ensure the graphics folder exists.
	if (!FileSystem::directoryExists(FileSystem::getStartupPath() + GRAPHICS_PATH)) {
		FileSystem::createDirectory(FileSystem::getStartupPath() + GRAPHICS_PATH);
	}

	// Ensure that the font folder exists.
	if (!FileSystem::directoryExists(FileSystem::getStartupPath() + FONTS_PATH)) {
		FileSystem::createDirectory(FileSystem::getStartupPath() + FONTS_PATH);
	}
}

Board* Game::getGameBoard()
{
	return Game::_gameBoard;
}

GameState Game::getState()
{
	return Game::_state;
}

void Game::changeState(GameState state)
{
#ifdef DEBUG
	assert(state != GameState::GameState_Length);
#endif
	// Blindly accept state changes for now.
	Game::_state = state;
}

