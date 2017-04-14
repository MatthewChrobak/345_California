#pragma once
#include "RenderController.h"
	
class MainMenuController : public RenderController
{
public:
	MainMenuController();
	~MainMenuController();

	virtual void handleMouseDown(int x, int y, std::string button);
	virtual void handleMouseUp(int x, int y, std::string button);
	virtual void handleMouseMove(int x, int y);

	virtual void handleKeyDown(std::string key);
	virtual void handleKeyUp(std::string key);

	virtual void draw();
};