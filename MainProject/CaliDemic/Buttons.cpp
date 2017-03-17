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

bool ToggleActionsButton::onMouseDown(std::string button, int x, int y)
{
	auto element = GuiManager::getUIElementByName(FRM_PLAYER_ACTIONS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
	element->visible = !element->visible;
	return true;
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

bool PlayGameButton::onMouseDown(std::string button, int x, int y)
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
	return true;
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

bool DrivePlayerAction::onMouseDown(std::string key, int x, int y)
{
	GameFrame::PlayerAction = PlayerActions::Drive;
	GuiManager::showMsgBox("Please click on a city you wish to drive to.");
	return true;
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

bool DirectFlightPlayerAction::onMouseDown(std::string key, int x, int y)
{
	auto element = GuiManager::getUIElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction);
#endif
	GameFrame::PlayerAction = PlayerActions::DirectFlight;
	((PlayerCardsFrame*)element)->show();
	return true;
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

bool CharterFlightAction::onMouseDown(std::string key, int x, int y)
{
	auto element = GuiManager::getUIElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction);
#endif
	GameFrame::PlayerAction = PlayerActions::CharterFlight;
	((PlayerCardsFrame*)element)->show();
	return true;
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

bool ShuttleFlightAction::onMouseDown(std::string key, int x, int y)
{
	auto element = GuiManager::getUIElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction);
#endif
	GameFrame::PlayerAction = PlayerActions::ShuttleFlight;
	((PlayerCardsFrame*)element)->show();
	return true;
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

bool BuildResearchCenterAction::onMouseDown(std::string key, int x, int y)
{
	auto element = GuiManager::getUIElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction);
#endif
	GameFrame::PlayerAction = PlayerActions::BuildResearchCenter;
	((PlayerCardsFrame*)element)->show();
	return true;
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

bool TreatDiseaseAction::onMouseDown(std::string key, int x, int y)
{
	Board* board = Game::getGameBoard();
	Player& player = board->getCurrentTurnPlayer();

	/*
	When the player successfully finishes an action, ensure that the action is reset by writing the line
	GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
	Failure to do so will cause assertions to fail and will cause the application to crash.
	*/
	int currentPlayerIndex = player.pawn->cityIndex;
	//create a city pointer to change cube counter 
	int playerRoleCardValue = player.getRoleCard()->getRoleCardVal();

	City* tempCity = board->getCity(currentPlayerIndex);

	//check if there's any cube 
	int counterNoCubes = 0;
	for (int i = 0; i < 3; i++){
		//check if medic
		if (playerRoleCardValue != 5){
			if (tempCity->cube[i] >= 0){
				tempCity->cube[i] = -1;
				counterNoCubes++;
				GuiManager::showMsgBox("One cube removed");
				break;
			}
		}
		else if (tempCity->cube[i] >= 0){
			//start another for loop to find the matching disease value 
			GuiManager::showMsgBox("You're a medic!...Removing all matching cubes! Counts as one action.");
			for (int j = 0; j < 3; j++){

				if (tempCity->cube[i] == tempCity->cube[j]){
					counterNoCubes++;
					tempCity->cube[j] = -1;
				}
			}
		}
	}

	if (counterNoCubes == 0){
		GuiManager::showMsgBox("No cubes to remove!");
	}

	GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
	return true;
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

bool ShareKnowledgeAction::onMouseDown(std::string key, int x, int y)
{
	auto element = GuiManager::getUIElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction);
#endif
	GameFrame::PlayerAction = PlayerActions::ShareKnowledge;
	((PlayerCardsFrame*)element)->show();
	return true;
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

bool DiscoverCureAction::onMouseDown(std::string key, int x, int y)
{
	auto element = GuiManager::getUIElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction);
#endif
	GameFrame::PlayerAction = PlayerActions::DiscoverCure;
	((PlayerCardsFrame*)element)->show();
	return true;
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

bool ViewCardsAction::onMouseDown(std::string key, int x, int y)
{
	auto element = GuiManager::getUIElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction);
#endif
	GameFrame::PlayerAction = PlayerActions::ViewCards;
	((PlayerCardsFrame*)element)->show();
	return true;
}

PlayerCardsClose::PlayerCardsClose() : UIButton(CMD_PLAYER_CARDS_CLOSE)
{
	this->surfaceName = "ui\\close.png";
	this->width = CMD_PLAYER_CARDS_CLOSE_WIDTH;
	this->height = CMD_PLAYER_CARDS_CLOSE_HEIGHT;

	this->left = FRM_PLAYER_CARDS_WIDTH - CMD_PLAYER_CARDS_CLOSE_WIDTH - 10;
	this->top = 10;
}

bool PlayerCardsClose::onMouseDown(std::string button, int x, int y)
{
	auto element = GuiManager::getUIElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
	element->visible = false;
	GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
	return true;
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





bool PlayerCardsOkay::onMouseDown(std::string button, int x, int y)
{
	Board* board = Game::getGameBoard();
	Player& player = board->getCurrentTurnPlayer();
	int roleCardIndex = player.getRoleCard()->getRoleCardVal();

	switch (GameFrame::PlayerAction)
	{
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
					break;
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
		return true;

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
				break;
			}

		}
		return true;
	case PlayerActions::ShuttleFlight:

		/*
		When the player successfully finishes an action, ensure that the action is reset by writing the line
		GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
		Failure to do so will cause assertions to fail and will cause the application to crash.
		*/
		GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = false;
		GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
		return true;
	case PlayerActions::BuildResearchCenter:


		if (roleCardIndex == 4){
			if (Game::numOfResearchCenter > 0)
			{
				if (Game::getGameBoard()->getCity(player.pawn->cityIndex)->research != true)
				{
					GuiManager::showMsgBox("You're operations expert! This is worth one action");
					decrementActionCounter();

					}
				else 
					GuiManager::showMsgBox("The research facility is already built in this city.");

			}
			else 
				GuiManager::showMsgBox("All research centers have been used.");

		}
		
		
		
		//select only one card
		else if (this->_cardData->size() != 1)
			GuiManager::showMsgBox("Please select only one card.");

		//correct selection than check if we have enough research center
		else
		{
			// Get the card index.
			int cardIndex = this->_cardData->at(0);
			PlayerCard* card = player.getCard(cardIndex);
			//check if the card is null or if the card is not city card type
			if (card != nullptr && card->getType() == PlayerCardType::City_Card)
			{
				//check if we have enough research center
				if (Game::numOfResearchCenter > 0)
				{
					if (Game::getGameBoard()->getCity(player.pawn->cityIndex)->research != true)
					{
						//check if the player is current city match with the city card
						if (player.pawn->cityIndex == ((CityCard*)card)->cityIndex)
						{
							Game::getGameBoard()->getCity(player.pawn->cityIndex)->research = true;
							player.removeCard(cardIndex);
							Game::numOfResearchCenter--;
							decrementActionCounter();
							//reset player actions
							GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
							break;
						}
						else
							GuiManager::showMsgBox("You current position does not match the selected city card.");
					}
					else
						GuiManager::showMsgBox("The research facility is already built in this city.");
				}
				else
					GuiManager::showMsgBox("All research centers have been used.");
			}
			else
				GuiManager::showMsgBox("The card is either null or you did not select a city");
		}
		return true;
     
		case PlayerActions::ShareKnowledge:
			/*
			When the player successfully finishes an action, ensure that the action is reset by writing the line
			GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
			Failure to do so will cause assertions to fail and will cause the application to crash.
			*/
			GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
			break;


		case PlayerActions::DiscoverCure:
		{
			int requiredCardCount = 5;
			bool medic = false;

			// Figure out if we're a medic or not.
			if (roleCardIndex == 5) {
				requiredCardCount = 4;
				medic = true;
			}

			// Did we select enough cards?
			if (this->_cardData->size() == requiredCardCount) {

				// Are they all city cards?
				for (int i = 0; i < requiredCardCount; i++) {
					if (player.getCard(this->_cardData->at(i))->getType() != PlayerCardType::City_Card) {
						GuiManager::showMsgBox("You must select city cards only.");
						return true;
					}
				}

				// Ensure they're the same color.
				for (int i = 1; i < requiredCardCount; i++) {
					CityCard* cityCard0 = (CityCard*)player.getCard(this->_cardData->at(i - 1));
					CityCard* cityCard1 = (CityCard*)player.getCard(this->_cardData->at(i));
					City* city0 = board->getCity(cityCard0->cityIndex);
					City* city1 = board->getCity(cityCard1->cityIndex);

					if (city0->color ^ city0->color) {
						GuiManager::showMsgBox("You must select the same color cards.");
						return true;
					}
				}

				// Make sure it hasn't been cured already.
				InfectionColor color = Game::getGameBoard()->getCity(((CityCard*)player.getCard(this->_cardData->at(0)))->cityIndex)->color;
				if (board->isCured[color]) {
					GuiManager::showMsgBox("This disease has already been cured!");
					return true;
				}

				// Remove all the cards.
				for (int i = 0; i < this->_cardData->size(); i++) {
					player.removeCard(this->_cardData->at(i));
				}

				// Cure the disease.
				board->isCured[color] = true;
				GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = false;
				GuiManager::showMsgBox("The disease has been cured.");
				GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
				decrementActionCounter();
			} else {
				GuiManager::showMsgBox("You need to select " + std::to_string(roleCardIndex) + " cards.");
			}
		}

		/*
		When the player successfully finishes an action, ensure that the action is reset by writing the line
		GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
		Failure to do so will cause assertions to fail and will cause the application to crash.
		*/
		return true;

	case PlayerActions::ViewCards:
		GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = false;
		GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
		return true;


	case PlayerActions::DiscardCards:
		int numberOfCards = player.getNumberOfCards();
		int numberOfDiscards = (numberOfCards + 2) % 7;

		if (this->_cardData->size() == numberOfDiscards) {

			for (int i = 0; i < numberOfDiscards; i++)
			{
				int cardIndex1 = this->_cardData->at(0);
				player.removeCard(cardIndex1);
			}
		}
		else {
			GuiManager::showMsgBox("You must select " + std::to_string(numberOfCards) + " cards.");
		}
		break;
	}


	//If turn is changed, show this message
	if (board->playerTurnChange() == true) 
	{

		GuiManager::showMsgBox("Your current hand after picking two cards.");
		GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = true;


		int numberOfCards = player.getNumberOfCards();

		if (numberOfCards >= 6) //You only excess cards only when you draw while you have 6 or more cards
		{
			GuiManager::showMsgBox("Please discard " + std::to_string((numberOfCards + 2) % 7) + " cards.");
			GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = true;// show message that we have to discard.
			GameFrame::PlayerAction = PlayerActions::DiscardCards;

		}
		//City::infectCity()

		GuiManager::showMsgBox("End of your turn.");
	}

	return true;
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

bool ToggleMapEditingActions::onMouseDown(std::string button, int x, int y)
{
	auto element = GuiManager::getUIElementByName(FRM_MAP_EDITING_ACTIONS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
	element->visible = !element->visible;
	return true;
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
bool SelectNodeAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::SelectNode;
	return true;
}

RotateNodeAngleAction::RotateNodeAngleAction() : UIButton(CMD_SELECT_NODE)
{
	this->caption = "Rotate Angle";
	this->width = FRM_MAP_EDITING_ACTIONS_WIDTH;
	this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

	this->top = FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::RotateAngle;
	this->left = FRM_MAP_EDITING_ACTIONS_LEFT;
}
bool RotateNodeAngleAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::RotateAngle;
	return true;
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
bool AddNodeAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::AddNode;
	return true;
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
bool MakeNodeBlackAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::MakeNodeBlack;
	return true;
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
bool MakeNodeRedAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::MakeNodeRed;
	return true;
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
bool MakeNodeYellowAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::MakeNodeYellow;
	return true;
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
bool MakeNodeBlueAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::MakeNodeBlue;
	return true;
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
bool ChangeNodeNameAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::ChangeNodeName;
	return true;
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
bool MakeDirectedEdgeAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::MakeDirectedEdge;
	return true;
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
bool MoveNodeAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::MoveNode;
	return true;
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
bool FinishedEditingMapAction::onMouseDown(std::string button, int x, int y)
{
	auto element = GuiManager::getUIElementByName(FRM_GAME_FRAME);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
	((GameFrame*)element)->finishedEditing();
	return true;
}