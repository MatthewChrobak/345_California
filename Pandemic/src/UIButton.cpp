#include "UIButton.h"
#include "GraphicsManager.h"
#include "GuiManager.h"
#include <iostream>


UIButton::UIButton(std::string elementName) : UIElement(elementName)
{
	this->horizontalCenter = true;
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
		ctx.position = new Vector2D(this->left, this->top);
		ctx.size = new Vector2D(this->width, this->height);
		GraphicsManager::renderSurface(this->hoverSurfaceName, ctx);
	}
	else {
		UIElement::draw();
	}

	// Position the text in the center.
	this->position = new Vector2D(this->left + (this->width / 2),
		this->top + (this->height - this->fontSize) / 2);

	GraphicsManager::renderText(this->caption, *this);
}

std::string UIButton::getObjectType()
{
	return UI_TYPE_BUTTON;
}