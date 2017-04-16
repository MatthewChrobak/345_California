#include "MainMenuCheckboxes.h"

DefaultMapBox::DefaultMapBox(UIElement* parent) : UICheckbox(parent, CHK_DEFAULT_MAP)
{
	this->setSurfaceName("ui/defaultmap_unchecked.png");
	this->checkedSurfaceName = "ui/defaultmap_checked.png";
	this->setWidth(200);
	this->setHeight(50);
	this->setTop(DRAW_HEIGHT / 2 + 100);
	this->setLeft(DRAW_WIDTH - this->getWidth());
}