#include "UIMessageBox.h"
#include "GuiManager.h"

UIMessageBox::UIMessageBox(UIElement* parent) : UIFrame(parent, MSG_BOX)
{
	this->setSurfaceName("ui\\textbox.png");
	this->setWidth(MSG_BOX_WIDTH);
	this->setHeight(MSG_BOX_HEIGHT);
	this->setVisible(false);

	this->_elements.push_back(new UIMessageBoxAccept(parent));
}

void UIMessageBox::draw()
{
	UIFrame::draw();

	// Draw the message if there is one.
	if (!this->_messages.empty()) {
		TextContext ctx;
		ctx.setFontSize(24);
		ctx.setHorizontalCenter(true);
		ctx.setFontColor(RGBA(0, 0, 0));
		ctx.setPosition(this->getWidth() / 2, this->getHeight() / 2);
		GraphicsManager::renderText(this->_messages.front(), ctx);
	}
}


void UIMessageBox::addMessage(std::string message)
{
	// Add the message to the queue and make sure we're visible.
	this->_messages.push(message);
	this->setVisible(true);
}

void UIMessageBox::popMessage()
{
	// If we're not empty, pop a message.
	if (!this->_messages.empty()) {
		this->_messages.pop();
	}

	// If we're empty, make us invisible.
	if (this->_messages.empty()) {
		this->setVisible(false);
	}
}


UIMessageBoxAccept::UIMessageBoxAccept(UIElement* parent) : UIButton(parent, CMD_MSG_BOX_ACCEPT)
{
	this->setCaption("Okay");
	this->getOutline().setThickness(2);
	this->getOutline().setColor(0, 0, 0);
	this->setFontSize(36);
	this->setHorizontalCenter(true);

	this->setWidth(200);
	this->setHeight(50);
	this->setLeft(MSG_BOX_WIDTH / 2 - this->getWidth() / 2);
	this->setTop(MSG_BOX_HEIGHT / 2 + this->getHeight());
}

bool UIMessageBoxAccept::onMouseDown(std::string button, int x, int y)
{
	GuiManager::popMsgBox();
	return true;
}

bool UIMessageBox::onKeyDown(std::string key)
{
	if (key == "enter") {
		GuiManager::popMsgBox();
	}
	return true;
}