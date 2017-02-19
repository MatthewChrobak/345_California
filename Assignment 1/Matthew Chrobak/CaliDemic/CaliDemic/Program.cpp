#pragma once
#include "Game.h"
#include <iostream>

// Sample main for debugging and testing purposes.
int main()
{
	while (true) {
		// Either load or create a game.
		std::string gameName;
		std::cout << "Please enter the name of a save you wish to create/load or 'exit' to exit." << std::endl;
		std::getline(std::cin, gameName);

		if (gameName == "exit") {
			break;
		}

		// Load the game.
		Game::loadOrCreate(gameName);

		// When the game is no longer visible, display that the game ended.
		std::cout << "Game closed." << std::endl;
	}
}