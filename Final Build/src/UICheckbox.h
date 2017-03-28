#pragma once
#include "UIElement.h"

class UICheckbox : public UIElement
{
public:
	UICheckbox(std::string name);
	bool isChecked();
	bool onMouseDown(std::string button, int x, int y);
	void draw();

	std::string getObjectType();

protected:
	std::string checkedSurfaceName;

private:
	bool _checked;
};

