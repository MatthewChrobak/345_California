/*!
	Author: Matthew Chrobak
	Contributors:

	Purpose: A god-class designed to allow static access to the graphics implementation.
*/
#pragma once
#include "GraphicsSystem.h"

#define DRAW_WIDTH 960
#define DRAW_HEIGHT 640

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