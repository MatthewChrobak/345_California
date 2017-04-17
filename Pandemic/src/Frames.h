#pragma once
#include "UIFrame.h"
#include "PlayerActions.h"

// The frame that holds all UI elements whilst in game.
class GameFrame : public UIFrame
{
public:
	GameFrame();
	bool onMouseDown(std::string button, int x, int y);
	void onMouseMove(int x, int y);
	bool onKeyDown(std::string key);
	bool onKeyUp(std::string key);
	void draw();

	static MapEditingActions EditingAction;
	static PlayerActions PlayerAction;
	static int EditNodeIndex;
};

// The frame that holds all player-action buttons in game.
struct PlayerActionsFrame : public UIFrame
{
	PlayerActionsFrame();
	bool onMouseDown(std::string button, int x, int y);
};


// The frame that holds all UI elements for the main menu.
struct MainMenuFrame : public UIFrame
{
	MainMenuFrame();
};


// The frame that handles the rendering of player cards.
struct PlayerCardsFrame : public UIFrame
{
	PlayerCardsFrame();
	void draw();
	bool onMouseDown(std::string button, int x, int y);

	void show();

private:
	std::vector<int> _cardData;
};

struct NumPlayersFrame : public UIFrame 
{
	NumPlayersFrame();
};