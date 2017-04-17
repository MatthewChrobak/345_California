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
	static void destroy();

	static GraphicsSystem& getInstance();

private:
	static GraphicsSystem* _system;
};