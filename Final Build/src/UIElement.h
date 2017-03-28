#pragma once
#include <string>
#include <functional>
#include <assert.h>
#include "UIDefinitions.h"

class UIElement
{
public:
	UIElement(std::string elementName);
	~UIElement();

	static const std::string GuiSurfacePath;

	std::string surfaceName = "";
	int width = 0;
	int height = 0;
	int top = 0;
	int left = 0;

	bool visible = true;

	virtual bool onMouseDown(std::string button, int x, int y);
	virtual bool onMouseUp(std::string button, int x, int y);
	virtual void onMouseMove(int x, int y);

	virtual bool onKeyDown(std::string key);
	virtual bool onKeyUp(std::string key);

	virtual UIElement* getElementByName(std::string name);
	virtual std::string getObjectType() = 0;
	virtual void draw();

	void giveFocus();
	void resetFocus();
	void giveHover();
	void resetHover();

protected:
	bool hasFocus = false;
	bool hasHover = false;

private:
	std::string _elementName;
};

