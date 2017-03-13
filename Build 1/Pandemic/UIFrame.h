#pragma once
#include "UIElement.h"
#include <vector>

class UIFrame : public UIElement
{
public:
	UIFrame(std::string elementName);
	~UIFrame();

	void onMouseDown(std::string button, int x, int y);
	void onMouseUp(std::string button, int x, int y);
	void onMouseMove(int x, int y);

	void onKeyDown(std::string key);
	void onKeyUp(std::string key);

	UIElement* getElementByName(std::string name);
	std::string getObjectType();
	void draw();

protected:
	std::vector<UIElement*> _elements;

private:
	UIElement* _currentFocusedElement = nullptr;
};