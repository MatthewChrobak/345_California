#include "GuiManager.h"
#include "Game.h"
#include "GraphicsManager.h"
#include "UIButton.h"
#include "Frames.h"
#include <iostream>

int GuiManager::WindowHeight = DRAW_HEIGHT;
int GuiManager::WindowWidth = DRAW_WIDTH;
std::vector<UIElement*> GuiManager::_uiElements[(int)GameState::GameState_Length];
UIElement* GuiManager::_currentFocusedElement = nullptr;

int GuiManager::_mouseX = 0;
int GuiManager::_mouseY = 0;

UIMessageBox GuiManager::_messageBox;

void GuiManager::initialize()
{
	auto menuScene = &GuiManager::_uiElements[(int)GameState::MainMenu];
	menuScene->push_back(new MainMenuFrame());


	auto gameScene = &GuiManager::_uiElements[(int)GameState::InGame];	
	gameScene->push_back(new GameFrame());
}

void GuiManager::destroy()
{
	for (int state = 0; state < (int)GameState::GameState_Length; state++) {
		for (unsigned int i = 0; i < GuiManager::_uiElements[state].size(); i++) {
			delete GuiManager::_uiElements[state].at(i);
			GuiManager::_uiElements[state].pop_back();
		}
	}

	GuiManager::_currentFocusedElement = nullptr;
}

void GuiManager::handleWindowClose()
{
	switch (Game::getState())
	{
		case GameState::InGame:
			Game::destroy();
			Game::changeState(GameState::MainMenu);
			break;
		case GameState::MainMenu:
			// Close the game.
			Game::changeState(GameState::Closed);
			break;
	}
}

void GuiManager::handleMouseDown(int x, int y, std::string button)
{
	// Make sure the coordinate account for window resizing.
	GuiManager::convertCoords(&x, &y);
	
	// Get the current scene.
	auto scene = GuiManager::getCurrentSceneUIElements();

	// Take away the focus from the currently focused UI element.
	GuiManager::_currentFocusedElement = nullptr;

	// Pass it off to the MessageBox if it's visible
	if (GuiManager::_messageBox.visible) {
		GuiManager::_messageBox.onMouseDown(button, x, y);
		return;
	}

	// Loop through every scene element until we find the element we
	// need to interact with.
	for (int i = (int)scene->size() - 1; i >= 0; i--) {
		UIElement* element = scene->at(i);

		if (element->visible) {
			if (element->left <= x && element->left + element->width >= x) {
				if (element->top <= y && element->top + element->height >= y) {

					// If there's a previous focused element, take away its focus.
					if (GuiManager::_currentFocusedElement != nullptr) {
						GuiManager::_currentFocusedElement->resetFocus();
					}

					// Set the currently focused UI element.
					GuiManager::_currentFocusedElement = element;
					element->onMouseDown(button, x, y);
					element->giveFocus();
					break;
				}
			}
		}
	}
}

void GuiManager::handleWindowResize(int x, int y)
{
	GuiManager::WindowWidth = x;
	GuiManager::WindowHeight = y;
}

void GuiManager::handleMouseUp(int x, int y, std::string button)
{
	// Make sure the coordinate account for window resizing.
	GuiManager::convertCoords(&x, &y);

	// Get the current scene.
	auto scene = GuiManager::getCurrentSceneUIElements();

	// Pass it off to the MessageBox if it's visible
	if (GuiManager::_messageBox.visible) {
		GuiManager::_messageBox.onMouseUp(button, x, y);
		return;
	}

	// Loop through every scene element until we find the element we
	// need to interact with.
	for (int i = (int)scene->size() - 1; i >= 0; i--) {
		UIElement* element = scene->at(i);

		if (element->visible) {
			if (element->left <= x && element->left + element->width >= x) {
				if (element->top <= y && element->top + element->height >= y) {
					element->onMouseUp(button, x, y);
					break;
				}
			}
		}
	}
}

void GuiManager::handleMouseMove(int x, int y)
{
	// Make sure the coordinate account for window resizing.
	GuiManager::convertCoords(&x, &y);

	// Save the mouse coordinates.
	GuiManager::_mouseX = x;
	GuiManager::_mouseY = y;

	// Get the current scene.
	auto scene = GuiManager::getCurrentSceneUIElements();

	// Pass it off to the MessageBox if it's visible
	if (GuiManager::_messageBox.visible) {
		GuiManager::_messageBox.onMouseMove(x, y);
		return;
	}

	// Loop through every scene element until we find the element we
	// need to interact with.
	for (int i = (int)scene->size() - 1; i >= 0; i--) {
		UIElement* element = scene->at(i);

		if (element->visible) {
			if (element->left <= x && element->left + element->width >= x) {
				if (element->top <= y && element->top + element->height >= y) {
					element->onMouseMove(x, y);
					break;
				}
			}
		}	
	}
}

void GuiManager::handleKeyDown(std::string key)
{
	// Pass it off to the MessageBox if it's visible
	if (GuiManager::_messageBox.visible) {
		GuiManager::_messageBox.onKeyDown(key);
		return;
	}

	// If there is a current focus, and an event handler, invoke it.
	if (GuiManager::_currentFocusedElement != nullptr) {
		GuiManager::_currentFocusedElement->onKeyDown(key);
	}
}

void GuiManager::handleKeyUp(std::string key)
{
	// Pass it off to the MessageBox if it's visible
	if (GuiManager::_messageBox.visible) {
		GuiManager::_messageBox.onKeyUp(key);
		return;
	}

	// If there is a current focus, and an event handler, invoke it.
	if (GuiManager::_currentFocusedElement != nullptr) {
		GuiManager::_currentFocusedElement->onKeyUp(key);
	}
}

void GuiManager::draw()
{
	auto scene = GuiManager::getCurrentSceneUIElements();

	// Go through every UI element in the scene.
	for (unsigned int i = 0; i < scene->size(); i++) {
		UIElement* sceneObject = scene->at(i);

		// If the scene object is visible, then draw it.
		if (sceneObject->visible) {
			sceneObject->draw();
		}
	}

	// Draw the MessagBox if it's visible.
	if (GuiManager::_messageBox.visible) {
		GuiManager::_messageBox.draw();
	}
}

void GuiManager::convertCoords(int* x, int* y)
{
	// Apply the ratio conversion.
	*x = (int)((DRAW_WIDTH / (float)GuiManager::WindowWidth) * *x);
	*y = (int)((DRAW_HEIGHT / (float)GuiManager::WindowHeight) * *y);
}

std::vector<UIElement*>* GuiManager::getCurrentSceneUIElements()
{
	return &GuiManager::_uiElements[(int)Game::getState()];
}

UIElement* GuiManager::getUIElementByName(std::string name)
{
	auto scene = GuiManager::getCurrentSceneUIElements();

	for (unsigned int i = 0; i < scene->size(); i++) {
		UIElement* element = scene->at(i)->getElementByName(name);
		if (element != nullptr) {
			return element;
		}
	}

	return nullptr;
}

int GuiManager::getMouseX()
{
	return GuiManager::_mouseX;
}

int GuiManager::getMouseY()
{
	return GuiManager::_mouseY;
}

void GuiManager::showMsgBox(std::string message)
{
	GuiManager::_messageBox.addMessage(message);
}

void GuiManager::popMsgBox()
{
	GuiManager::_messageBox.popMessage();
}