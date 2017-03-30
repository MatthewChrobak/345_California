#include "UIButton.h"
#include "GraphicsManager.h"
#include "GuiManager.h"
#include <iostream>


UIButton::UIButton(std::string elementName) : UIElement(elementName)
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
	if (this->hoverSurfaceName.size() != 0 &&
		GuiManager::getMouseX() >= this->left && GuiManager::getMouseX() <= this->left + this->width &&
			GuiManager::getMouseY() >= this->top && GuiManager::getMouseY() <= this->top + this->height)
	{
		SurfaceContext ctx;
		ctx.setPosition(this->left, this->top);
		ctx.setRenderSize(this->width, this->height);
		GraphicsManager::renderSurface(this->hoverSurfaceName, ctx);
	}
	else {
		UIElement::draw();
	}

	// Position the text in the center.
	this->setPosition(this->left + (this->width / 2),
		this->top + (this->height - this->getFontSize()) / 2);

	GraphicsManager::renderText(this->caption, *this);
}

std::string UIButton::getObjectType()
{
	return UI_TYPE_BUTTON;
}