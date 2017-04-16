#include "MainMenuTextboxes.h"

SaveNameTextbox::SaveNameTextbox(UIElement* parent) : UITextbox(parent, TXT_SAVE_NAME)
{
	this->setSurfaceName("ui/lightbox.png");
	this->setWidth(DRAW_WIDTH / 2);
	this->setLeft(this->getWidth() / 2);
	this->setFontSize(24);

	this->setHeight(50);
	this->setTop( DRAW_HEIGHT / 2 + 100);
}