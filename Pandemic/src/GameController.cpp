#pragma once
#include "GameController.h"
#include "GameView.h"

GameController::GameController() : GameFrame()
{
	this->view = new GameView(this);
}

GameController::~GameController()
{

}

void GameController::draw()
{
	this->view->clear();
	this->view->draw();
	this->view->display();
}