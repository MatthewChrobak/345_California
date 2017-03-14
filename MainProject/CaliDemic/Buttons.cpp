#include "Buttons.h"
#include "GraphicsManager.h"
#include "GuiManager.h"
#include "UITextbox.h"
#include "Frames.h"
#include "PlayerActions.h"

ToggleActionsButton::ToggleActionsButton() : UIButton(CMD_TOGGLE_ACTIONS)
{
	this->surfaceName = "ui\\button.png";
	this->caption = "View Actions";
	this->width = CMD_TOGGLE_ACTIONS_WIDTH;
	this->height = CMD_TOGGLE_ACITONS_HEIGHT;

	this->left = DRAW_WIDTH - this->width - 10;
	this->top = DRAW_HEIGHT - this->height - 10;
}

void ToggleActionsButton::onMouseDown(std::string button, int x, int y)
{
	auto element = GuiManager::getUIElementByName(FRM_PLAYER_ACTIONS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
	element->visible = !element->visible;
}





PlayGameButton::PlayGameButton() : UIButton(CMD_PLAY_GAME_BUTTON)
{
	this->width = DRAW_WIDTH / 2;
	this->height = 50;
	this->caption = "play game";
	this->outlineColor = new RGBA(0, 0, 0);
	this->outlineThickness = 2;
	this->left = this->width - this->width / 2;
	this->top = DRAW_HEIGHT / 2 + 150;
	this->fontSize = 48;
}

void PlayGameButton::onMouseDown(std::string button, int x, int y)
{
	auto element = GuiManager::getUIElementByName(TXT_SAVE_NAME);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_TEXTBOX);
#endif
	// Get the name of the game.
	std::string text = ((UITextbox*)element)->text;

	// Make sure the name is valid.
	if (text.size() > 0)
	{
		Game::loadOrCreate(text);
	}
}



DrivePlayerAction::DrivePlayerAction() : UIButton(CMD_PLAYER_ACTION_DRIVE)
{
	this->caption = "Drive";
	this->hoverSurfaceName = "ui\\lightbox.png";
	this->width = FRM_PLAYER_ACTIONS_WIDTH;
	this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

	this->top = FRM_PLAYER_ACTIONS_TOP;
	this->left = FRM_PLAYER_ACTIONS_LEFT;
}

void DrivePlayerAction::onMouseDown(std::string key, int x, int y)
{
	auto element = GuiManager::getUIElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
	((PlayerCardsFrame*)element)->show(PlayerActions::Drive);
}

DirectFlightPlayerAction::DirectFlightPlayerAction() : UIButton(CMD_PLAYER_ACTION_DIRECT_FLIGHT)
{
	this->caption = "Direct Flight";
	this->hoverSurfaceName = "ui\\lightbox.png";
	this->width = FRM_PLAYER_ACTIONS_WIDTH;
	this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

	this->top = FRM_PLAYER_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * PlayerActions::DirectFlight;
	this->left = FRM_PLAYER_ACTIONS_LEFT;
}

void DirectFlightPlayerAction::onMouseDown(std::string key, int x, int y)
{
	auto element = GuiManager::getUIElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
	((PlayerCardsFrame*)element)->show(PlayerActions::DirectFlight);
}

CharterFlightAction::CharterFlightAction() : UIButton(CMD_PLAYER_ACTION_CHARTER_FLIGHT)
{
	this->caption = "Charter Flight";
	this->hoverSurfaceName = "ui\\lightbox.png";
	this->width = FRM_PLAYER_ACTIONS_WIDTH;
	this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

	this->top = FRM_PLAYER_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * PlayerActions::CharterFlight;
	this->left = FRM_PLAYER_ACTIONS_LEFT;
}

void CharterFlightAction::onMouseDown(std::string key, int x, int y)
{
	auto element = GuiManager::getUIElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
	((PlayerCardsFrame*)element)->show(PlayerActions::CharterFlight);
}

ShuttleFlightAction::ShuttleFlightAction() : UIButton(CMD_PLAYER_ACTION_SHUTTLE_FLIGHT)
{
	this->caption = "Shuttle Flight";
	this->hoverSurfaceName = "ui\\lightbox.png";
	this->width = FRM_PLAYER_ACTIONS_WIDTH;
	this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

	this->top = FRM_PLAYER_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * PlayerActions::ShuttleFlight;
	this->left = FRM_PLAYER_ACTIONS_LEFT;
}

