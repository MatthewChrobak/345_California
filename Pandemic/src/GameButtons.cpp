#include "GameButtons.h"
#include "PlayerActions.h"
#include "GameFrames.h"
#include "Game.h"
#include "CityCard.h"

ToggleActionsButton::ToggleActionsButton(UIElement* parent) : UIButton(parent, CMD_TOGGLE_ACTIONS)
{
	this->setSurfaceName("ui\\button.png");
	this->setCaption("View Actions");
	this->setWidth(CMD_TOGGLE_ACTIONS_WIDTH);
	this->setHeight(CMD_TOGGLE_ACITONS_HEIGHT);

	this->setLeft(DRAW_WIDTH - this->getWidth() - 10);
	this->setTop(DRAW_HEIGHT - this->getHeight() - 10);
}

bool ToggleActionsButton::onMouseDown(std::string button, int x, int y)
{
	auto element = this->baseParent->getElementByName(FRM_PLAYER_ACTIONS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
	element->setVisible(!element->getVisible());
	return true;
}





DrivePlayerAction::DrivePlayerAction(UIElement* parent) : UIButton(parent, CMD_PLAYER_ACTION_DRIVE)
{
	this->setCaption("Drive");
	this->setSurfaceName("ui\\lightbox.png");
	this->setWidth(FRM_PLAYER_ACTIONS_WIDTH);
	this->setHeight(CMD_PLAYER_ACTION_BUTTON_HEIGHT);

	this->setTop(FRM_PLAYER_ACTIONS_TOP);
	this->setLeft(FRM_PLAYER_ACTIONS_LEFT);
}

bool DrivePlayerAction::onMouseDown(std::string key, int x, int y)
{
	GameFrame::PlayerAction = PlayerActions::Drive;
	this->showMsgBox("Please click on a city you wish to drive to.");
	return true;
}

DirectFlightPlayerAction::DirectFlightPlayerAction(UIElement* parent) : UIButton(parent, CMD_PLAYER_ACTION_DIRECT_FLIGHT)
{
	this->setCaption("Direct Flight");
	this->setSurfaceName("ui\\lightbox.png");
	this->setWidth(FRM_PLAYER_ACTIONS_WIDTH);
	this->setWidth(CMD_PLAYER_ACTION_BUTTON_HEIGHT);

	this->setTop(FRM_PLAYER_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * PlayerActions::DirectFlight);
	this->setLeft(FRM_PLAYER_ACTIONS_LEFT);
}

bool DirectFlightPlayerAction::onMouseDown(std::string key, int x, int y)
{
	auto element = this->baseParent->getElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction || GameFrame::PlayerAction == PlayerActions::Drive);
#endif
	GameFrame::PlayerAction = PlayerActions::DirectFlight;
	((PlayerCardsFrame*)element)->show();
	return true;
}

CharterFlightAction::CharterFlightAction(UIElement* parent) : UIButton(parent, CMD_PLAYER_ACTION_CHARTER_FLIGHT)
{
	this->setCaption("Charter Flight");
	this->setHoverSurfaceName("ui\\lightbox.png";
	this->setWidth(FRM_PLAYER_ACTIONS_WIDTH);
	this->setHeight(CMD_PLAYER_ACTION_BUTTON_HEIGHT);

	this->setTop(FRM_PLAYER_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * PlayerActions::CharterFlight);
	this->setLeft(FRM_PLAYER_ACTIONS_LEFT);
}

bool CharterFlightAction::onMouseDown(std::string key, int x, int y)
{
	auto element = this->baseParent->getElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction || GameFrame::PlayerAction == PlayerActions::Drive);
#endif
	GameFrame::PlayerAction = PlayerActions::CharterFlight;
	((PlayerCardsFrame*)element)->show();
	return true;
}

