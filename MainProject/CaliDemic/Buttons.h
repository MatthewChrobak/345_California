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


// Buttons in the player actions menu.
struct DrivePlayerAction : public UIButton
{
	DrivePlayerAction();
	void onMouseDown(std::string button, int x, int y);
};

struct DirectFlightPlayerAction : public UIButton
{
	DirectFlightPlayerAction();
	void onMouseDown(std::string button, int x, int y);
};

struct CharterFlightAction : public UIButton
{
	CharterFlightAction();
	void onMouseDown(std::string button, int x, int y);
};

struct ShuttleFlightAction : public UIButton
{
	ShuttleFlightAction();
	void onMouseDown(std::string button, int x, int y);
};

struct BuildResearchCenterAction : public UIButton
{
	BuildResearchCenterAction();
	void onMouseDown(std::string button, int x, int y);
};

struct TreatDiseaseAction : public UIButton
{
	TreatDiseaseAction();
	void onMouseDown(std::string button, int x, int y);
};

struct ShareKnowledgeAction : public UIButton
{
	ShareKnowledgeAction();
	void onMouseDown(std::string button, int x, int y);
};

struct DiscoverCureAction : public UIButton
{
	DiscoverCureAction();
	void onMouseDown(std::string button, int x, int y);
};

struct ViewCardsAction : public UIButton
{
	ViewCardsAction();
	void onMouseDown(std::string button, int x, int y);
};


struct PlayerCardsClose : public UIButton
{
	PlayerCardsClose();
	void onMouseDown(std::string button, int x, int y);
};