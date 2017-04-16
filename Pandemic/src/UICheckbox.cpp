#include "UICheckbox.h"

UICheckbox::UICheckbox(UIElement* parent, std::string name) : UIElement(parent, name)
{

}

bool UICheckbox::onMouseDown(std::string button, int x, int y)
{
	this->_checked = !this->_checked;
	return true;
}

bool UICheckbox::isChecked()
{
	return this->_checked;
}

void UICheckbox::draw()
{
	// If we're checked, render the checked surface.
	// Otherwise, render the base surface.
	if (this->isChecked()) {
		// Make sure there's a surface to render.
		if (this->checkedSurfaceName.length() != 0) {
			SurfaceContext ctx;
			ctx.setPosition(this->getLeft(), this->getTop());
			ctx.setRenderSize(this->getWidth(), this->getHeight());
			GraphicsManager::renderSurface(this->checkedSurfaceName, ctx);
			return;
		}
	}

	UIElement::draw();
}

std::string UICheckbox::getObjectType()
{
	return UI_TYPE_CHECKBOX;
}