#pragma once
#include "GraphicsSystem.h"

class GraphicsManager
{
public:
	static void initialize();
	static void destroy();
	static void draw();
	static void renderSurface(const char* surfaceName, SurfaceContext& ctx);

private:
	static GraphicsSystem* _system;
};

