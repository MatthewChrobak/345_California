#include "Frames.h"
#include "Buttons.h"
#include "Textboxes.h"
#include "Game.h"
#include "PlayerActions.h"
#include "CityCard.h"
#include "GuiManager.h"

PlayerActions GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
MapEditingActions GameFrame::EditingAction;
int GameFrame::EditNodeIndex = 0;

GameFrame::GameFrame() : UIFrame(FRM_GAME_FRAME)
{
	this->surfaceName = "ui\\frame.png";
	this->width = FRM_GAME_FRAME_WIDTH;
	this->height = FRM_GAME_FRAME_HEIGHT;
	this->_elements.push_back(new ToggleActionsButton());
	this->_elements.push_back(new PlayerActionsFrame());
	this->_elements.push_back(new PlayerCardsFrame());
	this->_elements.push_back(new ToggleMapEditingActions());
	this->_elements.push_back(new MapEditingActionsFrame());
}

void GameFrame::showAdminTools()
{
	this->_editing = true;
	
	// Make the map tools button visible.
	auto element = GuiManager::getUIElementByName(CMD_TOGGLE_MAP_EDITING_ACTIONS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_BUTTON);
#endif
	element->visible = true;
}

void GameFrame::finishedEditing()
{
	this->_editing = false;

	// Make the map tools button invisible.
	auto element = GuiManager::getUIElementByName(CMD_TOGGLE_MAP_EDITING_ACTIONS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_BUTTON);
#endif
	element->visible = false;

	// Make the map tools frame invisible.
	element = GuiManager::getUIElementByName(FRM_MAP_EDITING_ACTIONS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
	element->visible = false;
}

bool GameFrame::onMouseDown(std::string button, int x, int y)
{
	// Maybe we can exit out early.
	if (UIFrame::onMouseDown(button, x, y)) {
		return true;
	}

	if (button == "left") {
		Board* board = Game::getGameBoard();
		int numCities = board->getNumCities();

		// Are we currently editing the map?
		if (this->_editing)
		{
			// Figure out if we did an action that requires clicking on cities.
			switch (GameFrame::EditingAction) {
				// Move the node.
				case MapEditingActions::MoveNode: {
					City* city = Game::getGameBoard()->getCity(GameFrame::EditNodeIndex);
					city->x = x;
					city->y = y;
				}
				break;
			case MapEditingActions::AddNode: {
				City* city = new City();
				city->x = x;
				city->y = y;
				Game::getGameBoard()->addCity(city);
				break;
			}
			case MapEditingActions::RotateAngle:
			case MapEditingActions::SelectNode:
			case MapEditingActions::MakeNodeBlack:
			case MapEditingActions::MakeNodeRed:
			case MapEditingActions::MakeNodeYellow:
			case MapEditingActions::MakeNodeBlue:
			case MapEditingActions::MakeDirectedEdge:
				// Get the city from the x/y coordinate.
				int index = City::getCityIndexFromXY(x, y);
				City* city = board->getCity(index);

				// Make sure it's not null.
				if (city != nullptr) {
					// Figure out what editing action we're doing.
					switch (GameFrame::EditingAction) {

						// Modify the currently focused node.
						case MapEditingActions::SelectNode:
							GameFrame::EditNodeIndex = index;
							break;

							// Place the node in the current position.
						case MapEditingActions::AddNode:
						{
							City* newCity = new City();
							newCity->x = x;
							newCity->y = y;
							board->addCity(newCity);
						}
						break;

						// Set the colors.
						case MapEditingActions::MakeNodeBlack:
							city->color = InfectionColor::Black;
							break;
						case MapEditingActions::MakeNodeRed:
							city->color = InfectionColor::Red;
							break;
						case MapEditingActions::MakeNodeYellow:
							city->color = InfectionColor::Yellow;
							break;
						case MapEditingActions::MakeNodeBlue:
							city->color = InfectionColor::Blue;
							break;

						case MapEditingActions::RotateAngle:
							city->inverseAngle = !city->inverseAngle;
							break;

							// Add the edges.
						case MapEditingActions::MakeDirectedEdge:
						{
							City* primaryCity = Game::getGameBoard()->getCity(GameFrame::EditNodeIndex);

							// Connect them only if they're different.
							if (index != GameFrame::EditNodeIndex) {
								primaryCity->addAdjacentNode(index);
								city->addAdjacentNode(GameFrame::EditNodeIndex);
							}
						}
						break;
					}
					break;
				}
				break;
			}
		} 
		else {
			// Are we currently trying to do an action?
			if (GameFrame::PlayerAction != PlayerActions::NoPlayerAction) {

				switch (GameFrame::PlayerAction) 
				{
					// Are we trying to move?
					case PlayerActions::Drive:
					{
						Player& player = board->getCurrentTurnPlayer();
						int playerCityIndex = player.pawn->cityIndex;

						// Make sure we're within the valid bounds.
						if (playerCityIndex >= 0 && playerCityIndex < numCities) {
							City* playerCity = board->getCity(playerCityIndex);
							int clickedCityIndex = City::getCityIndexFromXY(x, y);

							// If the city is an adjacent city, move us.
							if (playerCity->isAdjacent(clickedCityIndex)) {
								player.pawn->cityIndex = clickedCityIndex;

								// Reset the player action.
								// TODO: Decrement the player action count.
								GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
								break;
							}
						}
						break;
					}
					default:
						GuiManager::showMsgBox("Tried to perform an action on " + GameFrame::PlayerAction);
						break;
				}
			}
		}
	}
	return true;
}

void GameFrame::draw()
{
	UIFrame::draw();

	// Are we editing right now?
	if (this->_editing && Game::getGameBoard()->getNumCities()) {
		switch (GameFrame::EditingAction) {
			case MapEditingActions::SelectNode:
			case MapEditingActions::MakeDirectedEdge:
			case MapEditingActions::ChangeNodeName:
			case MapEditingActions::MoveNode:
				SurfaceContext ctx;
				City* city = Game::getGameBoard()->getCity(GameFrame::EditNodeIndex);
				ctx.position = new Vector2D(city->x - (CITY_RENDER_WIDTH / 2), city->y - (CITY_RENDER_HEIGHT / 2));
				ctx.size = new Vector2D(CITY_RENDER_WIDTH, CITY_RENDER_HEIGHT);
				GraphicsManager::renderSurface("ui\\selectbox.png", ctx);
				break;
		}
	}
}

bool GameFrame::onKeyDown(std::string key)
{
	// Are we editing right now?
	if (this->_editing && Game::getGameBoard()->getNumCities()) {
		switch (GameFrame::EditingAction) {
			case MapEditingActions::ChangeNodeName:

				// Get the city object.
				City* city = Game::getGameBoard()->getCity(GameFrame::EditNodeIndex);

				// Is the input a non-character?
				if (key.size() != 1) {

					if (key == "backspace") {
						// Can we even backspace?
						if (city->name.size() != 0) {
							city->name = city->name.substr(0, city->name.size() - 1);
							return true;
						}
					}

					// Exit out. This is not a character we should append.
					return true;
				}

				city->name += key;
				break;
		}
	}

	return true;
}


bool GameFrame::onKeyUp(std::string key)
{
	return true;
}

void GameFrame::onMouseMove(int x, int y)
{
	
}


PlayerActionsFrame::PlayerActionsFrame() : UIFrame(FRM_PLAYER_ACTIONS)
{
	this->surfaceName = "ui\\panel.png";
	this->width = FRM_PLAYER_ACTIONS_WIDTH;
	this->height = FRM_PLAYER_ACTIONS_HEIGHT;

	this->top = FRM_PLAYER_ACTIONS_TOP;
	this->left = FRM_PLAYER_ACTIONS_LEFT;
	this->visible = false;

	this->_elements.push_back(new DrivePlayerAction());
	this->_elements.push_back(new DirectFlightPlayerAction());
	this->_elements.push_back(new CharterFlightAction());
	this->_elements.push_back(new ShuttleFlightAction());
	this->_elements.push_back(new BuildResearchCenterAction());
	this->_elements.push_back(new TreatDiseaseAction());
	this->_elements.push_back(new ShareKnowledgeAction());
	this->_elements.push_back(new DiscoverCureAction());
	this->_elements.push_back(new ViewCardsAction());
}

bool PlayerActionsFrame::onMouseDown(std::string button, int x, int y)
{
	// Maybe exit out early.
	if (UIFrame::onMouseDown(button, x, y)) {
		return true;
	}

	this->visible = false;
	return true;
}


MainMenuFrame::MainMenuFrame() : UIFrame(FRM_MAIN_MENU)
{
	this->surfaceName = "ui\\mainmenu.png";
	this->width = FRM_MAIN_MENU_WIDTH;
	this->height = FRM_MAIN_MENU_HEIGHT;

	this->_elements.push_back(new SaveNameTextbox());
	this->_elements.push_back(new PlayGameButton());
}


PlayerCardsFrame::PlayerCardsFrame() : UIFrame(FRM_PLAYER_CARDS)
{
	this->surfaceName = "ui\\textbox.png";
	this->width = FRM_PLAYER_CARDS_WIDTH;
	this->height = FRM_PLAYER_CARDS_HEIGHT;
	this->visible = false;

	this->_elements.push_back(new PlayerCardsClose());
	this->_elements.push_back(new PlayerCardsOkay(&this->_cardData));
}

void PlayerCardsFrame::draw()
{
	UIFrame::draw();

	Player& player = Game::getGameBoard()->getCurrentTurnPlayer();
	SurfaceContext sCtx;
	TextContext tCtx;

	// Draw two rows of cards.
	for (int i = 0; i < MAX_PLAYER_CARDS; i++) {
		// Get the card, and figure out what row and column we're in.
		PlayerCard* card = player.getCard(i);

		// Make sure the card is not null.
		if (card == nullptr) {
			continue;
		}

		int x = i % 4;
		int y = i / 4;

		// Reset the contexes just in case.
		tCtx.reset();
		sCtx.reset();

		sCtx.size = new Vector2D(PLAYER_CARD_WIDTH, PLAYER_CARD_HEIGHT);
		sCtx.position = new Vector2D(PLAYER_CARD_WIDTH * x + 10 * (x + 1), PLAYER_CARD_HEIGHT * y / 2 + 10 * (y + 1) + y * PLAYER_CARD_HEIGHT / 2);


		// Render the card as a city card if it's a city card.
		if (card->getType() == PlayerCardType::City_Card) {
			// Get the city from its index.
			int cityIndex = ((CityCard*)card)->cityIndex;

			if (cityIndex >= 0 && cityIndex < Game::getGameBoard()->getNumCities()) {
				City* city = Game::getGameBoard()->getCity(cityIndex);

				// Do we render the selector?
				for (unsigned int cardDataIndex = 0; cardDataIndex < this->_cardData.size(); cardDataIndex++) {
					if (this->_cardData.at(cardDataIndex) == i) {
						GraphicsManager::renderSurface("cards\\cardselect.png", sCtx);
						break;
					}
				}

				// Modify the color
				switch (city->color)
				{
				case InfectionColor::Black:
					sCtx.color = new RGBA(100, 100, 100);
					break;
				case InfectionColor::Blue:
					sCtx.color = new RGBA(0, 0, 255);
					break;
				case InfectionColor::Red:
					sCtx.color = new RGBA(255, 0, 0);
					break;
				case InfectionColor::Yellow:
					sCtx.color = new RGBA(255, 255, 0);
					break;
				}

				// Render the text in the middle.
				tCtx.horizontalCenter = true;
				tCtx.position = new Vector2D(sCtx.position->x + PLAYER_CARD_WIDTH / 2, sCtx.position->y + 25);
				tCtx.fontSize = 18;

				// Pass it off to the graphics manager to draw.
				GraphicsManager::renderSurface("cards\\citycard.png", sCtx);
				GraphicsManager::renderText(city->name, tCtx);
			}
		}
	}
}

bool PlayerCardsFrame::onMouseDown(std::string button, int x, int y)
{
	// Maybe we can exit out early.
	if (UIFrame::onMouseDown(button, x, y)) {
		return true;
	}

	Player& player = Game::getGameBoard()->getCurrentTurnPlayer();
	

	for (int i = 0; i < MAX_PLAYER_CARDS; i++) {
		// Get the card, and figure out what row and column we're in.
		PlayerCard* card = player.getCard(i);

		// Make sure the card is not null.
		if (card == nullptr) {
			continue;
		}

		int column = i % 4;
		int row = i / 4;

		int left = PLAYER_CARD_WIDTH * column + 10 * (column + 1);
		int top = PLAYER_CARD_HEIGHT * row / 2 + 10 * (row + 1) + row * PLAYER_CARD_HEIGHT / 2;

		// Did we click on the card?
		if (left <= x && x <= left + PLAYER_CARD_WIDTH) {
			if (top <= y && y <= top + PLAYER_CARD_HEIGHT) {
				
				// Is the card already contained in the card data?
				bool contained = false;

				for (unsigned int cardDataIndex = 0; cardDataIndex < this->_cardData.size(); cardDataIndex++) {
					if (this->_cardData.at(cardDataIndex) == i) {
						// If it is, remove it.
						this->_cardData.erase(this->_cardData.begin() + cardDataIndex);
						contained = true;
						break;
					}
				}

				// If not, put it there.
				if (!contained) {
					this->_cardData.push_back(i);
				}
				break;
			}
		}

	}
	return true;
}

void PlayerCardsFrame::show()
{
	this->_cardData.erase(this->_cardData.begin(), this->_cardData.end());
	this->visible = true;

	switch (GameFrame::PlayerAction)
	{
	case PlayerActions::Drive:

		break;
	case PlayerActions::DirectFlight:
		GuiManager::showMsgBox("Please select one city card to fly to.");
		break;
	case PlayerActions::CharterFlight:

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
		// Do nothing.
		break;
	}
}


MapEditingActionsFrame::MapEditingActionsFrame() : UIFrame(FRM_MAP_EDITING_ACTIONS)
{
	this->surfaceName = "ui\\panel.png";
	this->width = FRM_MAP_EDITING_ACTIONS_WIDTH;
	this->height = FRM_MAP_EDITING_ACTIONS_HEIGHT;

	this->top = FRM_MAP_EDITING_ACTIONS_TOP;
	this->left = FRM_MAP_EDITING_ACTIONS_LEFT;
	this->visible = false;

	this->_elements.push_back(new SelectNodeAction());
	this->_elements.push_back(new AddNodeAction());
	this->_elements.push_back(new MakeNodeBlackAction());
	this->_elements.push_back(new MakeNodeRedAction());
	this->_elements.push_back(new MakeNodeYellowAction());
	this->_elements.push_back(new MakeNodeBlueAction());
	this->_elements.push_back(new ChangeNodeNameAction());
	this->_elements.push_back(new MakeDirectedEdgeAction());
	this->_elements.push_back(new MoveNodeAction());
	this->_elements.push_back(new FinishedEditingMapAction());
	this->_elements.push_back(new RotateNodeAngleAction());
}

void MapEditingActionsFrame::draw()
{
	UIFrame::draw();

	// Highlight the selected tool.
	SurfaceContext ctx;
	ctx.size = new Vector2D(FRM_MAP_EDITING_ACTIONS_WIDTH, CMD_PLAYER_ACTION_BUTTON_HEIGHT);
	ctx.position = new Vector2D(FRM_MAP_EDITING_ACTIONS_LEFT, FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * GameFrame::EditingAction);
	GraphicsManager::renderSurface("ui\\lightbox.png", ctx);
}