ShuttleFlightAction::ShuttleFlightAction(UIElement* parent) : UIButton(parent, CMD_PLAYER_ACTION_SHUTTLE_FLIGHT)
{
	this->setCaption("Shuttle Flight");
	this->setHoverSurfaceName("ui\\lightbox.png");
	this->setWidth(FRM_PLAYER_ACTIONS_WIDTH);
	this->setHeight(CMD_PLAYER_ACTION_BUTTON_HEIGHT);

	this->setTop(FRM_PLAYER_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * PlayerActions::ShuttleFlight);
	this->setLeft(FRM_PLAYER_ACTIONS_LEFT);
}

bool ShuttleFlightAction::onMouseDown(std::string key, int x, int y)
{
	GameFrame::PlayerAction = PlayerActions::ShuttleFlight;
	this->showMsgBox("Please select a city with a research center");
	return true;
}

BuildResearchCenterAction::BuildResearchCenterAction(UIElement* parent) : UIButton(parent, CMD_PLAYER_ACTION_BUILD_RESEARCH_CENTER)
{
	this->setCaption("Build Research Center");
	this->getHoverSurfaceName("ui\\lightbox.png");
	this->setWidth(FRM_PLAYER_ACTIONS_WIDTH);
	this->setHeight(CMD_PLAYER_ACTION_BUTTON_HEIGHT);

	this->setTop(FRM_PLAYER_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * PlayerActions::BuildResearchCenter);
	this->setLeft(FRM_PLAYER_ACTIONS_LEFT);
}

bool BuildResearchCenterAction::onMouseDown(std::string key, int x, int y)
{
	auto element = this->baseParent->getElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction || GameFrame::PlayerAction == PlayerActions::Drive);
#endif
	GameFrame::PlayerAction = PlayerActions::BuildResearchCenter;
	((PlayerCardsFrame*)element)->show();
	return true;
}

TreatDiseaseAction::TreatDiseaseAction(UIElement* parent) : UIButton(parent, CMD_PLAYER_ACTION_TREAT_DISEASE)
{
	this->setCaption("Treat Disease");
	this->setSurfaceName("ui\\lightbox.png");
	this->setWidth(FRM_PLAYER_ACTIONS_WIDTH);
	this->setHeight(CMD_PLAYER_ACTION_BUTTON_HEIGHT);

	this->setTop(FRM_PLAYER_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * PlayerActions::TreatDisease);
	this->setLeft(FRM_PLAYER_ACTIONS_LEFT);
}
//TODO: only the city cube color can be remove(the game itself allow to remove any cubes on the city. Thus, we have to modify that in the future)
bool TreatDiseaseAction::onMouseDown(std::string key, int x, int y)
{
	auto game = Game::getInstance();
	auto board = game.getBoard();
	Player& player = board.getCurrentTurnPlayer();

	/*
	When the player successfully finishes an action, ensure that the action is reset by writing the line
	GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
	Failure to do so will cause assertions to fail and will cause the application to crash.
	*/
	int currentPlayerIndex = player.pawn->cityIndex;
	int cityColor = board.getCity(player.pawn->cityIndex)->color;

	/*
	implementing one function of the medic role
	the second function is not implemented
	*/
	//TODO: Implementation of the medic role completely
	if (player.getRoleCard()->getRoleCardVal() == 5)
	{
		this->showMsgBox("You're a medic!...Removing all matching cubes! Counts as one action.");
		do {
			board.getCity(currentPlayerIndex)->cube[cityColor]--;
			game.numOfCubeIncrementor(cityColor);
			game.decrementActionCounter();
			Board::checkTurn();
		} while (board.getCity(currentPlayerIndex)->cube[cityColor] > 0);

		GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
	}
	//if the player is not a medic
	else if (board.getCity(currentPlayerIndex)->cube[cityColor] > 0)
	{
		this->showMsgBox("An infection cube has been remove in the current city");
		board.getCity(currentPlayerIndex)->cube[cityColor]--;
		game.numOfCubeIncrementor(cityColor);
		game.decrementActionCounter();
		Board::checkTurn();
		GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
	}
	else
	{
		this->showMsgBox("No Infection cube is at the current city.");
	}

	return true;
}

