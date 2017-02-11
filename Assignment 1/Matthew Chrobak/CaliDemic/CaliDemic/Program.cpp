#pragma once
#include "SfmlSystem.h"
#include "GraphicsManager.h"

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
	if (!FileSystem::directoryExists(FileSystem::getStartupPath() + "graphics/")) {
		FileSystem::createDirectory(FileSystem::getStartupPath() + "graphics/");
		std::cout << "Created directory graphics/" << std::endl;
	}

	gameloop();
}

#endif