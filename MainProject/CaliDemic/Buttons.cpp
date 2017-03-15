#include "Buttons.h"
#include "GraphicsManager.h"
#include "GuiManager.h"
#include "UITextbox.h"
#include "Frames.h"
#include "PlayerActions.h"
#include "CityCard.h"

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
	element->visible = false;
}


PlayerCardsOkay::PlayerCardsOkay(PlayerActions* action, std::vector<int>* cardData) : UIButton(CMD_PLAYER_CARDS_OKAY)
{
	this->_action = action;
	this->_cardData = cardData;

	this->surfaceName = "ui\\button.png";
	this->caption = "Okay";
	this->outlineThickness = 2;
	this->outlineColor = new RGBA(0, 0, 0);
	this->horizontalCenter = true;

	this->left = CMD_PLAYER_CARDS_OKAY_LEFT;
	this->top = CMD_PLAYER_CARDS_OKAY_TOP;
	this->width = CMD_PLAYER_CARDS_OKAY_WIDTH;
	this->height = CMD_PLAYER_CARDS_OKAY_HEIGHT;
}

void PlayerCardsOkay::onMouseDown(std::string button, int x, int y)
{
	switch (*this->_action)
	{
		case PlayerActions::Drive:

			break;
		case PlayerActions::DirectFlight:
			// We should only have one card selected here.
			if (this->_cardData->size() == 1) {
				Board* board = Game::getGameBoard();
				Player& player = board->getCurrentTurnPlayer();
				
				// Get the card index.
				int cardIndex = this->_cardData->at(0);
				PlayerCard* card = player.getCard(cardIndex);

				// Make sure the card is not null.
				if (card != nullptr) {

					// Make sure it's a city card.
					if (card->getType() == PlayerCardType::City_Card) {
						CityCard* cityCard = (CityCard*)card;
						int cityIndex = cityCard->cityIndex;

						// Remove it, move the player, and hide the player cards.
						player.removeCard(cardIndex);
						player.pawn->cityIndex = cityIndex;
						GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = false;

						// TODO: Decrement the player actions.
					}
					else {
						GuiManager::showMsgBox("Please select a city card.");
					}
				}
				else {
					GuiManager::showMsgBox("Card was null.");
				}
			}
			else {
				GuiManager::showMsgBox("Please select only one card.");
			}
			break;
		case PlayerActions::CharterFlight:

			
			//select atleast 1 card
			if (this->_cardData->size() != 1){
				GuiManager::showMsgBox("Please select only one card.");
			}else
			{
						Board* board = Game::getGameBoard();
						Player& player = board->getCurrentTurnPlayer();

						// Get the card index.
						int cardIndex = this->_cardData->at(0);
						PlayerCard* card = player.getCard(cardIndex);

						//if the player's current city === selected card move there 
						if (player.pawn->cityIndex == cardIndex){
							int x = cardIndex;
							player.pawn->cityIndex = x;
							player.removeCard(cardIndex);
							GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = false;
						
			}
					
					
					
					
			}





			break;
		case PlayerActions::ShuttleFlight:

			break;
		case PlayerActions::BuildResearchCenter:

			break;
		case PlayerActions::TreatDisease:

			break;
		case PlayerActions::ShareKnowledge:

			break;
		case PlayerActions::DiscoverCure:

			break;
		case PlayerActions::ViewCards:
			GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = false;
			break;
	}
}




ToggleMapEditingActions::ToggleMapEditingActions() : UIButton(CMD_TOGGLE_MAP_EDITING_ACTIONS)
{
	this->surfaceName = "ui\\button.png";
	this->caption = "Show Tools";
	this->width = CMD_TOGGLE_ACTIONS_WIDTH;
	this->height = CMD_TOGGLE_ACITONS_HEIGHT;
	this->visible = false;

	this->left = DRAW_WIDTH - this->width - 10;
	this->top = DRAW_HEIGHT - this->height - 10;
}

void ToggleMapEditingActions::onMouseDown(std::string button, int x, int y)
{
	auto element = GuiManager::getUIElementByName(FRM_MAP_EDITING_ACTIONS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
	element->visible = !element->visible;
}

SelectNodeAction::SelectNodeAction() : UIButton(CMD_SELECT_NODE)
{
	this->caption = "Select Node";
	this->hoverSurfaceName = "ui\\lightbox.png";
	this->width = FRM_MAP_EDITING_ACTIONS_WIDTH;
	this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

	this->top = FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::SelectNode;
	this->left = FRM_MAP_EDITING_ACTIONS_LEFT;
}
void SelectNodeAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::SelectNode;
}

RotateNodeAngleAction::RotateNodeAngleAction() : UIButton(CMD_SELECT_NODE)
{
	this->caption = "Rotate Angle";
	this->width = FRM_MAP_EDITING_ACTIONS_WIDTH;
	this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

	this->top = FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::RotateAngle;
	this->left = FRM_MAP_EDITING_ACTIONS_LEFT;
}
void RotateNodeAngleAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::RotateAngle;
}

