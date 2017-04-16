#pragma once
#include "UIElement.h"
#include "TextContext.h"
#define CURSOR_TICK 500

class UITextbox : public UIElement, public TextContext
{
public:
	UITextbox(UIElement* parent, std::string elementName);
	~UITextbox();

	void setText(std::string value);
	std::string getText();

	std::string getObjectType();
	void draw();
	bool onKeyDown(std::string key);

private:
	int tickCursor;
	std::string _text;
};

