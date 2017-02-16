#include "GraphicsManager.h"
#include "SfmlSystem.h"
#ifdef DEBUG
#include <assert.h>
#endif

GraphicsSystem* GraphicsManager::_system = nullptr;
const std::string GraphicsManager::GraphicsPath = "graphics/";
const std::string GraphicsManager::FontPath = "fonts/";

void GraphicsManager::initialize()
{
	GraphicsManager::_system = new SFML::SfmlSystem("SFML is working", 960, 640, 960, 640);
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