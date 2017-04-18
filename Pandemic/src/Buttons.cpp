#include "Buttons.h"
#include "GraphicsManager.h"
#include "GuiManager.h"
#include "UITextbox.h"
#include "Frames.h"
#include "PlayerActions.h"
#include "CityCard.h"
#include "BoardBuilder.h"
#include "EventCard.h"

ToggleActionsButton::ToggleActionsButton() : UIButton(CMD_TOGGLE_ACTIONS)
{
	this->surfaceName = "ui/button.png";
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
	this->getOutline().setColor(0, 0, 0);
	this->getOutline().setThickness(2);
	this->left = this->width - this->width / 2;
	this->top = DRAW_HEIGHT / 2 + 150;
	this->setFontSize(48);
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
	this->hoverSurfaceName = "ui/lightbox.png";
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
	this->hoverSurfaceName = "ui/lightbox.png";
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
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction || GameFrame::PlayerAction == PlayerActions::Drive);
#endif
	GameFrame::PlayerAction = PlayerActions::DirectFlight;
	((PlayerCardsFrame*)element)->show();
	return true;
}

CharterFlightAction::CharterFlightAction() : UIButton(CMD_PLAYER_ACTION_CHARTER_FLIGHT)
{
	this->caption = "Charter Flight";
	this->hoverSurfaceName = "ui/lightbox.png";
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
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction || GameFrame::PlayerAction == PlayerActions::Drive);
#endif
	GameFrame::PlayerAction = PlayerActions::CharterFlight;
	((PlayerCardsFrame*)element)->show();
	return true;
}

ShuttleFlightAction::ShuttleFlightAction() : UIButton(CMD_PLAYER_ACTION_SHUTTLE_FLIGHT)
{
	this->caption = "Shuttle Flight";
	this->hoverSurfaceName = "ui/lightbox.png";
	this->width = FRM_PLAYER_ACTIONS_WIDTH;
	this->height = CMD_PLAYER_ACTION_BUTTON_HEIGHT;

	this->top = FRM_PLAYER_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * PlayerActions::ShuttleFlight;
	this->left = FRM_PLAYER_ACTIONS_LEFT;
}

bool ShuttleFlightAction::onMouseDown(std::string key, int x, int y)
{
	/*
	auto element = GuiManager::getUIElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction || GameFrame::PlayerAction == PlayerActions::Drive);
#endif
	GameFrame::PlayerAction = PlayerActions::ShuttleFlight;
	((PlayerCardsFrame*)element)->show();
	*/
	GameFrame::PlayerAction = PlayerActions::ShuttleFlight;
	GuiManager::showMsgBox("Please select a city with a research center");
	return true;
}

BuildResearchCenterAction::BuildResearchCenterAction() : UIButton(CMD_PLAYER_ACTION_BUILD_RESEARCH_CENTER)
{
	this->caption = "Build Research Center";
	this->hoverSurfaceName = "ui/lightbox.png";
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
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction || GameFrame::PlayerAction == PlayerActions::Drive);
#endif
	GameFrame::PlayerAction = PlayerActions::BuildResearchCenter;
	((PlayerCardsFrame*)element)->show();
	return true;
}

