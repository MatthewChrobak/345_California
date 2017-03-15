#include "GameRenderer.h"
#include "SurfaceContext.h"
#include "GraphicsManager.h"
#include "GuiManager.h"

void GameRenderer::drawGame()
{
	// Make sure we're actually in game.
	if (Game::getState() != GameState::InGame) {
		return;
	}

	// Render the background image.
	GameRenderer::drawBackground();

	// Render all the nodes.
	GameRenderer::drawCities();

	// Render the player.
	GameRenderer::drawPlayers();
}



void GameRenderer::drawPlayers()
{
	Board* board = Game::getGameBoard();
	int numPlayers = board->getNumberOfPlayers();
	Player& currentTurnPlayer = board->getCurrentTurnPlayer();

	// Draw every player except the current turn.
	for (int i = 0; i < numPlayers; i++) {
		Player& player = board->getPlayer(i);
		if (&currentTurnPlayer != &player) {
			GameRenderer::drawPlayer(player);
		}
	}

	// Draw the player with the current turn.
	GameRenderer::drawPlayer(currentTurnPlayer);
}

void GameRenderer::drawBackground()
{
	SurfaceContext ctx;
	ctx.size = new Vector2D(DRAW_WIDTH, DRAW_HEIGHT);
	GraphicsManager::renderSurface("backgrounds\\world.png", ctx);
}

void GameRenderer::drawCities()
{
	// Get the game board and the number of cities.
	Board* board = Game::getGameBoard();
	unsigned int numCities = board->getNumCities();

	// Draw all the connections so that they appear under the nodes.
	for (unsigned int i = 0; i < numCities; i++) {
		GameRenderer::drawCityConnections(*board->getCity(i));
	}

	// Draw all the nodes and their names.
	for (unsigned int i = 0; i < numCities; i++) {
		City* city = board->getCity(i);
		GameRenderer::drawCityNode(*city);
		GameRenderer::drawCityName(*city);
	}
}

void GameRenderer::drawCityNode(City& city)
{
	SurfaceContext ctx;
	ctx.position = new Vector2D(city.x - (CITY_RENDER_WIDTH / 2), city.y - (CITY_RENDER_HEIGHT / 2));
	ctx.size = new Vector2D(CITY_RENDER_WIDTH, CITY_RENDER_HEIGHT);

	// Assign the appropriate color.
	switch (city.color) {
	case InfectionColor::Red:
		ctx.color = new RGBA(255, 0, 0);
		break;
	case InfectionColor::Blue:
		ctx.color = new RGBA(0, 0, 255);
		break;
	case InfectionColor::Yellow:
		ctx.color = new RGBA(255, 255, 0);
		break;
	case InfectionColor::Black:
		ctx.color = new RGBA(0, 0, 0);
		break;
	}

	// Pass it off to the graphics manager to render it.
	GraphicsManager::renderSurface("nodes\\node.png", ctx);
}

void GameRenderer::drawCityName(City& city)
{
	// Rrender the name of the city just underneath it.
	TextContext ctx;
	ctx.fillColor = new RGBA(255, 255, 255);
	ctx.horizontalCenter = true;
	ctx.position = new Vector2D(city.x, city.y + (CITY_RENDER_HEIGHT / 2));
	ctx.fontSize = 9;

	// Pass it off to the graphics manager to render it.
	GraphicsManager::renderText(city.name, ctx);
}

void GameRenderer::drawCityConnections(City& city)
{
	SurfaceContext ctx;

	// Get all the nodes connected to the city.
	auto adjacentNodes = city.getAdjacentNodes();

	for (unsigned int i = 0; i < adjacentNodes.size(); i++) {
		City* adjacentNode = Game::getGameBoard()->getCity(adjacentNodes.at(i));

		// Get the width of the hypotenuse between this city and its adjacent node.
		int width = adjacentNode->x - city.x;
		int height = adjacentNode->y - city.y;
		double hypLength = std::sqrt(width * width + height * height);

		// Figure out the rotation value and convert it from radians to degrees (180/pi).
		double degrees = std::atan2(height, width) * 57.2957795130823209;

		int lineHeight = 1;

		// Inverse the angle of rotation if we're on specific connecting cities.
		if (city.inverseAngle && adjacentNode->inverseAngle) {
			degrees = 180 - degrees;
			lineHeight = 2;
		}


		// Reset and adjust the context.
		ctx.reset();
		ctx.size = new Vector2D((int)hypLength, lineHeight);
		ctx.rotation = (float)degrees;
		ctx.position = new Vector2D(city.x, city.y);

		// Pass the context off to the graphics manager to render it.
		GraphicsManager::renderSurface("nodes\\line.png", ctx);
	}
}

void GameRenderer::drawPlayer(Player& player)
{
	int cityIndex = player.pawn->cityIndex;

	// Ensure that the city index is within the bounds of the graph.
	if (cityIndex >= 0 && cityIndex < Game::getGameBoard()->getNumCities()) {
		City* city = Game::getGameBoard()->getCity(cityIndex);
		SurfaceContext ctx;

		// Set the position of the player.
		ctx.position = new Vector2D(city->x - 10, city->y - 20);
		ctx.size = new Vector2D(20, 20);
		GraphicsManager::renderSurface("pawns\\pawn.png", ctx);
	}
}