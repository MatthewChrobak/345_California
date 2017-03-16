#pragma once
#include "UIButton.h"
#include "PlayerActions.h"
#include <vector>

// The button that's meant to toggle the visibility of the player actions frame
// while in game.
struct ToggleActionsButton : public UIButton
{
	ToggleActionsButton();
	bool onMouseDown(std::string button, int x, int y);
};

// The button that's meant to transition the game from the main menu to the game.
struct PlayGameButton : public UIButton
{
	PlayGameButton();
	bool onMouseDown(std::string button, int x, int y);
};


// Buttons in the player actions menu.
struct DrivePlayerAction : public UIButton
{
	DrivePlayerAction();
	bool onMouseDown(std::string button, int x, int y);
};

struct DirectFlightPlayerAction : public UIButton
{
	DirectFlightPlayerAction();
	bool onMouseDown(std::string button, int x, int y);
};

struct CharterFlightAction : public UIButton
{
	CharterFlightAction();
	bool onMouseDown(std::string button, int x, int y);
};

struct ShuttleFlightAction : public UIButton
{
	ShuttleFlightAction();
	bool onMouseDown(std::string button, int x, int y);
};

struct BuildResearchCenterAction : public UIButton
{
	BuildResearchCenterAction();
	bool onMouseDown(std::string button, int x, int y);
};

struct TreatDiseaseAction : public UIButton
{
	TreatDiseaseAction();
	bool onMouseDown(std::string button, int x, int y);
};

struct ShareKnowledgeAction : public UIButton
{
	ShareKnowledgeAction();
	bool onMouseDown(std::string button, int x, int y);
};

struct DiscoverCureAction : public UIButton
{
	DiscoverCureAction();
	bool onMouseDown(std::string button, int x, int y);
};

struct ViewCardsAction : public UIButton
{
	ViewCardsAction();
	bool onMouseDown(std::string button, int x, int y);
};


struct PlayerCardsClose : public UIButton
{
	PlayerCardsClose();
	bool onMouseDown(std::string button, int x, int y);
};

struct PlayerCardsOkay : public UIButton
{
	PlayerCardsOkay(std::vector<int>* cardData);
	bool onMouseDown(std::string button, int x, int y);
private:
	std::vector<int>* _cardData;
};




struct ToggleMapEditingActions : public UIButton
{
	ToggleMapEditingActions();
	bool onMouseDown(std::string button, int x, int y);
};

struct MoveNodeAction : public UIButton
{
	MoveNodeAction();
	bool onMouseDown(std::string button, int x, int y);
};

struct SelectNodeAction : public UIButton
{
	SelectNodeAction();
	bool onMouseDown(std::string button, int x, int y);
};

struct AddNodeAction : public UIButton
{
	AddNodeAction();
	bool onMouseDown(std::string button, int x, int y);
};

struct MakeNodeBlackAction : public UIButton
{
	MakeNodeBlackAction();
	bool onMouseDown(std::string button, int x, int y);
};

struct MakeNodeRedAction : public UIButton
{
	MakeNodeRedAction();
	bool onMouseDown(std::string button, int x, int y);
};

struct MakeNodeYellowAction : public UIButton
{
	MakeNodeYellowAction();
	bool onMouseDown(std::string button, int x, int y);
};

struct MakeNodeBlueAction : public UIButton
{
	MakeNodeBlueAction();
	bool onMouseDown(std::string button, int x, int y);
};

struct ChangeNodeNameAction : public UIButton
{
	ChangeNodeNameAction();
	bool onMouseDown(std::string button, int x, int y);
};

struct MakeDirectedEdgeAction : public UIButton
{
	MakeDirectedEdgeAction();
	bool onMouseDown(std::string button, int x, int y);
};

struct RotateNodeAngleAction : public UIButton
{
	RotateNodeAngleAction();
	bool onMouseDown(std::string button, int x, int y);
};

struct FinishedEditingMapAction : public UIButton
{
	FinishedEditingMapAction();
	bool onMouseDown(std::string button, int x, int y);
};