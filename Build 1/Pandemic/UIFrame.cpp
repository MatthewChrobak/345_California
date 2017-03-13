#include "UIFrame.h"



UIFrame::UIFrame(std::string elementName) : UIElement(elementName)
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

void UIFrame::onMouseDown(std::string button, int x, int y)
{
	for (int i = (int)this->_elements.size() - 1; i >= 0; i--) {
		UIElement* element = this->_elements.at(i);

		if (element->visible) {
			if (x >= element->left && x <= element->left + element->width) {
				if (y >= element->top && y <= element->top + element->height) {

					// If there's a previous focused element, take away its focus.
					if (this->_currentFocusedElement != nullptr) {
						this->_currentFocusedElement->resetFocus();
					}

					element->onMouseDown(button, x, y);
					element->giveFocus();
					this->_currentFocusedElement = element;
					break;
				}
			}
		}
	}
}

void UIFrame::onMouseUp(std::string button, int x, int y)
{
	for (int i = (int)this->_elements.size() - 1; i >= 0; i--) {
		UIElement* element = this->_elements.at(i);

		if (element->visible) {
			if (x >= element->left && x <= element->left + element->width) {
				if (y >= element->top && y <= element->top + element->height) {
					element->onMouseUp(button, x, y);
					break;
				}
			}
		}
	}
}

void UIFrame::onMouseMove(int x, int y)
{
	for (int i = (int)this->_elements.size() - 1; i >= 0; i--) {
		UIElement* element = this->_elements.at(i);

		if (element->visible) {
			if (x >= element->left && x <= element->left + element->width) {
				if (y >= element->top && y <= element->top + element->height) {
					element->onMouseMove(x, y);
					break;
				}
			}
		}
	}
}

void UIFrame::onKeyDown(std::string key)
{
	if (this->_currentFocusedElement != nullptr) {
		this->_currentFocusedElement->onKeyDown(key);
	}
}

void UIFrame::onKeyUp(std::string key)
{
	if (this->_currentFocusedElement != nullptr) {
		this->_currentFocusedElement->onKeyUp(key);
	}
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
		if (this->_elements.at(i)->visible) {
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
