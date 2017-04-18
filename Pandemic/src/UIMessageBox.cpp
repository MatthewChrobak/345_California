#include "UIMessageBox.h"
#include "GuiManager.h"

UIMessageBox::UIMessageBox() : UIFrame(MSG_BOX)
{
    this->surfaceName = "ui/textbox.png";
    this->width = MSG_BOX_WIDTH;
    this->height = MSG_BOX_HEIGHT;
    this->visible = false;

    this->_elements.push_back(new UIMessageBoxAccept());
}

void UIMessageBox::draw()
{
    UIFrame::draw();

    // Draw the message if there is one.
    if (!this->_messages.empty()) {
        TextContext ctx;
        ctx.setFontSize(24);
        ctx.setHorizontalCenter(true);
        RGBA rbga(0,0,0);
        ctx.setFontColor(rbga);
        ctx.setPosition(this->width / 2, this->height / 2);
        GraphicsManager::renderText(this->_messages.front(), ctx);
    }
}


void UIMessageBox::addMessage(std::string message)
{
    // Add the message to the queue and make sure we're visible.
    this->_messages.push(message);
    this->visible = true;
}

void UIMessageBox::popMessage()
{
    // If we're not empty, pop a message.
    if (!this->_messages.empty()) {
        this->_messages.pop();
    }

    // If we're empty, make us invisible.
    if (this->_messages.empty()) {
        this->visible = false;
    }
}


UIMessageBoxAccept::UIMessageBoxAccept() : UIButton(CMD_MSG_BOX_ACCEPT)
{
    this->caption = "Okay";
    this->getOutline().setThickness(2);
    this->getOutline().setColor(0, 0, 0);
    this->setFontSize(36);
    this->setHorizontalCenter(true);

    this->width = 200;
    this->height = 50;
    this->left = MSG_BOX_WIDTH / 2 - this->width / 2;
    this->top = MSG_BOX_HEIGHT / 2 + this->height;
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