#pragma once
#include "Game.h"
#include <iostream>
#include "GuiManager.h"
#include "GraphicsManager.h"
#include "FileSystem.h"
#include "Paths.h"
#include <ctime>

#ifdef DEBUG
#include <assert.h>
#endif

int main()
{

#ifdef DEBUG
	assert(Game::getState() == GameState::MainMenu);
#endif

	// Make sure the proper folders exist.

	// Ensure the saves folder exists.
	if (!FileSystem::directoryExists(FileSystem::getStartupPath() + GAME_SAVES_FOLDER)) {
		FileSystem::createDirectory(FileSystem::getStartupPath() + GAME_SAVES_FOLDER);
	}

	// Ensure the graphics folder exists.
	if (!FileSystem::directoryExists(FileSystem::getStartupPath() + GRAPHICS_PATH)) {
		FileSystem::createDirectory(FileSystem::getStartupPath() + GRAPHICS_PATH);
	}

	// Ensure that the font folder exists.
	if (!FileSystem::directoryExists(FileSystem::getStartupPath() + FONTS_PATH)) {
		FileSystem::createDirectory(FileSystem::getStartupPath() + FONTS_PATH);
	}



	// Initialize the GUI system.
	GuiManager::initialize();

	// Initialize the graphics system.
	GraphicsSystem& graphics = GraphicsManager::getInstance();







	int tick = 0, tmrGraphics = 0;

	// Continue to loop while the game is not closed.
	while (Game::getState() != GameState::Closed) {

		tick = std::clock();

		if (tmrGraphics < tick) {
			graphics.drawContext();
			tmrGraphics = tick + 16;
		}
	}





#ifdef DEBUG
	// Only destroy the game if we're flagged to.
	assert(Game::getState() == GameState::Closed);
#endif

	// Destroy the graphics system.
	GraphicsManager::destroy();

	// Destroy the UI system.
	GuiManager::destroy();
}