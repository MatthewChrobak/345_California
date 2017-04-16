#pragma once
#include "UIElement.h"
#include <vector>

class UIFrame : public UIElement
{
public:
	UIFrame(UIElement* parent, std::string elementName);
	~UIFrame();

	bool onMouseDown(std::string button, int x, int y);
	bool onMouseUp(std::string button, int x, int y);
	void onMouseMove(int x, int y);

	bool onKeyDown(std::string key);
	bool onKeyUp(std::string key);

	UIElement* getElementByName(std::string name);
	std::string getObjectType();
	void draw();

protected:
	std::vector<UIElement*> _elements;

private:
	UIElement* _currentFocusedElement = nullptr;
};