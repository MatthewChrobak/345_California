#include "GameRenderer.h"
#include "SurfaceContext.h"
#include "GraphicsManager.h"
#include "Game.h"
#include "City.h"


void GameRenderer::drawGame()
{
	SurfaceContext ctx;
	ctx.Size = new Vector2D(960, 640);
	GraphicsManager::renderSurface("backgrounds\\world.png", ctx);

	int numCities = Game::getGameBoard()->getNumCities();

	for (int i = 0; i < numCities; i++) {
		City* city = Game::getGameBoard()->getCity(i);

		ctx.reset();
		ctx.SurfaceRect = new Rect(0, 0, 32, 32);
		ctx.Position = new Vector2D(city->x, city->y);
		GraphicsManager::renderSurface("nodes\\images.png", ctx);
	}
}