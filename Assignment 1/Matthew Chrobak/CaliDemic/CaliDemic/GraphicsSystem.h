#pragma once
#include "SurfaceContext.h"

class GraphicsSystem
{
public:
	virtual ~GraphicsSystem() {};

	// Context construction events
	virtual void destroyContext() = 0;
	virtual void restartContext() = 0;
	virtual void drawContext() = 0;

	// Context mutators
	virtual void setWindowTitle(const char* title) = 0;
	virtual void setWindowSize(unsigned int width, unsigned int height) = 0;
	virtual void setContextSize(unsigned int width, unsigned int height) = 0;

	virtual bool isDestroyed() = 0;
	virtual void renderSurface(const char* surfacename, SurfaceContext& ctx) = 0;

	// TODO: Add a string containing the base directory for graphics for the sake of path isolation.

private:
	// Context construction events
	virtual void createContext() = 0;
};