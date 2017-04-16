#include "Game.h"
#include "MainMenuController.h"
#include "GameController.h"

#ifdef DEBUG
#include <assert.h>
#endif

// Singleton functions and properties.
Game* Game::_game = nullptr;

Game& Game::getInstance()
{
	// Create the instance if it's null.
	if (Game::_game == nullptr) {
		Game::_game = new Game();
	}

	return *Game::_game;
}



// Instance functions and properties.
Game::Game()
{

}

Controller& Game::getController()
{
	return *this->_controller;
}

Board& Game::getBoard()
{
	return *this->_board;
}

GameState Game::getState()
{
	return this->_state;
}

void Game::changeState(GameState state)
{
	switch (state)
	{
		// Are we trying to close the game?
		case GameState::Closed_GameState:
#ifdef DEBUG
			assert(this->getState() == GameState::MainMenu_GameState);
#endif
			SwapController(nullptr);
			break;

		// Are we trying to get into the game?
		case GameState::InGame_GameState:
#ifdef DEBUG
			assert(this->getState() == GameState::MainMenu_GameState);
#endif
			SwapController(new GameController());
			break;

		// Are we trying to get to the main menu?
		case GameState::MainMenu_GameState:
#ifdef DEBUG
			assert(this->getState() == GameState::InGame_GameState || this->getState() == GameState::Startup_GameState);
#endif
			SwapController(new MainMenuController());
			break;

		// Is the game finished closed and going back into a startup state?
		case GameState::Startup_GameState:
#ifdef DEBUG
			assert(this->getState() == GameState::Closed_GameState);
#endif
			SwapController(nullptr);
			break;
	};
}

void Game::SwapController(Controller* controller)
{
	// Deallocate the previous controller.
	if (this->_controller != nullptr) {
		delete this->_controller;
	}

	// Assign the new one.
	this->_controller = controller;
}

void Game::numOfCubeDecrementor(int cityColor)
{
#ifdef DEBUG
	assert(cityColor >= 0 && cityColor < 4);
#endif
	this->numOfCubes[cityColor]--;

	if (this->numOfCubes[cityColor] <= 0) {
		// TODO: Game end here.
	}
}

void Game::numOfCubeIncrementor(int cityColor)
{
#ifdef DEBUG
	assert(cityColor >= 0 && cityColor < 4);
#endif
	this->numOfCubes[cityColor]++;
}

void Game::decrementActionCounter()
{
	this->actionCounter--;
}

void Game::resetActionCounter()
{
	this->actionCounter = 4;
}