#pragma once
#include <string>

class Controller
{
public:
	virtual void handleMouseDown(int x, int y, std::string button) = 0;
	virtual void handleMouseUp(int x, int y, std::string button) = 0;
	virtual void handleMouseMove(int x, int y) = 0;

	virtual void handleKeyDown(std::string key) = 0;
	virtual void handleKeyUp(std::string key) = 0;

	virtual void draw() = 0;
};