ShareKnowledgeAction::ShareKnowledgeAction(UIElement* parent) : UIButton(parent, CMD_PLAYER_ACTION_SHARE_KNOWLEDGE)
{
	this->setCaption("Share Knowledge");
	this->setSurfaceName("ui\\lightbox.png");
	this->setWidth(FRM_PLAYER_ACTIONS_WIDTH);
	this->setHeight(CMD_PLAYER_ACTION_BUTTON_HEIGHT);

	this->setTop(FRM_PLAYER_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * PlayerActions::ShareKnowledge);
	this->setLeft(FRM_PLAYER_ACTIONS_LEFT);
}

bool ShareKnowledgeAction::onMouseDown(std::string key, int x, int y)
{
	auto element = this->baseParent->getElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction || GameFrame::PlayerAction == PlayerActions::Drive);
#endif
	GameFrame::PlayerAction = PlayerActions::ShareKnowledge;
	((PlayerCardsFrame*)element)->show();
	return true;
}


DiscoverCureAction::DiscoverCureAction(UIElement* parent) : UIButton(parent, CMD_PLAYER_ACTION_DISCOVER_CURE)
{
	this->setCaption("Discover Cure");
	this->setSurfaceName("ui\\lightbox.png");
	this->setWidth(FRM_PLAYER_ACTIONS_WIDTH);
	this->setHeight(CMD_PLAYER_ACTION_BUTTON_HEIGHT);

	this->setTop(FRM_PLAYER_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * PlayerActions::DiscoverCure);
	this->setLeft(FRM_PLAYER_ACTIONS_LEFT);
}

bool DiscoverCureAction::onMouseDown(std::string key, int x, int y)
{
	auto element = this->baseParent->getElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction || GameFrame::PlayerAction == PlayerActions::Drive);
#endif
	GameFrame::PlayerAction = PlayerActions::DiscoverCure;
	((PlayerCardsFrame*)element)->show();
	return true;
}


ViewCardsAction::ViewCardsAction(UIElement* parent) : UIButton(parent, CMD_PLAYER_ACTION_VIEW_CARDS)
{
	this->setCaption("View Cards");
	this->setSurfaceName("ui\\lightbox.png");
	this->setWidth(FRM_PLAYER_ACTIONS_WIDTH);
	this->setHeight(CMD_PLAYER_ACTION_BUTTON_HEIGHT);

	this->setTop(FRM_PLAYER_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * PlayerActions::ViewCards);
	this->setLeft(FRM_PLAYER_ACTIONS_LEFT);
}

bool ViewCardsAction::onMouseDown(std::string key, int x, int y)
{
	auto element = this->baseParent->getElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
	assert(GameFrame::PlayerAction == PlayerActions::NoPlayerAction || GameFrame::PlayerAction == PlayerActions::Drive);
#endif
	GameFrame::PlayerAction = PlayerActions::ViewCards;
	((PlayerCardsFrame*)element)->show();
	return true;
}

PlayerCardsClose::PlayerCardsClose(UIElement* parent) : UIButton(parent, CMD_PLAYER_CARDS_CLOSE)
{
	this->setSurfaceName("ui\\close.png");
	this->setWidth(CMD_PLAYER_CARDS_CLOSE_WIDTH);
	this->setHeight(CMD_PLAYER_CARDS_CLOSE_HEIGHT);

	this->setLeft(FRM_PLAYER_CARDS_WIDTH - CMD_PLAYER_CARDS_CLOSE_WIDTH - 10);
	this->setTop(10);
}