TreatDiseaseAction::TreatDiseaseAction() : UIButton(CMD_PLAYER_ACTION_TREAT_DISEASE)
{
	this->caption = "Treat Disease";
	this->hoverSurfaceName = "ui/lightbox.png";
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
	int cityColor = Game::getGameBoard()->getCity(player.pawn->cityIndex)->color;

	/*
	implementing one function of the medic role
	the second function is not implemented
	*/
	if (Game::getGameBoard()->isCured[cityColor]==true)
	{
		GuiManager::showMsgBox("Cure has been found, all cubes in the city are eradicated.");
		do {
			Game::getGameBoard()->getCity(currentPlayerIndex)->cube[cityColor]--;
			Game::numOfCubeIncrementor(cityColor);
		} while (Game::getGameBoard()->getCity(currentPlayerIndex)->cube[cityColor] > 0);
	}

	if (player.getRoleCard()->getRoleCardVal() == 5)
	{
		GuiManager::showMsgBox("You're a medic!...Removing all matching cubes! Counts as one action.");
		do {
			Game::getGameBoard()->getCity(currentPlayerIndex)->cube[cityColor]--;
			Game::numOfCubeIncrementor(cityColor);
		} while (Game::getGameBoard()->getCity(currentPlayerIndex)->cube[cityColor] > 0);
		Game::decrementActionCounter();
		
		GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
		Board::checkTurn();
	}
	//if the player is not a medic
	else if (Game::getGameBoard()->getCity(currentPlayerIndex)->cube[cityColor] > 0)
	{
		GuiManager::showMsgBox("An infection cube has been remove in the current city");
		Game::getGameBoard()->getCity(currentPlayerIndex)->cube[cityColor]--;
		Game::numOfCubeIncrementor(cityColor);
		Game::decrementActionCounter();
		
		GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
		Board::checkTurn();
	}
	else
		GuiManager::showMsgBox("No Infection cube is at the current city.");
	
	return true;
}

ShareKnowledgeAction::ShareKnowledgeAction() : UIButton(CMD_PLAYER_ACTION_SHARE_KNOWLEDGE)
{
	this->caption = "Share Knowledge";
	this->hoverSurfaceName = "ui/lightbox.png";
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
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction || GameFrame::PlayerAction == PlayerActions::Drive);
#endif
	GameFrame::PlayerAction = PlayerActions::ShareKnowledge;
	((PlayerCardsFrame*)element)->show();
	return true;
}


DiscoverCureAction::DiscoverCureAction() : UIButton(CMD_PLAYER_ACTION_DISCOVER_CURE)
{
	this->caption = "Discover Cure";
	this->hoverSurfaceName = "ui/lightbox.png";
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
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction || GameFrame::PlayerAction == PlayerActions::Drive);
#endif
	GameFrame::PlayerAction = PlayerActions::DiscoverCure;
	((PlayerCardsFrame*)element)->show();
	return true;
}


ViewCardsAction::ViewCardsAction() : UIButton(CMD_PLAYER_ACTION_VIEW_CARDS)
{
	this->caption = "View Cards";
	this->hoverSurfaceName = "ui/lightbox.png";
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
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction || GameFrame::PlayerAction == PlayerActions::Drive);
#endif
	GameFrame::PlayerAction = PlayerActions::ViewCards;
	((PlayerCardsFrame*)element)->show();
	GuiManager::showMsgBox("Select an event card if you wish to play one.");
	return true;
}

