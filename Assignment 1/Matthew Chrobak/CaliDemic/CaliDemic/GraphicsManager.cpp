#include "GraphicsManager.h"
#include "SfmlSystem.h"
#include "GuiManager.h"
#ifdef DEBUG
#include <assert.h>
#endif

GraphicsSystem* GraphicsManager::_system = nullptr;

void GraphicsManager::initialize()
{
	GraphicsManager::_system = new SFML::SfmlSystem("Pandemic", DRAW_WIDTH, DRAW_HEIGHT, GuiManager::WindowWidth, GuiManager::WindowHeight);
}

void GraphicsManager::draw()
{
#ifdef DEBUG
	assert(GraphicsManager::_system != nullptr);
#endif
	if (!GraphicsManager::_system->isDestroyed()) {
		GraphicsManager::_system->drawContext();
	}
}


void GraphicsManager::destroy()
{
#ifdef DEBUG
	assert(GraphicsManager::_system != nullptr);
#endif
	delete GraphicsManager::_system;
}


void GraphicsManager::renderSurface(std::string surfacename, SurfaceContext& ctx)
{
#ifdef DEBUG
	assert(GraphicsManager::_system != nullptr);
#endif
	GraphicsManager::_system->renderSurface(surfacename, ctx);
}

void GraphicsManager::renderText(std::string text, TextContext& ctx)
{
#ifdef DEBUG
	assert(GraphicsManager::_system != nullptr);
#endif
	GraphicsManager::_system->renderText(text, ctx);
}