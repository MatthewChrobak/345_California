#include "GameFrames.h"
#include "Game.h"
#include "GameButtons.h"
#include "CityCard.h"
#include "UIMessageBox.h"

PlayerActions GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
MapEditingActions GameFrame::EditingAction;
int GameFrame::EditNodeIndex = 0;

GameFrame::GameFrame() : UIFrame(this, FRM_GAME_FRAME)
{
	this->setSurfaceName("ui/frame.png");
	this->setWidth(FRM_GAME_FRAME_WIDTH);
	this->setHeight(FRM_GAME_FRAME_HEIGHT);
	this->_elements.push_back(new ToggleActionsButton(this));
	this->_elements.push_back(new PlayerActionsFrame(this));
	this->_elements.push_back(new PlayerCardsFrame(this));
	this->_elements.push_back(new ToggleMapEditingActions(this));
	this->_elements.push_back(new MapEditingActionsFrame(this));
	this->_elements.push_back(new UIMessageBox(this));
	this->_elements.push_back(new UIMessageBoxAccept(this));
}

void GameFrame::showAdminTools()
{
	// Make the map tools button visible.
	auto element = this->getElementByName(CMD_TOGGLE_MAP_EDITING_ACTIONS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_BUTTON);
#endif
	element->setVisible(true);

	// Make the other frame invisible.
	element = this->getElementByName(FRM_PLAYER_ACTIONS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
	element->setVisible(false);
}

void GameFrame::finishedEditing()
{
	auto board = Game::getInstance().getBoard();

	// Make the map tools button invisible.
	auto element = this->getElementByName(CMD_TOGGLE_MAP_EDITING_ACTIONS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_BUTTON);
#endif
	element->setVisible(false);

	// Make the map tools frame invisible.
	element = this->getElementByName(FRM_MAP_EDITING_ACTIONS);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_FRAME);
#endif
	element->setVisible(false);

	// Submit the map.
	board.submitMap();
}

