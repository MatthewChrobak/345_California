#pragma once
#include "UIElement.h"
#include "TextContext.h"

class UIButton : public UIElement, public TextContext
{
public:
	UIButton(std::string elementName);
	~UIButton();

	void draw();
	std::string getObjectType();

protected:
	std::string hoverSurfaceName;
	std::string caption;
};

