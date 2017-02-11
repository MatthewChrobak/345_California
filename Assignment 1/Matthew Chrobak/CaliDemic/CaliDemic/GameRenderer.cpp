#include "GameRenderer.h"
#include "SurfaceContext.h"
#include "GraphicsManager.h"

void GameRenderer::drawGame()
{
	SurfaceContext ctx;
	ctx.SurfaceRect = new Rect(0, 0, 32, 32);
	ctx.Position = new Vector2D(50, 50);
	GraphicsManager::renderSurface("nodes\\images.png", ctx);

	ctx.SurfaceRect->Left = 32;
	ctx.Position->X = 100;
	ctx.Position->Y = 100;
	ctx.Size = new Vector2D(100, 100);
	GraphicsManager::renderSurface("nodes\\images.png", ctx);
}