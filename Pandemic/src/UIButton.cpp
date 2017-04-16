#include "UIButton.h"

#include "GuiManager.h"
#include <iostream>


UIButton::UIButton(UIElement* parent, std::string elementName) : UIElement(parent, elementName)
{
	this->setHorizontalCenter(true);
}

UIButton::~UIButton()
{
	TextContext::~TextContext();
}

void UIButton::draw()
{
	// Draw the hover background if we can.
	if (this->getHoverSurfaceName().size() != 0 &&
		GuiManager::getMouseX() >= this->getLeft() && GuiManager::getMouseX() <= this->getLeft() + this->getWidth() &&
			GuiManager::getMouseY() >= this->getTop() && GuiManager::getMouseY() <= this->getTop() + this->getHeight())
	{
		SurfaceContext ctx;
		ctx.setPosition(this->getLeft(), this->getTop());
		ctx.setRenderSize(this->getWidth(), this->getHeight());
		GraphicsManager::renderSurface(this->getHoverSurfaceName(), ctx);
	}
	else {
		UIElement::draw();
	}

	// Position the text in the center.
	this->setPosition(this->getLeft() + (this->getWidth() / 2),
		this->getTop() + (this->getHeight() - this->getFontSize()) / 2);

	GraphicsManager::renderText(this->getCaption(), *this);
}

std::string UIButton::getObjectType()
{
	return UI_TYPE_BUTTON;
}

void UIButton::setCaption(std::string caption)
{
	this->_caption = caption;
}

std::string UIButton::getCaption()
{
	return this->_caption;
}

void UIButton::setHoverSurfaceName(std::string surfacename)
{
	this->_hoverSurfaceName = surfacename;
}

std::string UIButton::getHoverSurfaceName()
{
	return this->_hoverSurfaceName;
}