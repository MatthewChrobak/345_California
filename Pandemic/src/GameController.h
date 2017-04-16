#pragma once
#include "RenderController.h"
#include "GameFrames.h"

class GameController : public RenderController, public GameFrame
{
public:
	GameController();
	~GameController();

	virtual void draw();
};