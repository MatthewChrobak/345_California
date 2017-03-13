#pragma once
#include "UIButton.h"

// The button that's meant to toggle the visibility of the player actions frame
// while in game.
struct ToggleActionsButton : public UIButton
{
	ToggleActionsButton();
	void onMouseDown(std::string button, int x, int y);
};

// The button that's meant to transition the game from the main menu to the game.
struct PlayGameButton : public UIButton
{
	PlayGameButton();
	void onMouseDown(std::string button, int x, int y);
};