void ShuttleFlightAction::onMouseDown(std::string key, int x, int y)
{
	auto element = GuiManager::getUIElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
	((PlayerCardsFrame*)element)->show(PlayerActions::ShuttleFlight);
}

BuildResearchCenterAction::BuildResearchCenterAction() : UIButton(CMD_PLAYER_ACTION_BUILD_RESEARCH_CENTER)
{
	this->caption = "Build Research Center";
	this->hoverSurfaceName = "ui\\lightbox.png";
	this->width = FRM_PLAYER_ACTIONS_WIDTH;
	this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

	this->top = FRM_PLAYER_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * PlayerActions::BuildResearchCenter;
	this->left = FRM_PLAYER_ACTIONS_LEFT;
}

void BuildResearchCenterAction::onMouseDown(std::string key, int x, int y)
{
	auto element = GuiManager::getUIElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
	((PlayerCardsFrame*)element)->show(PlayerActions::BuildResearchCenter);
}

TreatDiseaseAction::TreatDiseaseAction() : UIButton(CMD_PLAYER_ACTION_TREAT_DISEASE)
{
	this->caption = "Treat Disease";
	this->hoverSurfaceName = "ui\\lightbox.png";
	this->width = FRM_PLAYER_ACTIONS_WIDTH;
	this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

	this->top = FRM_PLAYER_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * PlayerActions::TreatDisease;
	this->left = FRM_PLAYER_ACTIONS_LEFT;
}

void TreatDiseaseAction::onMouseDown(std::string key, int x, int y)
{
	auto element = GuiManager::getUIElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
	((PlayerCardsFrame*)element)->show(PlayerActions::TreatDisease);
}

ShareKnowledgeAction::ShareKnowledgeAction() : UIButton(CMD_PLAYER_ACTION_SHARE_KNOWLEDGE)
{
	this->caption = "Share Knowledge";
	this->hoverSurfaceName = "ui\\lightbox.png";
	this->width = FRM_PLAYER_ACTIONS_WIDTH;
	this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

	this->top = FRM_PLAYER_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * PlayerActions::ShareKnowledge;
	this->left = FRM_PLAYER_ACTIONS_LEFT;
}

void ShareKnowledgeAction::onMouseDown(std::string key, int x, int y)
{
	auto element = GuiManager::getUIElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
	((PlayerCardsFrame*)element)->show(PlayerActions::ShareKnowledge);
}


DiscoverCureAction::DiscoverCureAction() : UIButton(CMD_PLAYER_ACTION_DISCOVER_CURE)
{
	this->caption = "Discover Cure";
	this->hoverSurfaceName = "ui\\lightbox.png";
	this->width = FRM_PLAYER_ACTIONS_WIDTH;
	this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

	this->top = FRM_PLAYER_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * PlayerActions::DiscoverCure;
	this->left = FRM_PLAYER_ACTIONS_LEFT;
}

void DiscoverCureAction::onMouseDown(std::string key, int x, int y)
{
	auto element = GuiManager::getUIElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
	((PlayerCardsFrame*)element)->show(PlayerActions::DiscoverCure);
}


ViewCardsAction::ViewCardsAction() : UIButton(CMD_PLAYER_ACTION_VIEW_CARDS)
{
	this->caption = "View Cards";
	this->hoverSurfaceName = "ui\\lightbox.png";
	this->width = FRM_PLAYER_ACTIONS_WIDTH;
	this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

	this->top = FRM_PLAYER_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * PlayerActions::ViewCards;
	this->left = FRM_PLAYER_ACTIONS_LEFT;
}

void ViewCardsAction::onMouseDown(std::string key, int x, int y)
{
	auto element = GuiManager::getUIElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
	((PlayerCardsFrame*)element)->show(PlayerActions::ViewCards);
}



PlayerCardsClose::PlayerCardsClose() : UIButton(CMD_PLAYER_CARDS_CLOSE)
{
	this->surfaceName = "ui\\close.png";
	this->width = CMD_PLAYER_CARDS_CLOSE_WIDTH;
	this->height = CMD_PLAYER_CARDS_CLOSE_HEIGHT;

	this->left = FRM_PLAYER_CARDS_WIDTH - CMD_PLAYER_CARDS_CLOSE_WIDTH - 10;
	this->top = 10;
}

void PlayerCardsClose::onMouseDown(std::string button, int x, int y)
{
	auto element = GuiManager::getUIElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
	((PlayerCardsFrame*)element)->resetShow();
}