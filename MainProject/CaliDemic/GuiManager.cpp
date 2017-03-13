#include "GuiManager.h"
#include "Game.h"
#include "GraphicsManager.h"
#include <iostream>

int GuiManager::WindowHeight = DRAW_HEIGHT;
int GuiManager::WindowWidth = DRAW_WIDTH;

#ifdef ADMIN_EDITOR
bool GuiManager::connectNode = false;
bool GuiManager::moveMode = false;
bool GuiManager::teleportNode = false;
bool GuiManager::addNode = false;
#endif

void GuiManager::handleMouseDown(int x, int y, std::string button)
{
	// Make sure the coordinate account for window resizing.
	GuiManager::convertCoords(&x, &y);

	if (button == "left") {
		int numCities = Game::getGameBoard()->getNumCities();
		City* playerCity = Game::getGameBoard()->getCity(Game::getGameBoard()->player->pawn->cityIndex);

#ifdef ADMIN_EDITOR
		if (GuiManager::addNode) {
			City::consoleAddNodeAtCoordDialogue(x, y);
		}
#endif

		// Figure out if we clicked on a city
		for (int i = 0; i < numCities; i++) {

			City* city = Game::getGameBoard()->getCity(i);
			int centerX = city->x;
			int centerY = city->y;

			int halfWidth = City::RenderWidth / 2;
			int halfHeight = City::RenderHeight / 2;

			// Are we within the bounds of the current scity?
			if (centerX - halfWidth <= x && centerX + halfWidth >= x) {
				if (centerY - halfHeight <= y && centerY + halfHeight >= y) {

#ifdef ADMIN_EDITOR
					if (GuiManager::connectNode) {
						Game::getGameBoard()->getCity(i)->addAdjacentNode(Game::getGameBoard()->player->pawn->cityIndex);
						return;
					}
					if (GuiManager::teleportNode) {
						Game::getGameBoard()->player->pawn->cityIndex = i;
						return;
					}
#endif
					
					// Figure out if the city is adjacent to the city we're currently at.
					// If so, move to that city.
					std::vector<int> adjacents = playerCity->getAdjacentNodes();

					for (int k = 0; k < adjacents.size(); k++) {
						if (i == adjacents[k]) {
							Game::getGameBoard()->player->pawn->cityIndex = i;
							break;
						}
					}

					break;
				}
			}

		}
	}
}

void GuiManager::handleWindowResize(int x, int y)
{
	GuiManager::WindowWidth = x;
	GuiManager::WindowHeight = y;
}

void GuiManager::handleMouseUp(int x, int y, std::string button)
{
	// Make sure the coordinate account for window resizing.
	GuiManager::convertCoords(&x, &y);
}

void GuiManager::handleMouseMove(int x, int y)
{
	// Make sure the coordinate account for window resizing.
	GuiManager::convertCoords(&x, &y);

#ifdef ADMIN_EDITOR
	if (GuiManager::moveMode) {
		City* city = Game::getGameBoard()->getCity(Game::getGameBoard()->player->pawn->cityIndex);

		city->x = x;
		city->y = y;
	}
#endif
}

void GuiManager::handleKeyDown(char key)
{
#ifdef ADMIN_EDITOR
	switch (key) {
		// 'a' - key
		case 0:
			GuiManager::addNode = true;
			break;
		// 'c' - key
		case 2:
			GuiManager::connectNode = true;
			break;
		// 'm' - key
		case 12:
			GuiManager::moveMode = true;
			break;
		// 's' - key
		case 18:
			Game::save();
			break;
		// 't' - key
		case 19:
			GuiManager::teleportNode = true;
			break;
		default:
			std::cout << "KeyDown: " << (int)key << std::endl;
			break;
	}
#endif
}

void GuiManager::handleKeyUp(char key)
{
#ifdef ADMIN_EDITOR
	switch (key) {
		// 'a' - key
		case 0:
			GuiManager::addNode = false;
			break;
		// 'c' - key
		case 2:
			GuiManager::connectNode = false;
			break;
		// 'm' - key
		case 12:
			GuiManager::moveMode = false;
			break;
		// 't' - key
		case 19:
			GuiManager::teleportNode = false;
			break;
		default:
			std::cout << "KeyDown: " << (int)key << std::endl;
			break;
	}
#endif
}

void GuiManager::draw()
{
}

void GuiManager::convertCoords(int* x, int* y)
{
	// Apply the ratio conversion.
	*x = (DRAW_WIDTH / (float)GuiManager::WindowWidth) * *x;
	*y = (DRAW_HEIGHT / (float)GuiManager::WindowHeight) * *y;
}