#include "Frames.h"
#include "Buttons.h"
#include "Textboxes.h"
#include "Game.h"
#include "PlayerActions.h"
#include "CityCard.h"
#include "GuiManager.h"
#include "EventCard.h"
#include "EpidemicCard.h"
#include "Checkboxes.h"

PlayerActions GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
MapEditingActions GameFrame::EditingAction;
int GameFrame::EditNodeIndex = 0;

GameFrame::GameFrame() : UIFrame(FRM_GAME_FRAME)
{
	this->surfaceName = "ui/frame.png";
	this->width = FRM_GAME_FRAME_WIDTH;
	this->height = FRM_GAME_FRAME_HEIGHT;
	this->_elements.push_back(new ToggleActionsButton());
	this->_elements.push_back(new PlayerActionsFrame());
	this->_elements.push_back(new PlayerCardsFrame());
}

bool GameFrame::onMouseDown(std::string button, int x, int y)
{
	Board* board = Game::getGameBoard();
	Player& player = board->getCurrentTurnPlayer();
	int roleCardIndex = player.getRoleCard()->getRoleCardVal();
	int numCities = board->getNumCities();
	// Maybe we can exit out early.
	if (UIFrame::onMouseDown(button, x, y)) {
		return true;
	}

	if (button == "left") {
		Board* board = Game::getGameBoard();

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
						Game::decrementActionCounter();
						//If turn is changed, show this message
						GameFrame::PlayerAction = PlayerActions::NoPlayerAction;
						Board::checkTurn();
						break;
					}
				}
				break;
			}
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
			default:
				GuiManager::showMsgBox("Tried to perform an action on " + GameFrame::PlayerAction);
				break;
			}
			
		}
		
	}
	return true;
}

void GameFrame::draw()
{
	UIFrame::draw();
}

bool GameFrame::onKeyDown(std::string key)
{
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
	this->surfaceName = "ui/panel.png";
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
	this->surfaceName = "ui/mainmenu.png";
	this->width = FRM_MAIN_MENU_WIDTH;
	this->height = FRM_MAIN_MENU_HEIGHT;

	this->_elements.push_back(new SaveNameTextbox());
	this->_elements.push_back(new PlayGameButton());
	this->_elements.push_back(new NumPlayersFrame());
}


PlayerCardsFrame::PlayerCardsFrame() : UIFrame(FRM_PLAYER_CARDS)
{
	this->surfaceName = "ui/textbox.png";
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

		// Render the card as a city card if it's a city card.
		if (card->getType() == PlayerCardType::City_Card) {
			// Get the city from its index.
			int cityIndex = ((CityCard*)card)->cityIndex;

			if (cityIndex >= 0 && cityIndex < Game::getGameBoard()->getNumCities()) {
				City* city = Game::getGameBoard()->getCity(cityIndex);

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
				GraphicsManager::getInstance().renderSurface("cards/citycard.png", sCtx);
				GraphicsManager::getInstance().renderText(city->name, tCtx);
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
			GraphicsManager::getInstance().renderSurface("cards/eventcard.png", sCtx);
			GraphicsManager::getInstance().renderText(((EventCard*)card)->getEventName(), tCtx);
		}

		// Do we render the selector?
		for (unsigned int cardDataIndex = 0; cardDataIndex < this->_cardData.size(); cardDataIndex++) {
			if (this->_cardData.at(cardDataIndex) == i) {
				GraphicsManager::getInstance().renderSurface("cards/cardselect.png", sCtx);
				break;
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


NumPlayersFrame::NumPlayersFrame() : UIFrame(FRM_NUM_PLAYERS)
{
	this->surfaceName = "ui/mainmenu.png";
	this->width = FRM_NUM_PLAYERS_WIDTH;
	this->height = FRM_NUM_PLAYERS_HEIGHT;
	this->top = 0;
	this->left = 0;
	this->visible = false;

	this->_elements.push_back(new SelectTwoPlayerGame());
	this->_elements.push_back(new SelectThreePlayerGame());
	this->_elements.push_back(new SelectFourPlayerGame());
}