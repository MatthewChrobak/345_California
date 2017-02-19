#include "GuiManager.h"
#include "Game.h"
#include "GraphicsManager.h"
#include <iostream>

int GuiManager::WindowHeight = DRAW_HEIGHT;
int GuiManager::WindowWidth = DRAW_WIDTH;
bool GuiManager::connectNode = false;
bool GuiManager::moveMode = false;
bool GuiManager::teleportNode = false;
bool GuiManager::addNode = false;

void GuiManager::handleMouseDown(int x, int y, std::string button)
{
	// Make sure the coordinate account for window resizing.
	GuiManager::convertCoords(&x, &y);

	if (button == "left") {
		int numCities = Game::getGameBoard()->getNumCities();
		City* playerCity = Game::getGameBoard()->getCity(Game::getGameBoard()->player->pawn->cityIndex);

		if (GuiManager::addNode) {
			City::consoleAddNodeAtCoordDialogue(x, y);
		}

		for (int i = 0; i < numCities; i++) {

			City* city = Game::getGameBoard()->getCity(i);
			int centerX = city->x;
			int centerY = city->y;

			int halfWidth = City::RenderWidth / 2;
			int halfHeight = City::RenderHeight / 2;


			if (centerX - halfWidth <= x && centerX + halfWidth >= x) {
				if (centerY - halfHeight <= y && centerY + halfHeight >= y) {

					if (GuiManager::connectNode) {
						Game::getGameBoard()->getCity(i)->addAdjacentNode(Game::getGameBoard()->player->pawn->cityIndex);
					} else if (GuiManager::teleportNode) {
						Game::getGameBoard()->player->pawn->cityIndex = i;
					} else {

						std::vector<int> adjacents = playerCity->getAdjacentNodes();

						for (int k = 0; k < adjacents.size(); k++) {
							if (i == adjacents[k]) {
								Game::getGameBoard()->player->pawn->cityIndex = i;
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

	if (GuiManager::moveMode) {
		City* city = Game::getGameBoard()->getCity(Game::getGameBoard()->player->pawn->cityIndex);

		city->x = x;
		city->y = y;
	}
}

void GuiManager::handleKeyDown(char key)
{
	switch (key) {
		case 0:
			GuiManager::addNode = true;
			break;
		case 2:
			GuiManager::connectNode = true;
			break;
		case 12:
			GuiManager::moveMode = true;
			break;
		case 18:
			Game::save();
			break;
		case 19:
			GuiManager::teleportNode = true;
			break;
		default:
			std::cout << "KeyDown: " << (int)key << std::endl;
			break;
	}
}

void GuiManager::handleKeyUp(char key)
{
	switch (key) {
		case 0:
			GuiManager::addNode = false;
			break;
		case 2:
			GuiManager::connectNode = false;
			break;
		case 12:
			GuiManager::moveMode = false;
			break;
		case 19:
			GuiManager::teleportNode = false;
			break;
		default:
			std::cout << "KeyDown: " << (int)key << std::endl;
			break;
	}
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