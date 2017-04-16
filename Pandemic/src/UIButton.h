#pragma once
#include "UIElement.h"
#include "TextContext.h"

class UIButton : public UIElement, public TextContext
{
public:
	UIButton(UIElement* parent, std::string elementName);
	~UIButton();

	void setCaption(std::string caption);
	std::string getCaption();

	void setHoverSurfaceName(std::string hoversurface);
	std::string getHoverSurfaceName();

	void draw();
	std::string getObjectType();

private:
	std::string _hoverSurfaceName;
	std::string _caption;
};

