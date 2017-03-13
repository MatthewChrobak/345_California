#pragma once
#include "Game.h"

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
};

