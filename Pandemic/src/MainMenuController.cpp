#include "MainMenuController.h"
#include "MainMenuView.h"

MainMenuController::MainMenuController() : MainMenuFrame(nullptr)
{
	this->view = new MainMenuView(this);
}

MainMenuController::~MainMenuController()
{

}

void MainMenuController::draw()
{
	this->view->clear();
	this->view->draw();
	this->view->display();
}