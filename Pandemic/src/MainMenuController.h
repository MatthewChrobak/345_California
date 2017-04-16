#pragma once
#include "RenderController.h"
#include "MainMenuFrames.h"
	
class MainMenuController : public RenderController, public MainMenuFrame
{
public:
	MainMenuController();
	~MainMenuController();

	virtual void draw();
};