#include "GameRenderer.h"
#include "SurfaceContext.h"
#include "GraphicsManager.h"
#include "Game.h"
#include "City.h"

void GameRenderer::drawGame()
{
	SurfaceContext surfaceContext;
	TextContext textContext;


	// Render the background image.
	surfaceContext.Size = new Vector2D(960, 640);
	GraphicsManager::renderSurface("backgrounds\\world.png", surfaceContext);



	// Get the number of cities.
	int numCities = Game::getGameBoard()->getNumCities();

	// Draw all the edges joining the cities.
	for (int i = 0; i < numCities; i++) 
	{
		// Get all the nodes connected to one node.
		City* primaryNode = Game::getGameBoard()->getCity(i);
		std::vector<int> adjacentNodes = primaryNode->getAdjacentNodes();

		for (int x = 0; x < adjacentNodes.size(); x++) {
			City* adjacentNode = Game::getGameBoard()->getCity(adjacentNodes[x]);

			// Get the length of the hypotenuse between the primary and adjacent node.
			int width = adjacentNode->X - primaryNode->X;
			int height = adjacentNode->Y - primaryNode->Y;
			double hypLength = std::sqrt(width * width + height * height);
			
			// Figure out the rotation value and convert it from radians to degrees (180/pi).
			double degrees = std::atan2(height, width) * 57.2957795131;

			// Reset the context, and modify it to render the edge.
			surfaceContext.reset();
			surfaceContext.Size = new Vector2D(hypLength, 5);
			surfaceContext.Rotation = degrees;
			surfaceContext.Position = new Vector2D(primaryNode->X, primaryNode->Y);

			// Pass the context off to the graphics manager to render it.
			GraphicsManager::renderSurface("nodes\\line.png", surfaceContext);
		}
	}
	

	// Render all the city nodes.
	for (int i = 0; i < numCities; i++) {
		City* city = Game::getGameBoard()->getCity(i);

		// Reset the context, and modify it to render the node.
		surfaceContext.reset();
		surfaceContext.Position = new Vector2D(city->X - (City::Width / 2), city->Y - (City::Height / 2));
		surfaceContext.Size = new Vector2D(City::Width, City::Height);

		// Assign the appropriate color.
		switch (city->Color)
		{
			case InfectionColor::Red:
				surfaceContext.Color = new RGBA(255, 0, 0);
				break;
			case InfectionColor::Blue:
				surfaceContext.Color = new RGBA(0, 0, 255);
				break;
			case InfectionColor::Yellow:
				surfaceContext.Color = new RGBA(255, 255, 0);
				break;
			case InfectionColor::Black:
				surfaceContext.Color = new RGBA(0, 0, 0);
				break;
		}

		// Pass it off to the graphics manager to render it.
		GraphicsManager::renderSurface("nodes\\node.png", surfaceContext);


		// Reset the text context, and render the name of the city just underneath it.
		textContext.reset();
		textContext.FillColor = new RGBA(0, 0, 0); 
		textContext.HorizontalCenter = true;
		textContext.Position = new Vector2D(city->X, city->Y + (City::Height / 2));
		textContext.FontSize = 12;

		// Pass it off to the graphics manager to render it.
		GraphicsManager::renderText(city->Name, textContext);
	}
}