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
	GameRenderer::drawCureMarkers();
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
	ctx.setRenderSize(DRAW_WIDTH, DRAW_HEIGHT);
	GraphicsManager::getInstance().renderSurface("backgrounds/world.png", ctx);
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
					ctx.setPosition(city->x - (CITY_RENDER_WIDTH / 2), city->y - (CITY_RENDER_HEIGHT / 2));
					ctx.setRenderSize(CITY_RENDER_WIDTH, CITY_RENDER_HEIGHT);

					GraphicsManager::getInstance().renderSurface("ui/selectbox.png", ctx);
				}
			}
		}
	}
}

void GameRenderer::drawCityNode(City& city)
{
	SurfaceContext ctx;
	ctx.setPosition(city.x - (CITY_RENDER_WIDTH / 2), city.y - (CITY_RENDER_HEIGHT / 2));
	ctx.setRenderSize(CITY_RENDER_WIDTH, CITY_RENDER_HEIGHT);

	// Assign the appropriate color.
	switch (city.color) {
	case InfectionColor::Red:
		ctx.setColor(255, 0, 0);
		break;
	case InfectionColor::Blue:
		ctx.setColor(0, 0, 255);
		break;
	case InfectionColor::Yellow:
		ctx.setColor(255, 255, 0);
		break;
	case InfectionColor::Black:
		ctx.setColor(0, 0, 0);
		break;
	}

	// Pass it off to the graphics manager to render it.
	GraphicsManager::getInstance().renderSurface("nodes/node.png", ctx);
	
	int cubeHeight = CITY_RENDER_HEIGHT / 4;

	//update Counter the when there's a cube value 
	for (int color = 0; color < InfectionColor::InfectionColor_Length; color++) {
		for (int i = 0; i < city.cube[color]; i++) {
			// Reset the context.
			ctx.reset();
			ctx.setPosition(city.x + CITY_RENDER_WIDTH / 2 + i * 5, city.y - CITY_RENDER_HEIGHT / 2 + color * cubeHeight);
			ctx.setRenderSize(cubeHeight, cubeHeight);

			switch (color) {
				case InfectionColor::Red:
					ctx.setColor(255, 0, 0);
					break;
				case InfectionColor::Blue:
					ctx.setColor(0, 0, 255);
					break;
				case InfectionColor::Yellow:
					ctx.setColor(55, 255, 0);
					break;
				case InfectionColor::Black:
					ctx.setColor(50, 50, 50);
					break;
			}

			GraphicsManager::getInstance().renderSurface("nodes/cube.png", ctx);
		}
	}

	// If the city has a research center, render it.
	if (city.research) {
		ctx.reset();
		ctx.setPosition(city.x - CITY_RENDER_WIDTH / 2 - CITY_RENDER_HEIGHT / 3, city.y - CITY_RENDER_HEIGHT / 2 + CITY_RENDER_HEIGHT / 3);
		ctx.setRenderSize(CITY_RENDER_WIDTH / 3, CITY_RENDER_HEIGHT / 3);
		GraphicsManager::getInstance().renderSurface("nodes/cross.png", ctx);
	}
}

void GameRenderer::drawCityName(City& city)
{
	// Rrender the name of the city just underneath it.
	TextContext ctx;
	ctx.setFontColor(255, 255, 255);
	ctx.setHorizontalCenter(true);
	ctx.setPosition(city.x, city.y + (CITY_RENDER_HEIGHT / 2));
	ctx.setFontSize(9);

	// Pass it off to the graphics manager to render it.
	GraphicsManager::getInstance().renderText(city.name, ctx);
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
		ctx.setRenderSize((int)hypLength, lineHeight);
		ctx.setRotation((float)degrees);
		ctx.setPosition(city.x, city.y);

		// Pass the context off to the graphics manager to render it.
		GraphicsManager::getInstance().renderSurface("nodes/line.png", ctx);
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
		ctx.setPosition(city->x - 10, city->y - 20);
		ctx.setRenderSize(20, 20);
		GraphicsManager::getInstance().renderSurface("pawns/pawn.png", ctx);
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
		ctx.setPosition(25, DRAW_HEIGHT - fullHeight - 70 + i * renderHeight);
		ctx.setSurfaceRect(i * textureHeight, 0, textureWidth, textureHeight);
		ctx.setRenderSize(renderWidth, renderHeight);

		// Darken the color of all nodes except the current outbreak value.
		if (i != City::outbreakCount) {
			ctx.setColor(100, 100, 100);
		}

		GraphicsManager::getInstance().renderSurface("ui/outbreakmeter.png", ctx);
	}
}

void GameRenderer::drawInfectionRate()
{
	TextContext ctx;

	ctx.setPosition(10, DRAW_HEIGHT - 50);
	ctx.setFontSize(24);
	ctx.setFontColor(255, 255, 255);
	ctx.getOutline().setThickness(2);
	ctx.getOutline().setColor(0, 0, 0);

	// This should be changed to append the current infection rate to the rendered text.
	GraphicsManager::getInstance().renderText("Infection Rate: " + std::to_string(Game::getGameBoard()->getInfectionRate()), ctx);
}

void GameRenderer::drawCureMarkers()
{
	SurfaceContext ctx;
	Board* board = Game::getGameBoard();
	int drawWidth = 50;

	for (int i = 0; i < InfectionColor::InfectionColor_Length; i++) {
		ctx.reset();
		ctx.setPosition(DRAW_WIDTH / 2 - 2 * drawWidth + i * drawWidth, DRAW_HEIGHT - 60);
		ctx.setRenderSize(drawWidth, drawWidth);
		
		if (board->isCured[i]) {
			switch (i) {
				case InfectionColor::Black:
					ctx.setColor(50, 50, 50);
					break;
				case InfectionColor::Blue:
					ctx.setColor(0, 0, 255);
					break;
				case InfectionColor::Red:
					ctx.setColor(255, 0, 0);
					break;
				case InfectionColor::Yellow:
					ctx.setColor(255, 255, 0);
					break;
			}
			
		} else {
			switch (i) {
				case InfectionColor::Black:
					ctx.setColor(10, 10, 10);
					break;
				case InfectionColor::Blue:
					ctx.setColor(0, 0, 50);
					break;
				case InfectionColor::Red:
					ctx.setColor(50, 0, 0);
					break;
				case InfectionColor::Yellow:
					ctx.setColor(50, 50, 0);
					break;
			}
		}

		GraphicsManager::getInstance().renderSurface("ui/cure.png", ctx);

		if (board->isCured[i]) {
			ctx.getColor()->setR(0);
			ctx.getColor()->setG(255);
			ctx.getColor()->setB(0);
			GraphicsManager::getInstance().renderSurface("ui/hascure.png", ctx);
		}
	}
}