#include "GameView.h"

GameView::GameView(Controller* controller)
	: SfmlRenderView(controller, "Game", 960, 640), GameFrame(nullptr)
{

}