bool PlayerCardsClose::onMouseDown(std::string button, int x, int y)
{
	auto element = this->baseParent->getElementByName(FRM_PLAYER_CARDS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
	element->setVisible(false);
	GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
	return true;
}


PlayerCardsOkay::PlayerCardsOkay(std::vector<int>* cardData) : UIButton(CMD_PLAYER_CARDS_OKAY)
{
	this->_cardData = cardData;

	this->setSurfaceName("ui\\button.png");
	this->setCaption("Okay");
	this->getOutline().setThickness(2);
	this->getOutline().setColor(0, 0, 0);
	this->setHorizontalCenter(true);

	this->setLeft(CMD_PLAYER_CARDS_OKAY_LEFT);
	this->setTop(CMD_PLAYER_CARDS_OKAY_TOP);
	this->setWidth(CMD_PLAYER_CARDS_OKAY_WIDTH);
	this->setHeight(CMD_PLAYER_CARDS_OKAY_HEIGHT);
}

bool PlayerCardsOkay::onMouseDown(std::string button, int x, int y)
{
	auto game = Game::getInstance();
	auto board = game.getBoard();
	Player& player = board.getCurrentTurnPlayer();
	int roleCardIndex = player.getRoleCard()->getRoleCardVal();
	int numCities = board.getNumCities();
	int playerCityIndex = player.pawn->cityIndex;

	switch (GameFrame::PlayerAction)
	{
	case PlayerActions::Drive:
	{

		// Make sure we're within the valid bounds.
		if (playerCityIndex >= 0 && playerCityIndex < numCities) {
			City* playerCity = board.getCity(playerCityIndex);
			int clickedCityIndex = City::getCityIndexFromXY(x, y);

			// If the city is an adjacent city, move us.
			if (playerCity->isAdjacent(clickedCityIndex)) {
				player.pawn->cityIndex = clickedCityIndex;

				game.decrementActionCounter();
				Board::checkTurn();
				this->baseParent->getElementByName(FRM_PLAYER_CARDS)->setVisible(false);
				// Reset the player action.
				GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
				break;
			}
			else
			{
				this->showMsgBox("Not within bound please click a adjacent city.");
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
					game.decrementActionCounter();
					Board::checkTurn();
					this->baseParent->getElementByName(FRM_PLAYER_CARDS)->setVisible(false);
					// Reset the player action.
					GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
					break;
				}
				else {
					this->showMsgBox("Please select a city card.");
				}
			}
			else {
				this->showMsgBox("Card was null.");
			}
		}
		else {
			this->showMsgBox("Please select only one card.");
		}
		return true;

	case PlayerActions::CharterFlight:
		//select at least 1 card
		if (this->_cardData->size() != 1)
		{
			this->showMsgBox("Please select only one card.");
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
				game.decrementActionCounter();
				Board::checkTurn();
				this->baseParent->getElementByName(FRM_PLAYER_CARDS)->setVisible(false);
				//reset player Actions
				GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
				break;
			}

		}
		return true;
		/*
		*/
	case PlayerActions::ShuttleFlight:
		if (board.getCity(player.pawn->cityIndex)->research != false)
		{
			int clickedCityIndex = City::getCityIndexFromXY(x, y);
			if (board.getCity(clickedCityIndex)->research == true)
			{
				player.pawn->cityIndex = clickedCityIndex;
				/*
				When the player successfully finishes an action, ensure that the action is reset by writing the line
				GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
				Failure to do so will cause assertions to fail and will cause the application to crash.
				*/
				game.decrementActionCounter();
				Board::checkTurn();
				this->baseParent->getElementByName(FRM_PLAYER_CARDS)->setVisible(false);
				//reset player Actions
				GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
			}
			else
				this->showMsgBox("Invalid choice, the city does not have a research center.");
		}
		else
			this->showMsgBox("There is no research center at your current city. ");
		return true;
	case PlayerActions::BuildResearchCenter:


		if (roleCardIndex == 4)
		{
			if (game.numOfResearchCenter > 0)
			{
				if (board.getCity(player.pawn->cityIndex)->research != true)
				{
					this->showMsgBox("You're operations expert! This is worth one action");
					board.getCity(player.pawn->cityIndex)->research = true;
					game.numOfResearchCenter--;
					game.decrementActionCounter();
					Board::checkTurn();
					//reset player actions
					GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
				}
			}
		}


		//select only one card
		else if (this->_cardData->size() != 1)
			this->showMsgBox("Please select only one card.");

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
				if (game.numOfResearchCenter > 0)
				{
					if (board.getCity(player.pawn->cityIndex)->research != true)
					{
						//check if the player is current city match with the city card
						if (player.pawn->cityIndex == ((CityCard*)card)->cityIndex)
						{
							board.getCity(player.pawn->cityIndex)->research = true;
							player.removeCard(cardIndex);
							game.numOfResearchCenter--;
							game.decrementActionCounter();
							Board::checkTurn();
							//reset player actions
							GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
							break;
						}
						else
							this->showMsgBox("You current position does not match the selected city card.");
					}
					else
						this->showMsgBox("The research facility is already built in this city.");
				}
				else
					this->showMsgBox("All research centers have been used.");
			}
			else
				this->showMsgBox("The card is either null or you did not select a city");
		}
		return true;

	case PlayerActions::ShareKnowledge:
	{
		//TODO: THE PHI FIX THIS
		int numOfPlayerInSameCity = 0;
		int nextPlayerIndex;

		for (int i = 0; i < board.getNumberOfPlayers(); i++)
		{
			Player& nextPlayer = board.getPlayer(i);
			nextPlayerIndex = nextPlayer.pawn->cityIndex;
			if (playerCityIndex == nextPlayerIndex)
			{
				numOfPlayerInSameCity++;
			}
		}
		if (numOfPlayerInSameCity > 1)
		{
			this->showMsgBox("Shared knowledge is possible.");
			if (this->_cardData->size() != 1)
				this->showMsgBox("please select only one card.");

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
					game.decrementActionCounter();
					Board::checkTurn();
					this->baseParent->getElementByName(FRM_PLAYER_CARDS)->setVisible(false);
					//reset player Actions
					GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
				}
			}
		}
		else
			this->showMsgBox("No other players are at the current city, shared knowledge is not possible.");
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
					this->showMsgBox("You must select city cards only.");
					return true;
				}
			}

			// Ensure they're the same color.
			for (int i = 1; i < requiredCardCount; i++) {
				CityCard* cityCard0 = (CityCard*)player.getCard(this->_cardData->at(i - 1));
				CityCard* cityCard1 = (CityCard*)player.getCard(this->_cardData->at(i));
				City* city0 = board.getCity(cityCard0->cityIndex);
				City* city1 = board.getCity(cityCard1->cityIndex);

				if (city0->color ^ city0->color) {
					this->showMsgBox("You must select the same color cards.");
					return true;
				}
			}

			// Make sure it hasn't been cured already.
			InfectionColor color = board.getCity(((CityCard*)player.getCard(this->_cardData->at(0)))->cityIndex)->color;
			if (board.isCured[color]) {
				this->showMsgBox("This disease has already been cured!");
				return true;
			}

			// Remove all the cards.

			for (unsigned int i = 0; i < this->_cardData->size(); i++) {
				player.removeCard(this->_cardData->at(i));
			}

			// Cure the disease.
			board.isCured[color] = true;
			this->baseParent->getElementByName(FRM_PLAYER_CARDS)->setVisible(false);
			this->showMsgBox("The disease has been cured.");
			game.decrementActionCounter();
			Board::checkTurn();
			GameFrame::PlayerAction = PlayerActions::NoPlayerAction;

		}
		else
		{
			this->showMsgBox("You need to select " + std::to_string(roleCardIndex) + " cards.");
		}
	}

	/*
	When the player successfully finishes an action, ensure that the action is reset by writing the line
	GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
	Failure to do so will cause assertions to fail and will cause the application to crash.
	*/
	return true;

	case PlayerActions::ViewCards:
		this->baseParent->getElementByName(FRM_PLAYER_CARDS)->setVisible(false);
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
			this->showMsgBox("You must select " + std::to_string(numberOfCards) + " cards.");
		}
		break;
	}
	return true;
}