PlayerCardsClose::PlayerCardsClose() : UIButton(CMD_PLAYER_CARDS_CLOSE)
{
	this->surfaceName = "ui/close.png";
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

	this->surfaceName = "ui/button.png";
	this->caption = "Okay";
	this->getOutline().setThickness(2);
	this->getOutline().setColor(0, 0, 0);
	this->setHorizontalCenter(true);

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
	int numCities = board->getNumCities();
	int playerCityIndex = player.pawn->cityIndex;

	switch (GameFrame::PlayerAction)
	{
	case PlayerActions::Drive:
	{

		// Make sure we're within the valid bounds.
		if (playerCityIndex >= 0 && playerCityIndex < numCities) {
			City* playerCity = board->getCity(playerCityIndex);
			int clickedCityIndex = City::getCityIndexFromXY(x, y);

			// If the city is an adjacent city, move us.
			if (playerCity->isAdjacent(clickedCityIndex)) {
				player.pawn->cityIndex = clickedCityIndex;

				Game::decrementActionCounter();
				GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = false;
				// Reset the player action.
				GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
				Board::checkTurn();
				break;
			}
			else
			{
				GuiManager::showMsgBox("Not within bound please click a adjacent city.");
			}
		}
		return true;
	}
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
					Game::decrementActionCounter();
					
					GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = false;
					// Reset the player action.
					GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
					Board::checkTurn();
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
				Game::decrementActionCounter();
				
				GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = false;
				//reset player Actions
				GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
				Board::checkTurn();
				break;
			}

		}
		return true;
		/*
		*/
	case PlayerActions::ShuttleFlight:
		if (Game::getGameBoard()->getCity(player.pawn->cityIndex)->research != false)
		{
			int clickedCityIndex = City::getCityIndexFromXY(x, y);
			if (Game::getGameBoard()->getCity(clickedCityIndex)->research == true)
			{
				player.pawn->cityIndex = clickedCityIndex;
				/*
				When the player successfully finishes an action, ensure that the action is reset by writing the line
				GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
				Failure to do so will cause assertions to fail and will cause the application to crash.
				*/
				Game::decrementActionCounter();
				GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = false;
				//reset player Actions
				GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
				Board::checkTurn();
			}
			else
				GuiManager::showMsgBox("Invalid choice, the city does not have a research center.");
		}
		else
			GuiManager::showMsgBox("There is no research center at your current city. ");
		return true;
	case PlayerActions::BuildResearchCenter:


		if (roleCardIndex == 4)
		{
			if (Game::numOfResearchCenter > 0)
			{
				if (Game::getGameBoard()->getCity(player.pawn->cityIndex)->research != true)
				{
					GuiManager::showMsgBox("You're operations expert! This is worth one action");
					Game::getGameBoard()->getCity(player.pawn->cityIndex)->research = true;
					Game::numOfResearchCenter--;
					GuiManager::showMsgBox("A research center has been built");
					Game::decrementActionCounter();
					
					//reset player actions
					GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
					Board::checkTurn();
				}
			}	
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
							Game::decrementActionCounter();
							
							//reset player actions
							GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
							Board::checkTurn();
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
		{
			int numOfPlayerInSameCity = 0;
			int nextPlayerIndex;

			for (int i = 0; i < Game::getGameBoard()->getNumberOfPlayers(); i++)
			{
				Player& nextPlayer = Game::getGameBoard()->getPlayer(i);
				nextPlayerIndex = nextPlayer.pawn->cityIndex;
				if (playerCityIndex == nextPlayerIndex)
				{
					numOfPlayerInSameCity++;
				}
			}
			if (numOfPlayerInSameCity > 1)
			{
				GuiManager::showMsgBox("Shared knowledge is possible.");
				if (this->_cardData->size() != 1)
					GuiManager::showMsgBox("please select only one card.");

				//the card index
				int cardIndex = this->_cardData->at(0);
				PlayerCard* card = player.getCard(cardIndex);
				//check if the player is current city match with the city card
				if (player.pawn->cityIndex == ((CityCard*)card)->cityIndex)
				{
					// Make sure the card is not null.
					if (card != nullptr)
					{
						/*
						When the player successfully finishes an action, ensure that the action is reset by writing the line
						GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
						Failure to do so will cause assertions to fail and will cause the application to crash.
						*/
						Game::decrementActionCounter();
						
						GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = false;
						//reset player Actions
						GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
						Board::checkTurn();
					}
				}
			}
			else
				GuiManager::showMsgBox("No other players are at the current city, shared knowledge is not possible.");
		}
		return true;

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

				for (unsigned int i = 0; i < this->_cardData->size(); i++) {
					player.removeCard(this->_cardData->at(i));
				}

				// Cure the disease.
				board->isCured[color] = true;
				GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = false;
				GuiManager::showMsgBox("The disease has been cured.");
				Game::decrementActionCounter();
				
				GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
				Board::checkTurn();
				
			} 
			else 
			{
				GuiManager::showMsgBox("You need to select " + std::to_string(requiredCardCount) + " cards.");
			}
		}
		return true;

		case PlayerActions::ViewCards: {
			if (this->_cardData->size() == 1) {

				//Get the card index.
				int cardIndex = this->_cardData->at(0);
				PlayerCard* card = player.getCard(cardIndex);

				//Make sure the card is not null.
				if (card != nullptr) {

					//Make sure it's an event card.
					if (card->getType() == PlayerCardType::Event_Card) {

						card->eventAction(card);

						//Remove it, move the player and hide the player cards

						player.removeCard(cardIndex);
						Board::checkTurn();
						GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = false;

						//Reset the player action.
						GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
						break;
					}

					else {
						GuiManager::showMsgBox("Please select an event card.");
					}
				}
				else {
					GuiManager::showMsgBox("Card was null.");
				}

				GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = false;
				GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
			}
		}
		return true;


	case PlayerActions::DiscardCards:
		int numberOfCards = player.getNumberOfCards();
		int numberOfDiscards = (numberOfCards + 2) % 7;

		if (this->_cardData->size() == numberOfDiscards) {

			for (int i = 0; i < numberOfDiscards; i++)
			{
				player.removeCard(this->_cardData->at(i));
			}

			GuiManager::getUIElementByName(FRM_PLAYER_CARDS)->visible = false;
			GuiManager::getUIElementByName(CMD_PLAYER_CARDS_CLOSE)->visible = true;
			board->checkTurn();
		}
		else {
			GuiManager::showMsgBox("You must select " + std::to_string(numberOfDiscards) + " cards.");
		}
		break;
	}
	return true;
}



