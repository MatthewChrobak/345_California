#pragma once
#include "SfmlSystem.h"
#include "GraphicsManager.h"
#include "Game.h"

#ifdef DEBUG

#include "FileSystem.h"

void gameloop()
{
	int tick = 0, tmrRender = 0;

	while (1)
	{
		tick = clock();

		if (tmrRender < tick) {
			GraphicsManager::draw();
			tmrRender = tick + 16;
		}
	}

	GraphicsManager::destroy();
}

// Sample main for debugging and testing purposes.
int main() {
	
	// Initialize the graphics system.
	GraphicsManager::initialize();

	// Ensure the graphics folder exists.
	if (!FileSystem::directoryExists(FileSystem::getStartupPath() + GraphicsManager::GraphicsPath)) {
		FileSystem::createDirectory(FileSystem::getStartupPath() + GraphicsManager::GraphicsPath);
	}

	// Ensure the saves folder exists.
	if (!FileSystem::directoryExists(FileSystem::getStartupPath() + Game::SavePath)) {
		FileSystem::createDirectory(FileSystem::getStartupPath() + Game::SavePath);
	}

	// Ensure that the font folder exists.
	if (!FileSystem::directoryExists(FileSystem::getStartupPath() + GraphicsManager::FontPath)) {
		FileSystem::createDirectory(FileSystem::getStartupPath() + GraphicsManager::FontPath);
	}

	Game::load("save1");
	gameloop();
}

#endif