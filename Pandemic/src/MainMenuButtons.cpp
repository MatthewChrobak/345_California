#include "MainMenuButtons.h"
#include "Game.h"
#include "UITextbox.h"

PlayGameButton::PlayGameButton(UIElement* parent) : UIButton(parent, CMD_PLAY_GAME_BUTTON)
{
	this->setWidth(DRAW_WIDTH / 2);
	this->setHeight(50);
	this->setCaption("play game");
	this->getOutline().setColor(0, 0, 0);
	this->getOutline().setThickness(2);
	this->setLeft(this->getWidth() - this->getWidth() / 2);
	this->setTop(DRAW_HEIGHT / 2 + 150);
	this->setFontSize(48);
}

bool PlayGameButton::onMouseDown(std::string button, int x, int y)
{
	auto element = this->baseParent->getElementByName(TXT_SAVE_NAME);
#ifdef DEBUG
	assert(element != nullptr);
	assert(element->getObjectType() == UI_TYPE_TEXTBOX);
#endif
	// Get the name of the game.
	std::string text = ((UITextbox*)element)->getText();

	// Make sure the name is valid.
	if (text.size() > 0)
	{
		Game::loadOrCreate(text);
	}
	return true;
}
