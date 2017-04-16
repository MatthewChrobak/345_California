#pragma once
#include "UIButton.h"

// The button that's meant to toggle the visibility of the player actions frame
// while in game.
struct ToggleActionsButton : public UIButton
{
	ToggleActionsButton(UIElement* parent);
	bool onMouseDown(std::string button, int x, int y);
};


// Buttons in the player actions menu.
struct DrivePlayerAction : public UIButton
{
	DrivePlayerAction(UIElement* parent);
	bool onMouseDown(std::string button, int x, int y);
};

struct DirectFlightPlayerAction : public UIButton
{
	DirectFlightPlayerAction(UIElement* parent);
	bool onMouseDown(std::string button, int x, int y);
};

struct CharterFlightAction : public UIButton
{
	CharterFlightAction(UIElement* parent);
	bool onMouseDown(std::string button, int x, int y);
};

struct ShuttleFlightAction : public UIButton
{
	ShuttleFlightAction(UIElement* parent);
	bool onMouseDown(std::string button, int x, int y);
};

struct BuildResearchCenterAction : public UIButton
{
	BuildResearchCenterAction(UIElement* parent);
	bool onMouseDown(std::string button, int x, int y);
};

struct TreatDiseaseAction : public UIButton
{
	TreatDiseaseAction(UIElement* parent);
	bool onMouseDown(std::string button, int x, int y);
};

struct ShareKnowledgeAction : public UIButton
{
	ShareKnowledgeAction(UIElement* parent);
	bool onMouseDown(std::string button, int x, int y);
};

struct DiscoverCureAction : public UIButton
{
	DiscoverCureAction(UIElement* parent);
	bool onMouseDown(std::string button, int x, int y);
};

struct ViewCardsAction : public UIButton
{
	ViewCardsAction(UIElement* parent);
	bool onMouseDown(std::string button, int x, int y);
};

struct PlayerCardsClose : public UIButton
{
	PlayerCardsClose(UIElement* parent);
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
	ToggleMapEditingActions(UIElement* parent);
	bool onMouseDown(std::string button, int x, int y);
};

struct MoveNodeAction : public UIButton
{
	MoveNodeAction(UIElement* parent);
	bool onMouseDown(std::string button, int x, int y);
};

struct SelectNodeAction : public UIButton
{
	SelectNodeAction(UIElement* parent);
	bool onMouseDown(std::string button, int x, int y);
};

struct AddNodeAction : public UIButton
{
	AddNodeAction(UIElement* parent);
	bool onMouseDown(std::string button, int x, int y);
};

struct MakeNodeBlackAction : public UIButton
{
	MakeNodeBlackAction(UIElement* parent);
	bool onMouseDown(std::string button, int x, int y);
};

struct MakeNodeRedAction : public UIButton
{
	MakeNodeRedAction(UIElement* parent);
	bool onMouseDown(std::string button, int x, int y);
};

struct MakeNodeYellowAction : public UIButton
{
	MakeNodeYellowAction(UIElement* parent);
	bool onMouseDown(std::string button, int x, int y);
};

struct MakeNodeBlueAction : public UIButton
{
	MakeNodeBlueAction(UIElement* parent);
	bool onMouseDown(std::string button, int x, int y);
};

struct ChangeNodeNameAction : public UIButton
{
	ChangeNodeNameAction(UIElement* parent);
	bool onMouseDown(std::string button, int x, int y);
};

struct MakeDirectedEdgeAction : public UIButton
{
	MakeDirectedEdgeAction(UIElement* parent);
	bool onMouseDown(std::string button, int x, int y);
};

struct RotateNodeAngleAction : public UIButton
{
	RotateNodeAngleAction(UIElement* parent);
	bool onMouseDown(std::string button, int x, int y);
};

struct FinishedEditingMapAction : public UIButton
{
	FinishedEditingMapAction(UIElement* parent);
	bool onMouseDown(std::string button, int x, int y);
};