SelectTwoPlayerGame::SelectTwoPlayerGame() : UIButton(CMD_SELECT_TWO_PLAYERS)
{
	this->width = CMD_SELECT_PLAYERS_WIDTH;
	this->height = CMD_SELECT_PLAYERS_HEIGHT;
	this->top = CMD_SELECT_PLAYERS_TOP;
	this->caption = "2 Players";
	this->getOutline().setColor(0, 0, 0);
	this->getOutline().setThickness(2);
	this->setFontSize(48);
	this->setHorizontalCenter(true);
}

SelectThreePlayerGame::SelectThreePlayerGame() : UIButton(CMD_SELECT_THREE_PLAYERS)
{
	this->width = CMD_SELECT_PLAYERS_WIDTH;
	this->height = CMD_SELECT_PLAYERS_HEIGHT;
	this->top = CMD_SELECT_PLAYERS_TOP + this->height;
	this->caption = "3 Players";
	this->getOutline().setColor(0, 0, 0);
	this->getOutline().setThickness(2);
	this->setFontSize(48);
	this->setHorizontalCenter(true);
}

SelectFourPlayerGame::SelectFourPlayerGame() : UIButton(CMD_SELECT_FOUR_PLAYERS)
{
	this->width = CMD_SELECT_PLAYERS_WIDTH;
	this->height = CMD_SELECT_PLAYERS_HEIGHT;
	this->top = CMD_SELECT_PLAYERS_TOP + 2 * this->height;
	this->caption = "4 Players";
	this->getOutline().setColor(0, 0, 0);
	this->getOutline().setThickness(2);
	this->setFontSize(48);
	this->setHorizontalCenter(true);
}

bool SelectTwoPlayerGame::onMouseDown(std::string button, int x, int y)
{
	BoardBuilder builder;
	Game::setGameBoard(builder.loadNewGame(2));
	Game::getGameBoard()->generateGameContentAtStartOfGame();
	GuiManager::getUIElementByName(FRM_NUM_PLAYERS)->visible = false;
	Game::changeState(GameState::InGame);
	return true;
}

bool SelectThreePlayerGame::onMouseDown(std::string button, int x, int y)
{
	BoardBuilder builder;
	Game::setGameBoard(builder.loadNewGame(3));
	Game::getGameBoard()->generateGameContentAtStartOfGame();
	GuiManager::getUIElementByName(FRM_NUM_PLAYERS)->visible = false;
	Game::changeState(GameState::InGame);
	return true;
}

bool SelectFourPlayerGame::onMouseDown(std::string button, int x, int y)
{
	BoardBuilder builder;
	Game::setGameBoard(builder.loadNewGame(4));
	Game::getGameBoard()->generateGameContentAtStartOfGame();
	GuiManager::getUIElementByName(FRM_NUM_PLAYERS)->visible = false;
	Game::changeState(GameState::InGame);
	return true;
}