AddNodeAction::AddNodeAction() : UIButton(CMD_ADD_NODE)
{
	this->caption = "Add Node";
	this->hoverSurfaceName = "ui\\lightbox.png";
	this->width = FRM_MAP_EDITING_ACTIONS_WIDTH;
	this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

	this->top = FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::AddNode;
	this->left = FRM_MAP_EDITING_ACTIONS_LEFT;
}
void AddNodeAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::AddNode;
}



MakeNodeBlackAction::MakeNodeBlackAction() : UIButton(CMD_MAKE_NODE_BLACK)
{
	this->caption = "Make Black";
	this->hoverSurfaceName = "ui\\lightbox.png";
	this->width = FRM_MAP_EDITING_ACTIONS_WIDTH;
	this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

	this->top = FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::MakeNodeBlack;
	this->left = FRM_MAP_EDITING_ACTIONS_LEFT;
}
void MakeNodeBlackAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::MakeNodeBlack;
}



MakeNodeRedAction::MakeNodeRedAction() : UIButton(CMD_MAKE_NODE_RED)
{
	this->caption = "Make Red";
	this->hoverSurfaceName = "ui\\lightbox.png";
	this->width = FRM_MAP_EDITING_ACTIONS_WIDTH;
	this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

	this->top = FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::MakeNodeRed;
	this->left = FRM_MAP_EDITING_ACTIONS_LEFT;
}
void MakeNodeRedAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::MakeNodeRed;
}


MakeNodeYellowAction::MakeNodeYellowAction() : UIButton(CMD_MAKE_NODE_YELLOW)
{
	this->caption = "Make Yellow";
	this->hoverSurfaceName = "ui\\lightbox.png";
	this->width = FRM_MAP_EDITING_ACTIONS_WIDTH;
	this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

	this->top = FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::MakeNodeYellow;
	this->left = FRM_MAP_EDITING_ACTIONS_LEFT;
}
void MakeNodeYellowAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::MakeNodeYellow;
}


MakeNodeBlueAction::MakeNodeBlueAction() : UIButton(CMD_MAKE_NODE_BLUE)
{
	this->caption = "Make Blue";
	this->hoverSurfaceName = "ui\\lightbox.png";
	this->width = FRM_MAP_EDITING_ACTIONS_WIDTH;
	this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

	this->top = FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::MakeNodeBlue;
	this->left = FRM_MAP_EDITING_ACTIONS_LEFT;
}
void MakeNodeBlueAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::MakeNodeBlue;
}


ChangeNodeNameAction::ChangeNodeNameAction() : UIButton(CMD_CHANGE_NODE_NAME)
{
	this->caption = "Rename Node";
	this->hoverSurfaceName = "ui\\lightbox.png";
	this->width = FRM_MAP_EDITING_ACTIONS_WIDTH;
	this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

	this->top = FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::ChangeNodeName;
	this->left = FRM_MAP_EDITING_ACTIONS_LEFT;
}
void ChangeNodeNameAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::ChangeNodeName;
}


MakeDirectedEdgeAction::MakeDirectedEdgeAction() : UIButton(CMD_MAKE_DIRECTED_EDGE)
{
	this->caption = "Make Edge";
	this->hoverSurfaceName = "ui\\lightbox.png";
	this->width = FRM_MAP_EDITING_ACTIONS_WIDTH;
	this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

	this->top = FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::MakeDirectedEdge;
	this->left = FRM_MAP_EDITING_ACTIONS_LEFT;
}
void MakeDirectedEdgeAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::MakeDirectedEdge;
}



MoveNodeAction::MoveNodeAction() : UIButton(CMD_MOVE_NODE)
{
	this->caption = "MoveNode";
	this->hoverSurfaceName = "ui\\lightbox.png";
	this->width = FRM_MAP_EDITING_ACTIONS_WIDTH;
	this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

	this->top = FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::MoveNode;
	this->left = FRM_MAP_EDITING_ACTIONS_LEFT;
}
void MoveNodeAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::MoveNode;
}


FinishedEditingMapAction::FinishedEditingMapAction() : UIButton(CMD_FINISHED_MAP_EDITING)
{
	this->caption = "Done Editing";
	this->hoverSurfaceName = "ui\\lightbox.png";
	this->width = FRM_MAP_EDITING_ACTIONS_WIDTH;
	this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

	this->top = FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::FinishedEditingMap;
	this->left = FRM_MAP_EDITING_ACTIONS_LEFT;
}
void FinishedEditingMapAction::onMouseDown(std::string button, int x, int y)
{
	auto element = GuiManager::getUIElementByName(FRM_GAME_FRAME);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
	((GameFrame*)element)->finishedEditing();
}