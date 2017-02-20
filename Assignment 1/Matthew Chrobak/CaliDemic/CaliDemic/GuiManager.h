#pragma once
#include <vector>
#include <string>
#include "Game.h"

#define DRAW_WIDTH 960
#define DRAW_HEIGHT 640

class GuiManager
{
public:
	static void handleMouseDown(int x, int y, std::string button);
	static void handleMouseUp(int x, int y, std::string button);
	static void handleMouseMove(int x, int y);
	static void handleKeyDown(char key);
	static void handleKeyUp(char key);
	static void handleWindowResize(int x, int y);

	static int WindowWidth;
	static int WindowHeight;

	static void draw();

private:
	static void convertCoords(int* x, int* y);

#ifdef ADMIN_EDITOR
	static bool teleportNode;
	static bool connectNode;
	static bool moveMode;
	static bool addNode;
#endif
};