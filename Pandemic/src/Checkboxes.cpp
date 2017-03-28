#include "Checkboxes.h"

DefaultMapBox::DefaultMapBox() : UICheckbox(CHK_DEFAULT_MAP)
{
	this->surfaceName = "ui\\defaultmap_unchecked.png";
	this->checkedSurfaceName = "ui\\defaultmap_checked.png";
	this->width = 200;
	this->height = 50;
	this->top = DRAW_HEIGHT / 2 + 100;
	this->left = DRAW_WIDTH - this->width;
}