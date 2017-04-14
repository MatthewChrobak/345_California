#include "MainMenuController.h"
#include "MainMenuView.h"

MainMenuController::MainMenuController()
{
	this->view = new MainMenuView(this);
}

MainMenuController::~MainMenuController()
{

}

void MainMenuController::handleMouseDown(int x, int y, std::string button)
{

}

void MainMenuController::handleMouseUp(int x, int y, std::string button)
{
	
}

void MainMenuController::handleMouseMove(int x, int y)
{

}

void MainMenuController::handleKeyDown(std::string key)
{

}

void MainMenuController::handleKeyUp(std::string key)
{

}

void MainMenuController::draw()
{
	this->view->clear();
	this->view->draw();
	this->view->display();
}