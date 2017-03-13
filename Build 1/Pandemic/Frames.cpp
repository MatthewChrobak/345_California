#include "Frames.h"
#include "Buttons.h"
#include "Textboxes.h"
#include "Game.h"
#include "GraphicsManager.h"

GameFrame::GameFrame() : UIFrame(FRM_GAME_FRAME)
{
	this->surfaceName = "ui\\frame.png";
	this->width = DRAW_WIDTH;
	this->height = DRAW_HEIGHT;
	this->_elements.push_back(new ToggleActionsButton());
	this->_elements.push_back(new PlayerActionsFrame());
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

			int halfWidth = City::RenderWidth / 2;
			int halfHeight = City::RenderHeight / 2;

			// Are we within the bounds of the current city?
			if (centerX - halfWidth <= x && centerX + halfWidth >= x) {
				if (centerY - halfHeight <= y && centerY + halfHeight >= y) {

					Player* player = board->player;
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
		City* city = Game::getGameBoard()->getCity(Game::getGameBoard()->player->pawn->cityIndex);
		city->x = x;
		city->y = y;
	}
#endif
}


PlayerActionsFrame::PlayerActionsFrame() : UIFrame(FRM_PLAYER_ACTIONS)
{
	this->surfaceName = "ui\\panel.png";
	this->width = 100;
	this->height = 300;

	this->top = DRAW_HEIGHT - this->height - 10;
	this->left = DRAW_WIDTH - this->width - 10;
	this->visible = false;
}

void PlayerActionsFrame::onMouseDown(std::string button, int x, int y)
{
	this->visible = false;
}


MainMenuFrame::MainMenuFrame() : UIFrame(FRM_MAIN_MENU)
{
	this->surfaceName = "ui\\mainmenu.png";
	this->width = DRAW_WIDTH;
	this->height = DRAW_HEIGHT;

	this->_elements.push_back(new SaveNameTextbox());
	this->_elements.push_back(new PlayGameButton());
}