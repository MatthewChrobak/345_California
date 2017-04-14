#pragma once
#include <iostream>
#include "Game.h"
#include <ctime>

#ifdef DEBUG
#include <assert.h>
#endif

int main()
{
	// Create a new instance of the game.
	auto game = Game::getInstance();
	game.changeState(GameState::MainMenu_GameState);

	// While the game is running
	while (game.getState() != GameState::Closed_GameState)
	{
		// draw the controller.
		game.getController().draw();
	}
}