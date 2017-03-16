#include "GameRenderer.h"
#include "SurfaceContext.h"
#include "GraphicsManager.h"
#include "GuiManager.h"
#include "Frames.h"

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

	// Draw the game data.
	GameRenderer::drawInfectionRate();
	GameRenderer::drawOutbreakMeter();
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
	int numCities = board->getNumCities();

	// Draw all the connections so that they appear under the nodes.
	for (int i = 0; i < numCities; i++) {
		GameRenderer::drawCityConnections(*board->getCity(i));
	}

	// Draw all the nodes and their names.
	for (int i = 0; i < numCities; i++) {
		City* city = board->getCity(i);
		GameRenderer::drawCityNode(*city);
		GameRenderer::drawCityName(*city);
	}

	// Are we currently trying to do an action?
	if (GameFrame::PlayerAction == PlayerActions::Drive) {
		// We're trying to drive. Make sure we know what cities we can go to.
		Player& player = board->getCurrentTurnPlayer();
		int playerCityIndex = player.pawn->cityIndex;

		// Is it a valid city?
		if (playerCityIndex >= 0 && playerCityIndex < board->getNumCities()) {
			// Get the city and its adjacent nodes.
			City* playerCity = board->getCity(playerCityIndex);
			auto adjacentCities = playerCity->getAdjacentNodes();

			// Loop through every city.
			for (unsigned int i = 0; i < adjacentCities.size(); i++) {
				int cityIndex = adjacentCities.at(i);

				// Is it a valid city?
				if (cityIndex >= 0 && cityIndex < board->getNumCities()) {
					City* city = board->getCity(cityIndex);

					// It is. Render it.
					SurfaceContext ctx;
					ctx.position = new Vector2D(city->x - (CITY_RENDER_WIDTH / 2), city->y - (CITY_RENDER_HEIGHT / 2));
					ctx.size = new Vector2D(CITY_RENDER_WIDTH, CITY_RENDER_HEIGHT);

					GraphicsManager::renderSurface("ui\\selectbox.png", ctx);
				}
			}
		}
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
	
	int cubeHeight = CITY_RENDER_HEIGHT / 3;

	//update Counter the when there's a cube value 
	for (int i = 0; i < 3; i++){
		if (city.cube[i] >= 0){
			// Reset the context.
			ctx.reset();
			ctx.position = new Vector2D(city.x + CITY_RENDER_WIDTH / 2, city.y - CITY_RENDER_HEIGHT / 2 + i * cubeHeight);
			ctx.size = new Vector2D(cubeHeight, cubeHeight);

			int cubeColor = city.cube[i];
			switch (cubeColor) {
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
		
			GraphicsManager::renderSurface("nodes\\cube.png", ctx);
		}
	}

	// If the city has a research center, render it.
	if (city.research) {
		ctx.reset();
		ctx.position = new Vector2D(city.x - CITY_RENDER_WIDTH / 2 - CITY_RENDER_HEIGHT / 3, city.y - CITY_RENDER_HEIGHT / 2 + CITY_RENDER_HEIGHT / 3);
		ctx.size = new Vector2D(CITY_RENDER_WIDTH / 3, CITY_RENDER_HEIGHT / 3);
		GraphicsManager::renderSurface("nodes\\cross.png", ctx);
	}
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

void GameRenderer::drawOutbreakMeter()
{
	SurfaceContext ctx;

	// Get the dimentions of the actual surface.
	int textureFullHeight = 468;
	int textureWidth = 100;
	int textureHeight = textureFullHeight / 9;

	// From the actual dimentions, generate render dimentions.
	int fullHeight = textureFullHeight / 2;
	int renderHeight = textureHeight / 2;
	int renderWidth = textureWidth / 2;

	// Go through all nine nodes and render each one individually.
	for (int i = 0; i < 9; i++) {
		ctx.reset();
		ctx.position = new Vector2D(25, DRAW_HEIGHT - fullHeight - 70 + i * renderHeight);
		ctx.surfaceRect = new Rect(i * textureHeight, 0, textureWidth, textureHeight);
		ctx.size = new Vector2D(renderWidth, renderHeight);

		// Darken the color of all nodes except the current outbreak value.
		// TODO: This should be changed to
		//
		// if (i != Game::outbreakValue) {
		//
		// or whatever the outbreak value variable is.
		if (i != 0) {
			ctx.color = new RGBA(100, 100, 100);
		}

		GraphicsManager::renderSurface("ui\\outbreakmeter.png", ctx);
	}
}

void GameRenderer::drawInfectionRate()
{
	TextContext ctx;

	ctx.position = new Vector2D(10, DRAW_HEIGHT - 50);
	ctx.fontSize = 24;
	ctx.fillColor = new RGBA(255, 255, 255);
	ctx.outlineThickness = 2;
	ctx.outlineColor = new RGBA(0, 0, 0);

	// This should be changed to append the current infection rate to the rendered text.
	GraphicsManager::renderText("Infection Rate: 1", ctx);
}