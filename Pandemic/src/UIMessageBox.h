#pragma once
#include "UIFrame.h"
#include "UIButton.h"
#include <queue>
#include <string>

class UIMessageBoxAccept : public UIButton
{
public:
	UIMessageBoxAccept(UIElement* parent);
	bool onMouseDown(std::string button, int x, int y);
};



class UIMessageBox : public UIFrame
{
public:
	UIMessageBox(UIElement* parent);
	bool onKeyDown(std::string key);

	void addMessage(std::string message);
	void popMessage();
	void draw();

private:
	std::queue<std::string> _messages;
};