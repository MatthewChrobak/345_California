#include "GameRenderer.h"
#include "SurfaceContext.h"
#include "GraphicsManager.h"
#include "Game.h"
#include "City.h"
#include "GuiManager.h"

void GameRenderer::drawGame()
{
	// Make sure we're actually in game.
	if (Game::getState() != GameState::InGame) {
		return;
	}

	SurfaceContext surfaceContext;
	TextContext textContext;


	// Render the background image.
	surfaceContext.size = new Vector2D(DRAW_WIDTH, DRAW_HEIGHT);
	GraphicsManager::renderSurface("backgrounds\\world.png", surfaceContext);



	// Get the number of cities.
	int numCities = Game::getGameBoard()->getNumCities();

	// Draw all the edges joining the cities.
	for (int i = 0; i < numCities; i++) {
		// Get all the nodes connected to one node.
		City* primaryNode = Game::getGameBoard()->getCity(i);
		std::vector<int> adjacentNodes = primaryNode->getAdjacentNodes();

		for (unsigned int x = 0; x < adjacentNodes.size(); x++) {
			City* adjacentNode = Game::getGameBoard()->getCity(adjacentNodes[x]);

			// Get the length of the hypotenuse between the primary and adjacent node.
			int width = adjacentNode->x - primaryNode->x;
			int height = adjacentNode->y - primaryNode->y;
			double hypLength = std::sqrt(width * width + height * height);

			// Figure out the rotation value and convert it from radians to degrees (180/pi).
			double degrees = std::atan2(height, width) * 57.2957795130823209;


			// Inverse the angle of rotation if we're on specific connecting cities.
			char inverse = 0;
			int lineHeight = 1;

			if (primaryNode->name == "Tokyo") {
				inverse += adjacentNode->name == "San Francisco";
			}

			if (primaryNode->name == "San Francisco") {
				inverse += adjacentNode->name == "Tokyo";
				inverse += adjacentNode->name == "Manila";
			}

			if (primaryNode->name == "Manila") {
				inverse += adjacentNode->name == "San Francisco";
			}

			if (primaryNode->name == "Sydney") {
				inverse += adjacentNode->name == "Los Angeles";
			}

			if (primaryNode->name == "Los Angeles") {
				inverse += adjacentNode->name == "Sydney";
			}

			if (inverse) {
				degrees = 180 - degrees;
				lineHeight = 2;
			}

			// Reset the context, and modify it to render the edge.
			surfaceContext.reset();
			surfaceContext.size = new Vector2D((int)hypLength, lineHeight);
			surfaceContext.rotation = (float)degrees;
			surfaceContext.position = new Vector2D(primaryNode->x, primaryNode->y);

			// Pass the context off to the graphics manager to render it.
			GraphicsManager::renderSurface("nodes\\line.png", surfaceContext);
		}
	}


	// Render all the city nodes.
	for (int i = 0; i < numCities; i++) {
		City* city = Game::getGameBoard()->getCity(i);

		// Reset the context, and modify it to render the node.
		surfaceContext.reset();
		surfaceContext.position = new Vector2D(city->x - (City::RenderWidth / 2), city->y - (City::RenderHeight / 2));
		surfaceContext.size = new Vector2D(City::RenderWidth, City::RenderHeight);

		// Assign the appropriate color.
		switch (city->color) {
			case InfectionColor::Red:
				surfaceContext.color = new RGBA(255, 0, 0);
				break;
			case InfectionColor::Blue:
				surfaceContext.color = new RGBA(0, 0, 255);
				break;
			case InfectionColor::Yellow:
				surfaceContext.color = new RGBA(255, 255, 0);
				break;
			case InfectionColor::Black:
				surfaceContext.color = new RGBA(0, 0, 0);
				break;
		}

		// Pass it off to the graphics manager to render it.
		GraphicsManager::renderSurface("nodes\\node.png", surfaceContext);


		// Reset the text context, and render the name of the city just underneath it.
		textContext.reset();
		textContext.fillColor = new RGBA(255, 255, 255);
		textContext.horizontalCenter = true;
		textContext.position = new Vector2D(city->x, city->y + (City::RenderHeight / 2));
		textContext.fontSize = 9;

		// Pass it off to the graphics manager to render it.
		GraphicsManager::renderText(city->name, textContext);
	}


	// Render the player.
	Player* player = Game::getGameBoard()->player;

	int cityIndex = player->pawn->cityIndex;
	if (cityIndex < numCities) {
		City* playerCity = Game::getGameBoard()->getCity(cityIndex);
		surfaceContext.reset();
		surfaceContext.position = new Vector2D(playerCity->x - 10, playerCity->y - 20);
		surfaceContext.size = new Vector2D(20, 20);

		GraphicsManager::renderSurface("pawns\\pawn.png", surfaceContext);
	}
}