ToggleMapEditingActions::ToggleMapEditingActions(UIElement* parent) : UIButton(parent, CMD_TOGGLE_MAP_EDITING_ACTIONS)
{
	this->setSurfaceName("ui\\button.png");
	this->setCaption("Show Tools");
	this->setWidth(CMD_TOGGLE_ACTIONS_WIDTH);
	this->setHeight(CMD_TOGGLE_ACITONS_HEIGHT);
	this->setVisible(false);

	this->setLeft(DRAW_WIDTH - this->getWidth() - 10);
	this->setTop(DRAW_HEIGHT - this->getHeight() - 10);
}

bool ToggleMapEditingActions::onMouseDown(std::string button, int x, int y)
{
	auto element = this->baseParent->getElementByName(FRM_MAP_EDITING_ACTIONS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
	element->setVisible(!element->getVisible());
	return true;
}

SelectNodeAction::SelectNodeAction(UIElement* parent) : UIButton(parent, CMD_SELECT_NODE)
{
	this->setCaption("Select Node");
	this->setHoverSurfaceName("ui\\lightbox.png)");
	this->setWidth(FRM_MAP_EDITING_ACTIONS_WIDTH);
	this->setHeight(CMD_PLAYER_ACTION_BUTTON_HEIGHT);

	this->setTop(FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::SelectNode);
	this->setLeft(FRM_MAP_EDITING_ACTIONS_LEFT);
}
bool SelectNodeAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::SelectNode;
	return true;
}

