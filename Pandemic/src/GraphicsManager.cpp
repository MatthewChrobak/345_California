#include "GraphicsManager.h"
#include "SfmlGraphicsSystem.h"
#include "GuiManager.h"
#ifdef DEBUG
#include <assert.h>
#endif

GraphicsSystem* GraphicsManager::_system = nullptr;

GraphicsSystem& GraphicsManager::getInstance()
{
	// Create the instance if it's null.
	if (GraphicsManager::_system == nullptr) {
		GraphicsManager::_system = new SFML::SfmlGraphicsSystem("Pandemic", DRAW_WIDTH, DRAW_HEIGHT, GuiManager::WindowWidth, GuiManager::WindowHeight);
	}
	
	return *GraphicsManager::_system;
}


void GraphicsManager::destroy()
{
#ifdef DEBUG
	assert(GraphicsManager::_system != nullptr);
#endif
	delete GraphicsManager::_system;
	GraphicsManager::_system = nullptr;
}

