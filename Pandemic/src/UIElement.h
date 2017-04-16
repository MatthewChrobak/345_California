#pragma once
#include <string>
#include <functional>
#include <assert.h>
#include "UIDefinitions.h"
#include "Observable.h"

class UIElement : public Observable
{
public:
	UIElement(UIElement* parent, std::string elementName);
	~UIElement();

	void setSurfaceName(std::string name);
	std::string getSurfaceName();

	void setWidth(int width);
	int getWidth();

	void setHeight(int height);
	int getHeight();

	void setTop(int top);
	int getTop();

	void setLeft(int left);
	int getLeft();

	void setVisible(bool visible);
	bool getVisible();

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

	void showMsgBox(std::string message);

protected:
	bool hasFocus = false;
	bool hasHover = false;
	UIElement* baseParent;

private:
	std::string _elementName;

	std::string _surfaceName = "";
	int _width = 0;
	int _height = 0;
	int _top = 0;
	int _left = 0;

	bool _visible = true;
};