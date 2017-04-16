#include "UIFrame.h"



UIFrame::UIFrame(UIElement* parent, std::string elementName) : UIElement(parent, elementName)
{
}


UIFrame::~UIFrame()
{
	for (unsigned int i = 0; i < this->_elements.size(); i++) {
		delete this->_elements.at(i);
		this->_elements.pop_back();
	}

	this->_currentFocusedElement = nullptr;
}

bool UIFrame::onMouseDown(std::string button, int x, int y)
{
	for (int i = (int)this->_elements.size() - 1; i >= 0; i--) {
		UIElement* element = this->_elements.at(i);

		if (element->getVisible()) {
			if (x >= element->getLeft() && x <= element->getLeft() + element->getWidth()) {
				if (y >= element->getTop() && y <= element->getTop() + element->getHeight()) {

					// If there's a previous focused element, take away its focus.
					if (this->_currentFocusedElement != nullptr) {
						this->_currentFocusedElement->resetFocus();
					}

					element->onMouseDown(button, x, y);
					element->giveFocus();
					this->_currentFocusedElement = element;
					return true;
				}
			}
		}
	}

	return false;
}

bool UIFrame::onMouseUp(std::string button, int x, int y)
{
	for (int i = (int)this->_elements.size() - 1; i >= 0; i--) {
		UIElement* element = this->_elements.at(i);

		if (element->getVisible()) {
			if (x >= element->getLeft() && x <= element->getLeft() + element->getWidth()) {
				if (y >= element->getTop() && y <= element->getTop() + element->getHeight()) {
					return element->onMouseUp(button, x, y);
					break;
				}
			}
		}
	}

	return false;
}

void UIFrame::onMouseMove(int x, int y)
{
	for (int i = (int)this->_elements.size() - 1; i >= 0; i--) {
		UIElement* element = this->_elements.at(i);

		if (element->getVisible()) {
			if (x >= element->getLeft() && x <= element->getLeft() + element->getWidth()) {
				if (y >= element->getTop() && y <= element->getTop() + element->getHeight()) {
					element->onMouseMove(x, y);
					break;
				}
			}
		}
	}
}

bool UIFrame::onKeyDown(std::string key)
{
	if (this->_currentFocusedElement != nullptr) {
		return this->_currentFocusedElement->onKeyDown(key);
	}

	return false;
}

bool UIFrame::onKeyUp(std::string key)
{
	if (this->_currentFocusedElement != nullptr) {
		return this->_currentFocusedElement->onKeyUp(key);
	}
	return false;	
}

std::string UIFrame::getObjectType()
{
	return UI_TYPE_FRAME;
}

void UIFrame::draw()
{
	UIElement::draw();

	// Draw every element contained in the frame.
	for (unsigned int i = 0; i < this->_elements.size(); i++) {
		if (this->_elements.at(i)->getVisible()) {
			this->_elements.at(i)->draw();
		}
	}
}

UIElement* UIFrame::getElementByName(std::string name)
{
	// Is this the element we're looked for?
	UIElement* element = UIElement::getElementByName(name);
	if (element != nullptr) {
		return this;
	}

	// Look in the children.
	for (unsigned int i = 0; i < this->_elements.size(); i++) {
		UIElement* element = this->_elements.at(i)->getElementByName(name);
		if (element != nullptr) {
			return element;
		}
	}

	return nullptr;
}
