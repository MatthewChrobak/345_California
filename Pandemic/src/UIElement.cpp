#include "UIElement.h"
#include "SurfaceContext.h"
#include "GraphicsManager.h"


UIElement::UIElement(std::string name)
{
	this->_elementName = name;
}


UIElement::~UIElement()
{
}

bool UIElement::onMouseDown(std::string button, int x, int y)
{
	return true;
}

bool UIElement::onMouseUp(std::string button, int x, int y)
{
	return true;
}

void UIElement::onMouseMove(int x, int y)
{
}

bool UIElement::onKeyDown(std::string key)
{
	return true;
}

bool UIElement::onKeyUp(std::string key)
{
	return true;
}

UIElement* UIElement::getElementByName(std::string name)
{
	// Only return the element if we're the one it wants.
	if (this->_elementName == name) {
		return this;
	}

	return nullptr;
}

void UIElement::draw()
{
	// Make sure there's a surface to render.
	if (this->surfaceName.length() != 0) {
		SurfaceContext ctx;
		ctx.setPosition(this->left, this->top);
		ctx.setRenderSize(this->width, this->height);
		GraphicsManager::getInstance().renderSurface(this->surfaceName, ctx);
	}
}

void UIElement::resetFocus()
{
	this->hasFocus = false;
}

void UIElement::giveFocus()
{
	this->hasFocus = true;
}

void UIElement::resetHover()
{
	this->hasHover = false;
}

void UIElement::giveHover()
{
	this->hasHover = true;
}