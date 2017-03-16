#pragma once
#include "SurfaceContext.h"
#include "TextContext.h"
#include <string>

class GraphicsSystem
{
public:
	virtual ~GraphicsSystem() {};

	// Context construction events
	virtual void destroyContext() = 0;
	virtual void restartContext() = 0;
	virtual void drawContext() = 0;
	virtual void handleInput() = 0;

	// Context mutators
	virtual void setWindowTitle(std::string title) = 0;
	virtual void setWindowSize(unsigned int width, unsigned int height) = 0;
	virtual void setContextSize(unsigned int width, unsigned int height) = 0;

	virtual bool isDestroyed() = 0;
	virtual void renderSurface(std::string surfacename, SurfaceContext& ctx) = 0;
	virtual void renderText(std::string text, TextContext& ctx) = 0;

private:
	// Context construction events
	virtual void createContext() = 0;
};