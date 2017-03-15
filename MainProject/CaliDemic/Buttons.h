#pragma once
#include "UIButton.h"
#include "PlayerActions.h"
#include <vector>

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

struct PlayerCardsOkay : public UIButton
{
	PlayerCardsOkay(PlayerActions* action, std::vector<int>* cardData);
	void onMouseDown(std::string button, int x, int y);
private:
	PlayerActions* _action;
	std::vector<int>* _cardData;
};




struct ToggleMapEditingActions : public UIButton
{
	ToggleMapEditingActions();
	void onMouseDown(std::string button, int x, int y);
};

struct MoveNodeAction : public UIButton
{
	MoveNodeAction();
	void onMouseDown(std::string button, int x, int y);
};

struct SelectNodeAction : public UIButton
{
	SelectNodeAction();
	void onMouseDown(std::string button, int x, int y);
};

struct AddNodeAction : public UIButton
{
	AddNodeAction();
	void onMouseDown(std::string button, int x, int y);
};

struct MakeNodeBlackAction : public UIButton
{
	MakeNodeBlackAction();
	void onMouseDown(std::string button, int x, int y);
};

struct MakeNodeRedAction : public UIButton
{
	MakeNodeRedAction();
	void onMouseDown(std::string button, int x, int y);
};

struct MakeNodeYellowAction : public UIButton
{
	MakeNodeYellowAction();
	void onMouseDown(std::string button, int x, int y);
};

struct MakeNodeBlueAction : public UIButton
{
	MakeNodeBlueAction();
	void onMouseDown(std::string button, int x, int y);
};

struct ChangeNodeNameAction : public UIButton
{
	ChangeNodeNameAction();
	void onMouseDown(std::string button, int x, int y);
};

struct MakeDirectedEdgeAction : public UIButton
{
	MakeDirectedEdgeAction();
	void onMouseDown(std::string button, int x, int y);
};

struct RotateNodeAngleAction : public UIButton
{
	RotateNodeAngleAction();
	void onMouseDown(std::string button, int x, int y);
};

struct FinishedEditingMapAction : public UIButton
{
	FinishedEditingMapAction();
	void onMouseDown(std::string button, int x, int y);
};