#include "Textboxes.h"
#include "GuiManager.h"

SaveNameTextbox::SaveNameTextbox() : UITextbox(TXT_SAVE_NAME)
{
	this->surfaceName = "ui\\lighttextbox.png";
	this->width = DRAW_WIDTH / 2;
	this->left = this->width / 2;
	this->fontSize = 24;

	this->height = 50;
	this->top = DRAW_HEIGHT / 2 + 100;
}