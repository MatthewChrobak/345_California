#pragma once
#include "GraphicsSystem.h"
#include <string>

class GraphicsManager
{
public:
	static void initialize();
	static void destroy();
	static void draw();
	static void renderSurface(std::string surfaceName, SurfaceContext& ctx);
	static void renderText(std::string text, TextContext& ctx);

private:
	static GraphicsSystem* _system;
};