RotateNodeAngleAction::RotateNodeAngleAction(UIElement* parent) : UIButton(parent, CMD_SELECT_NODE)
{
	this->setCaption("Rotate Angle");
	this->setWidth(FRM_MAP_EDITING_ACTIONS_WIDTH);
	this->setHeight(CMD_PLAYER_ACTION_BUTTON_HEIGHT);

	this->setTop(FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::RotateAngle);
	this->setLeft(FRM_MAP_EDITING_ACTIONS_LEFT);
}
bool RotateNodeAngleAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::RotateAngle;
	return true;
}

AddNodeAction::AddNodeAction(UIElement* parent) : UIButton(parent, CMD_ADD_NODE)
{
	this->setCaption("Add Node");
	this->setSurfaceName("ui\\lightbox.png");
	this->setWidth(FRM_MAP_EDITING_ACTIONS_WIDTH);
	this->setHeight(CMD_PLAYER_ACTION_BUTTON_HEIGHT);

	this->setTop(FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::AddNode);
	this->setLeft(FRM_MAP_EDITING_ACTIONS_LEFT);
}
bool AddNodeAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::AddNode;
	return true;
}



MakeNodeBlackAction::MakeNodeBlackAction(UIElement* parent) : UIButton(parent, CMD_MAKE_NODE_BLACK)
{
	this->setCaption("Make Black");
	this->setSurfaceName("ui\\lightbox.png");
	this->setWidth(FRM_MAP_EDITING_ACTIONS_WIDTH);
	this->setHeight(CMD_PLAYER_ACTION_BUTTON_HEIGHT);

	this->setTop(FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::MakeNodeBlack);
	this->setLeft(FRM_MAP_EDITING_ACTIONS_LEFT);
}
bool MakeNodeBlackAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::MakeNodeBlack;
	return true;
}



MakeNodeRedAction::MakeNodeRedAction(UIElement* parent) : UIButton(parent, CMD_MAKE_NODE_RED)
{
	this->setCaption("Make Red");
	this->setSurfaceName("ui\\lightbox.png");
	this->setWidth(FRM_MAP_EDITING_ACTIONS_WIDTH);
	this->setHeight(CMD_PLAYER_ACTION_BUTTON_HEIGHT);

	this->setTop(FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::MakeNodeRed);
	this->setLeft(FRM_MAP_EDITING_ACTIONS_LEFT);
}
bool MakeNodeRedAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::MakeNodeRed;
	return true;
}


