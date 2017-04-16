#include "UIElement.h"
#include "SurfaceContext.h"

#include "UIMessageBox.h"


UIElement::UIElement(UIElement* parent, std::string name)
{
	this->_elementName = name;
	this->baseParent = parent;
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
	if (this->_surfaceName.length() != 0) {
		SurfaceContext ctx;
		ctx.setPosition(this->getLeft(), this->getTop());
		ctx.setRenderSize(this->getWidth(), this->getHeight());
		GraphicsManager::renderSurface(this->_surfaceName, ctx);
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



void UIElement::setSurfaceName(std::string name)
{
	this->_surfaceName = name;
}

std::string UIElement::getSurfaceName()
{
	return this->_surfaceName;
}


void UIElement::setWidth(int width)
{
	this->_width = width;
}

int UIElement::getWidth()
{
	return this->_width;
}


void UIElement::setHeight(int height)
{
	this->_height = height;
}

int UIElement::getHeight()
{
	return this->_height;
}

void UIElement::setTop(int top)
{
	this->_top = top;
}
int UIElement::getTop()
{
	return this->_top;
}

void UIElement::setLeft(int left)
{
	this->_left = left;
}
int UIElement::getLeft()
{
	return this->_left;
}

void UIElement::setVisible(bool visible)
{
	this->_visible = visible;
}

bool UIElement::getVisible()
{
	return this->_visible;
}

void UIElement::showMsgBox(std::string message)
{
	((UIMessageBox*)this->baseParent->getElementByName(MSG_BOX))->addMessage(message);
}