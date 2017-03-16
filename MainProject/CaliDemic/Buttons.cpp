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
	GameFrame::PlayerAction = PlayerActions::Drive;
	GuiManager::showMsgBox("Please click on a city you wish to drive to.");
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
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction);
#endif
	GameFrame::PlayerAction = PlayerActions::DirectFlight;
	((PlayerCardsFrame*)element)->show();
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
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction);
#endif
	GameFrame::PlayerAction = PlayerActions::CharterFlight;
	((PlayerCardsFrame*)element)->show();
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
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction);
#endif
	GameFrame::PlayerAction = PlayerActions::ShuttleFlight;
	((PlayerCardsFrame*)element)->show();
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
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction);
#endif
	GameFrame::PlayerAction = PlayerActions::BuildResearchCenter;
	((PlayerCardsFrame*)element)->show();
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
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction);
#endif
	GameFrame::PlayerAction = PlayerActions::TreatDisease;
	((PlayerCardsFrame*)element)->show();
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
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction);
#endif
	GameFrame::PlayerAction = PlayerActions::ShareKnowledge;
	((PlayerCardsFrame*)element)->show();
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
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction);
#endif
	GameFrame::PlayerAction = PlayerActions::DiscoverCure;
	((PlayerCardsFrame*)element)->show();
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
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction);
#endif
	GameFrame::PlayerAction = PlayerActions::ViewCards;
	((PlayerCardsFrame*)element)->show();
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


PlayerCardsOkay::PlayerCardsOkay(std::vector<int>* cardData) : UIButton(CMD_PLAYER_CARDS_OKAY)
{
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
	Board* board = Game::getGameBoard();
	Player& player = board->getCurrentTurnPlayer();

	switch (GameFrame::PlayerAction)
	{
		case PlayerActions::Drive:
		break;
		
		case PlayerActions::DirectFlight:
			// We should only have one card selected here.
			if (this->_cardData->size() == 1) {
				
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
						decrementActionCounter();
						GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = false;
						// Reset the player action.
						GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
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
			//select at least 1 card
			if (this->_cardData->size() != 1)
			{
				GuiManager::showMsgBox("Please select only one card.");
			}
			else
			{
				// Get the card index.
				int cardIndex = this->_cardData->at(0);
				PlayerCard* card = player.getCard(cardIndex);

				//if the player's current city == selected card move there 
				if (player.pawn->cityIndex == cardIndex)
				{
					int x = cardIndex;
					player.pawn->cityIndex = x;
					player.removeCard(cardIndex);
					decrementActionCounter();
					GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = false;	
					//reset player Actions
					GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
				}
		
			}

			break;
		case PlayerActions::ShuttleFlight:

			/*
			When the player successfully finishes an action, ensure that the action is reset by writing the line
			GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
			Failure to do so will cause assertions to fail and will cause the application to crash.
			*/
			GameFrame::PlayerAction = PlayerActions::NoPlayerAction;

			break;
		case PlayerActions::BuildResearchCenter:
			//select only one card
			if (this->_cardData->size() != 1)
				GuiManager::showMsgBox("Please select only one card.");

			//correct selection than check if we have enough research center
			else
			{
				// Get the card index.
				int cardIndex = this->_cardData->at(0);
				PlayerCard* card = player.getCard(cardIndex);
				//check if the card is null or if the card is not city card type
				if(card != nullptr && card->getType() == PlayerCardType::City_Card)
				{
					//check if we have enough research center
					if (Game::numOfResearchCenter > 0)
					{
						if (Game::getGameBoard()->getCity(player.pawn->cityIndex)->research != true)
						{
							//check if the player is current city match with the city card
							if (player.pawn->cityIndex == cardIndex)
							{
								Game::getGameBoard()->getCity(player.pawn->cityIndex)->research = true;
								player.removeCard(cardIndex);
								Game::numOfResearchCenter--;
								decrementActionCounter();
								//reset player actions
								GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
							}
							else
								GuiManager::showMsgBox("You current position does not match the selected city card.");
						}
						else
							GuiManager::showMsgBox("All research centers have been used.");
					}
					else
						GuiManager::showMsgBox("The research facility is already built in this city.");
				}
				else
					GuiManager::showMsgBox("The card is either null or you did not select a city");
			}
			break;
		case PlayerActions::TreatDisease:
			/*
			When the player successfully finishes an action, ensure that the action is reset by writing the line
			GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
			Failure to do so will cause assertions to fail and will cause the application to crash.
			*/
			GameFrame::PlayerAction = PlayerActions::NoPlayerAction;

			break;
		case PlayerActions::ShareKnowledge:
			/*
			When the player successfully finishes an action, ensure that the action is reset by writing the line
			GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
			Failure to do so will cause assertions to fail and will cause the application to crash.
			*/
			GameFrame::PlayerAction = PlayerActions::NoPlayerAction;

			break;
		case PlayerActions::DiscoverCure:
			/*
			When the player successfully finishes an action, ensure that the action is reset by writing the line
			GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
			Failure to do so will cause assertions to fail and will cause the application to crash.
			*/
			GameFrame::PlayerAction = PlayerActions::NoPlayerAction;

			break;
		case PlayerActions::ViewCards:
			GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = false;
			break;
	}

	//If turn is changed, show this message
	if (board->playerTurnChange() == true) {
		GuiManager::showMsgBox("End of your turn.");
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