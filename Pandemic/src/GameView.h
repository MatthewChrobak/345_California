#pragma once
#include "SfmlRenderView.h"
#include "GameFrames.h"

class GameView : public SfmlRenderView, public GameFrame
{
public:
	GameView(Controller* controller);
};