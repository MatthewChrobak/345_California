#include "MainMenuFrames.h"
#include "MainMenuButtons.h"
#include "MainMenuTextboxes.h"
#include "MainMenuCheckboxes.h"
#include "UIMessageBox.h"

MainMenuFrame::MainMenuFrame() : UIFrame(this, FRM_MAIN_MENU)
{
	this->surfaceName = "ui/mainmenu.png";
	this->width = FRM_MAIN_MENU_WIDTH;
	this->height = FRM_MAIN_MENU_HEIGHT;

	this->_elements.push_back(new SaveNameTextbox(this));
	this->_elements.push_back(new PlayGameButton(this));
	this->_elements.push_back(new DefaultMapBox(this));
	this->_elements.push_back(new UIMessageBox(this));
	this->_elements.push_back(new UIMessageBoxAccept(this));
}