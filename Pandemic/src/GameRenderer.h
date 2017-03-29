/*!
	Author: Matthew Chrobak
	Contributors:

	Purpose: Utilizes the render and text context classes to specify how the game should be rendered.
*/
#pragma once
#include "SurfaceContext.h"
#include "TextContext.h"

class GameRenderer
{
public:
	void drawGame();

private:
	void drawBackground();

	void drawCities();
	void drawCityNode(City& city);
	void drawCityConnections(City& city);
	void drawCityName(City& city);

	void drawPlayers();
	void drawPlayer(Player& player);

	void drawOutbreakMeter();
	void drawInfectionRate();

	void drawCureMarkers();
};