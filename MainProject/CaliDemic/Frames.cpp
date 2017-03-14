#include "Frames.h"
#include "Buttons.h"
#include "Textboxes.h"
#include "Game.h"
#include "PlayerActions.h"
#include "CityCard.h"
#include "GuiManager.h"

GameFrame::GameFrame() : UIFrame(FRM_GAME_FRAME)
{
	this->surfaceName = "ui\\frame.png";
	this->width = FRM_GAME_FRAME_WIDTH;
	this->height = FRM_GAME_FRAME_HEIGHT;
	this->_elements.push_back(new ToggleActionsButton());
	this->_elements.push_back(new PlayerActionsFrame());
	this->_elements.push_back(new PlayerCardsFrame());
}

void GameFrame::onMouseDown(std::string button, int x, int y)
{
	UIFrame::onMouseDown(button, x, y);

	if (button == "left") {
		Board* board = Game::getGameBoard();
		int numCities = board->getNumCities();

#ifdef ADMIN_EDITOR
		if (this->_addNode) {
			City::consoleAddNodeAtCoordDialogue(x, y);
		}
#endif

		// Figure out if we clicked on a city
		for (int i = 0; i < numCities; i++) {

			City* city = board->getCity(i);
			int centerX = city->x;
			int centerY = city->y;

			int halfWidth = CITY_RENDER_WIDTH / 2;
			int halfHeight = CITY_RENDER_HEIGHT / 2;

			// Are we within the bounds of the current city?
			if (centerX - halfWidth <= x && centerX + halfWidth >= x) {
				if (centerY - halfHeight <= y && centerY + halfHeight >= y) {

					Player* player = &board->getCurrentTurnPlayer();
					int playerCityIndex = player->pawn->cityIndex;
					City* playerCity = nullptr;

					// Get the city, if it exists on the board.
					if (playerCityIndex >= 0 && playerCityIndex < numCities) {
						playerCity = board->getCity(playerCityIndex);
					}

#ifdef ADMIN_EDITOR
					if (this->_connectNode) {
						board->getCity(i)->addAdjacentNode(playerCityIndex);
						return;
					}
					if (this->_teleportNode) {
						player->pawn->cityIndex = i;
						return;
					}
#endif

					if (playerCity != nullptr) {
						// Figure out if the city is adjacent to the city we're currently at.
						// If so, move to that city.
						std::vector<int> adjacents = playerCity->getAdjacentNodes();

						for (unsigned int k = 0; k < adjacents.size(); k++) {
							if (i == adjacents[k]) {
								player->pawn->cityIndex = i;
								break;
							}
						}

					}
					break;
				}
			}

		}
	}
}

void GameFrame::onKeyDown(std::string key)
{
#ifdef ADMIN_EDITOR
	if (Game::getState() == GameState::InGame) {
		if (key == "a") {
			this->_addNode = true;
		}
		else if (key == "c") {
			this->_connectNode = true;
		}
		else if (key == "m") {
			this->_moveMode = true;
		}
		else if (key == "s") {
			Game::save();
		}
		else if (key == "t") {
			this->_teleportNode = true;
		}
	}
#endif
}

void GameFrame::onKeyUp(std::string key)
{
#ifdef ADMIN_EDITOR
	if (Game::getState() == GameState::InGame) {
		if (key == "a") {
			this->_addNode = false;
		}
		else if (key == "c") {
			this->_connectNode = false;
		}
		else if (key == "m") {
			this->_moveMode = false;
		}
		else if (key == "t") {
			this->_teleportNode = false;
		}
	}
#endif
}

void GameFrame::onMouseMove(int x, int y)
{
#ifdef ADMIN_EDITOR
	if (this->_moveMode) {
		Board* board = Game::getGameBoard();
		City* city = board->getCity(board->getCurrentTurnPlayer().pawn->cityIndex);
		city->x = x;
		city->y = y;
	}
#endif
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

void PlayerActionsFrame::onMouseDown(std::string button, int x, int y)
{
	UIFrame::onMouseDown(button, x, y);
	this->visible = false;
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
	this->_elements.push_back(new PlayerCardsOkay(&this->_currentAction, &this->_cardData));
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

void PlayerCardsFrame::onMouseDown(std::string button, int x, int y)
{
	Player& player = Game::getGameBoard()->getCurrentTurnPlayer();
	UIFrame::onMouseDown(button, x, y);

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
}

void PlayerCardsFrame::show(PlayerActions action)
{
	this->_currentAction = action;
	this->_cardData.erase(this->_cardData.begin(), this->_cardData.end());
	this->visible = true;

	switch (action)
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