MakeNodeYellowAction::MakeNodeYellowAction(UIElement* parent) : UIButton(parent, CMD_MAKE_NODE_YELLOW)
{
	this->setCaption("Make Yellow");
	this->setSurfaceName("ui\\lightbox.png");
	this->setWidth(FRM_MAP_EDITING_ACTIONS_WIDTH);
	this->setHeight(CMD_PLAYER_ACTION_BUTTON_HEIGHT);

	this->setTop(FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::MakeNodeYellow);
	this->setLeft(FRM_MAP_EDITING_ACTIONS_LEFT);
}
bool MakeNodeYellowAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::MakeNodeYellow;
	return true;
}


MakeNodeBlueAction::MakeNodeBlueAction(UIElement* parent) : UIButton(parent, CMD_MAKE_NODE_BLUE)
{
	this->setCaption("Make Blue");
	this->setHoverSurfaceName("ui\\lightbox.png");
	this->setWidth(FRM_MAP_EDITING_ACTIONS_WIDTH);
	this->setHeight(CMD_PLAYER_ACTION_BUTTON_HEIGHT);

	this->setTop(FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::MakeNodeBlue);
	this->setLeft(FRM_MAP_EDITING_ACTIONS_LEFT);
}
bool MakeNodeBlueAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::MakeNodeBlue;
	return true;
}


ChangeNodeNameAction::ChangeNodeNameAction(UIElement* parent) : UIButton(parent, CMD_CHANGE_NODE_NAME)
{
	this->setCaption("Rename Node");
	this->setSurfaceName("ui\\lightbox.png");
	this->setWidth(FRM_MAP_EDITING_ACTIONS_WIDTH);
	this->setHeight(CMD_PLAYER_ACTION_BUTTON_HEIGHT);

	this->setTop(FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::ChangeNodeName);
	this->setLeft(FRM_MAP_EDITING_ACTIONS_LEFT);
}
bool ChangeNodeNameAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::ChangeNodeName;
	return true;
}


MakeDirectedEdgeAction::MakeDirectedEdgeAction(UIElement* parent) : UIButton(parent, CMD_MAKE_DIRECTED_EDGE)
{
	this->setCaption("Make Edge");
	this->setSurfaceName("ui\\lightbox.png");
	this->setWidth(FRM_MAP_EDITING_ACTIONS_WIDTH);
	this->setHeight(CMD_PLAYER_ACTION_BUTTON_HEIGHT);

	this->setTop(FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::MakeDirectedEdge);
	this->setLeft(FRM_MAP_EDITING_ACTIONS_LEFT);
}
bool MakeDirectedEdgeAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::MakeDirectedEdge;
	return true;
}



MoveNodeAction::MoveNodeAction(UIElement* parent) : UIButton(parent, CMD_MOVE_NODE)
{
	this->setCaption("MoveNode");
	this->setSurfaceName("ui\\lightbox.png");
	this->setWidth(FRM_MAP_EDITING_ACTIONS_WIDTH);
	this->setHeight(CMD_PLAYER_ACTION_BUTTON_HEIGHT);

	this->setTop(FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::MoveNode);
	this->setLeft(FRM_MAP_EDITING_ACTIONS_LEFT);
}
bool MoveNodeAction::onMouseDown(std::string button, int x, int y)
{
	GameFrame::EditingAction = MapEditingActions::MoveNode;
	return true;
}


FinishedEditingMapAction::FinishedEditingMapAction(UIElement* parent) : UIButton(parent, CMD_FINISHED_MAP_EDITING)
{
	this->setCaption("Done Editing");
	this->setSurfaceName("ui\\lightbox.png");
	this->setWidth(FRM_MAP_EDITING_ACTIONS_WIDTH);
	this->setHeight(CMD_PLAYER_ACTION_BUTTON_HEIGHT);

	this->setTop(FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * MapEditingActions::FinishedEditingMap);
	this->setLeft(FRM_MAP_EDITING_ACTIONS_LEFT);
}
bool FinishedEditingMapAction::onMouseDown(std::string button, int x, int y)
{
	auto element = this->baseParent->getElementByName(FRM_GAME_FRAME);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
	((GameFrame*)element)->finishedEditing();
	return true;
}