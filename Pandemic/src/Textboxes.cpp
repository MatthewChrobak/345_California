#include "Textboxes.h"
#include "GraphicsManager.h"

SaveNameTextbox::SaveNameTextbox() : UITextbox(TXT_SAVE_NAME)
{
	this->surfaceName = "ui\\lightbox.png";
	this->width = DRAW_WIDTH / 2;
	this->left = this->width / 2;
	this->setFontSize(24);

	this->height = 50;
	this->top = DRAW_HEIGHT / 2 + 100;
}