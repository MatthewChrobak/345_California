#include "Game.h"
#include "FileSystem.h"

#ifdef DEBUG
#include <assert.h>
#endif

//This is to initiate all the cubes for each disease color

int Game::numOfYellowCube = NUM_OF_STARTING_CUBE;
int Game::numOfBlackCube = NUM_OF_STARTING_CUBE;
int Game::numOfRedCube = NUM_OF_STARTING_CUBE;
int Game::numOfBlueCube = NUM_OF_STARTING_CUBE;


Board* Game::_gameBoard = nullptr;
GameState Game::_state = GameState::MainMenu;
std::string Game::_saveFolder = "";

void Game::loadOrCreate(std::string savename)
{
#ifdef DEBUG
	// We should only load a game when we're at the main menu.
	assert(Game::getState() == GameState::MainMenu);

	// There should not be a game already loaded or uncleared.
	assert(Game::_gameBoard == nullptr);
#endif

	// Assign the new name to the game.
	Game::_saveFolder = FileSystem::getStartupPath() + GAME_SAVES_FOLDER + savename + "/";

	// Ensure the savegame folder exists.
	if (!FileSystem::directoryExists(Game::_saveFolder)) {
		FileSystem::createDirectory(Game::_saveFolder);
	}

	// Load the game board, and change the game state.
	Game::_gameBoard = new Board(Game::_saveFolder);
	Game::changeState(GameState::InGame);
}

void Game::save()
{
#ifdef DEBUG
	// We should have some kind of valid path.
	assert(Game::_saveFolder.size() > 0);
#endif
	Game::_gameBoard->save(Game::_saveFolder);
}

void Game::destroy()
{
#ifdef DEBUG
	// Only destroy the game if we're in game.
	assert(Game::getState() == GameState::InGame);
	assert(Game::_gameBoard != nullptr);
#endif

	// Save the game.
	Game::save();

	// Clean up its resources.
	delete Game::_gameBoard;
	Game::_gameBoard = nullptr;
}

Board* Game::getGameBoard()
{
#ifdef DEBUG
	// There is no benefit to returning a null game board.
	assert(Game::_gameBoard != nullptr);
#endif
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

void Game::numOfCubeLeft()
{
	std::cout << "Number of yellow cube left: " << numOfYellowCube << std::endl;
	std::cout << "Number of black cube left: " << numOfBlackCube << std::endl;
	std::cout << "Number of blue cube left: " << numOfBlueCube << std::endl;
	std::cout << "Number of red cube left: " << numOfRedCube << std::endl;
}

