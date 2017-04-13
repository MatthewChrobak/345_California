#pragma once
#include "UIElement.h"
#include "TextContext.h"
#define CURSOR_TICK 500

class UITextbox : public UIElement, public TextContext
{
public:
	UITextbox(std::string elementName);
	~UITextbox();

	std::string text;

	std::string getObjectType();
	void draw();
	bool onKeyDown(std::string key);

private:
	int tickCursor;
};