#pragma once
#include "UIFrame.h"
#include "PlayerActions.h"

// The frame that holds all UI elements whilst in game.
class GameFrame : public UIFrame
{
public:
	GameFrame();
	void onMouseDown(std::string button, int x, int y);
	void onMouseMove(int x, int y);
	void onKeyDown(std::string key);
	void onKeyUp(std::string key);
	void draw();

	void showAdminTools();
	void finishedEditing();

	static MapEditingActions EditingAction;
	static int EditNodeIndex;

private:
	bool _editing = false;
};

// The frame that holds all player-action buttons in game.
struct PlayerActionsFrame : public UIFrame
{
	PlayerActionsFrame();
	void onMouseDown(std::string button, int x, int y);
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
	void onMouseDown(std::string button, int x, int y);

	void show(PlayerActions action);

private:
	PlayerActions _currentAction;
	std::vector<int> _cardData;
};

// The frame that contains the map-editing actions.
struct MapEditingActionsFrame : public UIFrame
{
	MapEditingActionsFrame();
	void draw();
};