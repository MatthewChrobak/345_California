#pragma once
#include "UIButton.h"

// The button that's meant to transition the game from the main menu to the game.
struct PlayGameButton : public UIButton
{
	PlayGameButton(UIElement* parent);
	bool onMouseDown(std::string button, int x, int y);
};