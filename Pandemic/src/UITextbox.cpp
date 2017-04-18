#include "UITextbox.h"
#include "GraphicsManager.h"
#include <ctime>


UITextbox::UITextbox(std::string elementName) : UIElement(elementName)
{
	this->tickCursor = std::clock();
}


UITextbox::~UITextbox()
{
}

std::string UITextbox::getObjectType()
{
	return UI_TYPE_TEXTBOX;
}

void UITextbox::draw()
{
	// Draw the background.
	UIElement::draw();

	std::string renderText = this->text;
	int timeDifference = std::clock() - this->tickCursor;

	// Figure out if we have the focus.
	if (this->hasFocus) {
		// Figure out if we render the cursor or not.
		if (timeDifference < CURSOR_TICK) {
			renderText += "|";
		}
		else if (timeDifference < 2 * CURSOR_TICK) {
			// Do nothing.
		}
		else {
			// Don't render it this time, and set the next time.
			this->tickCursor = std::clock();
		}
	}
	
	this->setPosition(this->left,
		this->top + (this->height - this->getFontSize()) / 2);
	GraphicsManager::getInstance().renderText(renderText, *this);
}

bool UITextbox::onKeyDown(std::string key)
{
	// Is the input a non-character?
	if (key.size() != 1) {

		if (key == "backspace") {
			// Can we even backspace?
			if (this->text.size() != 0) {
				this->text = this->text.substr(0, this->text.size() - 1);
				return true;
			}
		}

		// Exit out. This is not a character we should append.
		return true;
	}

	this->text += key;
	return true;
}