bool GameFrame::onMouseDown(std::string button, int x, int y)
{
	auto game = Game::getInstance();
	auto board = game.getBoard();
	Player& player = board.getCurrentTurnPlayer();
	int roleCardIndex = player.getRoleCard()->getRoleCardVal();
	int numCities = board.getNumCities();
	// Maybe we can exit out early.
	if (UIFrame::onMouseDown(button, x, y)) {
		return true;
	}

	if (button == "left") {
		// Are we currently editing the map?
		if (board.isEditingMap())
		{
			// Figure out if we did an action that requires clicking on cities.
			switch (GameFrame::EditingAction) {
				// Move the node.
			case MapEditingActions::MoveNode: {
				City* city = board.getCity(GameFrame::EditNodeIndex);
				city->x = x;
				city->y = y;
			}
											  break;
			case MapEditingActions::AddNode: {
				City* city = new City();
				city->x = x;
				city->y = y;
				board.addCity(city);
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

				if (index < 0)
				{
					return true;
				}

				City* city = board.getCity(index);

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
						board.addCity(newCity);
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
						City* primaryCity = board.getCity(GameFrame::EditNodeIndex);

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

		else
		{

			// Are we currently trying to do an action?
			if (GameFrame::PlayerAction != PlayerActions::NoPlayerAction) {

				switch (GameFrame::PlayerAction)
				{
					// Are we trying to move?
				case PlayerActions::Drive:
				{
					Player& player = board.getCurrentTurnPlayer();
					int playerCityIndex = player.pawn->cityIndex;

					// Make sure we're within the valid bounds.
					if (playerCityIndex >= 0 && playerCityIndex < numCities) {
						City* playerCity = board.getCity(playerCityIndex);
						int clickedCityIndex = City::getCityIndexFromXY(x, y);

						// If the city is an adjacent city, move us.
						if (playerCity->isAdjacent(clickedCityIndex)) {
							player.pawn->cityIndex = clickedCityIndex;

							// Reset the player action.
							game.decrementActionCounter();
							//If turn is changed, show this message
							Board::checkTurn();
							GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
							break;
						}
					}
					break;
				}
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
							this->getElementByName(FRM_PLAYER_CARDS)->setVisible(false);
							//reset player Actions
							GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
						}
						else
							this->showMsgBox("Invalid choice, the city does not have a research center.");
					}
					else
						this->showMsgBox("There is no research center at your current city. ");
					return true;
				default:
					this->showMsgBox("Tried to perform an action on " + GameFrame::PlayerAction);
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

	auto board = Game::getInstance().getBoard();

	// Are we editing right now?
	if (board.isEditingMap() && board.getNumCities()) {
		switch (GameFrame::EditingAction) {
		case MapEditingActions::SelectNode:
		case MapEditingActions::MakeDirectedEdge:
		case MapEditingActions::ChangeNodeName:
		case MapEditingActions::MoveNode:
			SurfaceContext ctx;
			City* city = board.getCity(GameFrame::EditNodeIndex);
			ctx.setPosition(city->x - (CITY_RENDER_WIDTH / 2), city->y - (CITY_RENDER_HEIGHT / 2));
			ctx.setRenderSize(CITY_RENDER_WIDTH, CITY_RENDER_HEIGHT);
			GraphicsManager::renderSurface("ui/selectbox.png", ctx);
			break;
		}
	}
}

bool GameFrame::onKeyDown(std::string key)
{
	auto board = Game::getInstance().getBoard();

	// Are we editing right now?
	if (board.isEditingMap() && board.getNumCities()) {
		switch (GameFrame::EditingAction) {
		case MapEditingActions::ChangeNodeName:

			// Get the city object.
			City* city = board.getCity(GameFrame::EditNodeIndex);

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



PlayerActionsFrame::PlayerActionsFrame(UIElement* parent) : UIFrame(parent, FRM_PLAYER_ACTIONS)
{
	this->setSurfaceName("ui\\panel.png");
	this->setWidth(FRM_PLAYER_ACTIONS_WIDTH);
	this->setHeight(FRM_PLAYER_ACTIONS_HEIGHT);

	this->setTop(FRM_PLAYER_ACTIONS_TOP);
	this->setLeft(FRM_PLAYER_ACTIONS_LEFT);
	this->setVisible(false);

	this->_elements.push_back(new DrivePlayerAction(this));
	this->_elements.push_back(new DirectFlightPlayerAction(this));
	this->_elements.push_back(new CharterFlightAction(this));
	this->_elements.push_back(new ShuttleFlightAction(this));
	this->_elements.push_back(new BuildResearchCenterAction(this));
	this->_elements.push_back(new TreatDiseaseAction(this));
	this->_elements.push_back(new ShareKnowledgeAction(this));
	this->_elements.push_back(new DiscoverCureAction(this));
	this->_elements.push_back(new ViewCardsAction(this));
}

bool PlayerActionsFrame::onMouseDown(std::string button, int x, int y)
{
	// Maybe exit out early.
	if (UIFrame::onMouseDown(button, x, y)) {
		return true;
	}

	this->setVisible(false);
	return true;
}



PlayerCardsFrame::PlayerCardsFrame(UIElement* parent) : UIFrame(parent, FRM_PLAYER_CARDS)
{
	this->setSurfaceName("ui\\textbox.png");
	this->setWidth(FRM_PLAYER_CARDS_WIDTH);
	this->setHeight(FRM_PLAYER_CARDS_HEIGHT);
	this->setVisible(false);

	this->_elements.push_back(new PlayerCardsClose(this));
	this->_elements.push_back(new PlayerCardsOkay(&this->_cardData));
}

void PlayerCardsFrame::draw()
{
	UIFrame::draw();

	auto board = Game::getInstance().getBoard();

	Player& player = board.getCurrentTurnPlayer();
	SurfaceContext sCtx;
	TextContext tCtx;

	// Draw two rows of cards.
	for (int i = 0; i < 7; i++) {
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

		sCtx.setRenderSize(PLAYER_CARD_WIDTH, PLAYER_CARD_HEIGHT);
		sCtx.setPosition(PLAYER_CARD_WIDTH * x + 10 * (x + 1), PLAYER_CARD_HEIGHT * y / 2 + 10 * (y + 1) + y * PLAYER_CARD_HEIGHT / 2);

		// Do we render the selector?
		for (unsigned int cardDataIndex = 0; cardDataIndex < this->_cardData.size(); cardDataIndex++) {
			if (this->_cardData.at(cardDataIndex) == i) {
				GraphicsManager::renderSurface("cards\\cardselect.png", sCtx);
				break;
			}
		}

		// Render the card as a city card if it's a city card.
		if (card->getType() == PlayerCardType::City_Card) {
			// Get the city from its index.
			int cityIndex = ((CityCard*)card)->cityIndex;

			if (cityIndex >= 0 && cityIndex < board.getNumCities()) {
				City* city = board.getCity(cityIndex);

				// Modify the color
				switch (city->color)
				{
				case InfectionColor::Black:
					sCtx.setColor(100, 100, 100);
					break;
				case InfectionColor::Blue:
					sCtx.setColor(0, 0, 255);
					break;
				case InfectionColor::Red:
					sCtx.setColor(255, 0, 0);
					break;
				case InfectionColor::Yellow:
					sCtx.setColor(255, 255, 0);
					break;
				}

				// Render the text in the middle.
				tCtx.setHorizontalCenter(true);
				tCtx.setPosition(sCtx.getPosition()->getX() + PLAYER_CARD_WIDTH / 2, sCtx.getPosition()->getY() + 25);
				tCtx.setFontSize(18);

				// Pass it off to the graphics manager to draw.
				GraphicsManager::renderSurface("cards\\citycard.png", sCtx);
				GraphicsManager::renderText(city->name, tCtx);
			}
		}

		//Render the card as an event card if it's an event card
		if (card->getType() == PlayerCardType::Event_Card) {

			sCtx.setColor(255, 178, 102);

			//Render the text in the middle.
			tCtx.setHorizontalCenter(true);
			tCtx.setPosition(sCtx.getPosition()->getX() + PLAYER_CARD_WIDTH / 2, sCtx.getPosition()->getY() + 25);
			tCtx.setFontSize(20);

			// Pass if off to the graphics manager to draw.
			GraphicsManager::renderSurface("cards\\eventcard.png", sCtx);
			GraphicsManager::renderText(((EventCard*)card)->getEventName(), tCtx);
		}
	}
}

bool PlayerCardsFrame::onMouseDown(std::string button, int x, int y)
{
	auto board = Game::getInstance().getBoard();

	// Maybe we can exit out early.
	if (UIFrame::onMouseDown(button, x, y)) {
		return true;
	}

	Player& player = board.getCurrentTurnPlayer();


	for (int i = 0; i < 7; i++) {
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
	this->setVisible(true);

	switch (GameFrame::PlayerAction)
	{
	case PlayerActions::Drive:

		break;
	case PlayerActions::DirectFlight:
		this->showMsgBox("Please select one city card to fly to.");
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


MapEditingActionsFrame::MapEditingActionsFrame(UIElement* parent) : UIFrame(parent, FRM_MAP_EDITING_ACTIONS)
{
	this->setSurfaceName("ui\\panel.png");
	this->setWidth(FRM_MAP_EDITING_ACTIONS_WIDTH);
	this->setHeight(FRM_MAP_EDITING_ACTIONS_HEIGHT);

	this->setTop(FRM_MAP_EDITING_ACTIONS_TOP);
	this->setLeft(FRM_MAP_EDITING_ACTIONS_LEFT);
	this->setVisible(false);

	this->_elements.push_back(new SelectNodeAction(this));
	this->_elements.push_back(new AddNodeAction(this));
	this->_elements.push_back(new MakeNodeBlackAction(this));
	this->_elements.push_back(new MakeNodeRedAction(this));
	this->_elements.push_back(new MakeNodeYellowAction(this));
	this->_elements.push_back(new MakeNodeBlueAction(this));
	this->_elements.push_back(new ChangeNodeNameAction(this));
	this->_elements.push_back(new MakeDirectedEdgeAction(this));
	this->_elements.push_back(new MoveNodeAction(this));
	this->_elements.push_back(new FinishedEditingMapAction(this));
	this->_elements.push_back(new RotateNodeAngleAction(this));
}

void MapEditingActionsFrame::draw()
{
	UIFrame::draw();

	// Highlight the selected tool.
	SurfaceContext ctx;
	ctx.setRenderSize(FRM_MAP_EDITING_ACTIONS_WIDTH, CMD_PLAYER_ACTION_BUTTON_HEIGHT);
	ctx.setPosition(FRM_MAP_EDITING_ACTIONS_LEFT, FRM_MAP_EDITING_ACTIONS_TOP + CMD_PLAYER_ACTION_BUTTON_HEIGHT * GameFrame::EditingAction);
	GraphicsManager::renderSurface("ui\\lightbox.png", ctx);
}