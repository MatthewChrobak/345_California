//#pragma once
//#include <vector>
//#include <string>
//#include "Game.h"
//#include "UIElement.h"
//#include "UIMessageBox.h"
//
//class GuiManager
//{
//public:
//	static void initialize();
//	static void destroy();
//
//	static void handleMouseDown(int x, int y, std::string button);
//	static void handleMouseUp(int x, int y, std::string button);
//	static void handleMouseMove(int x, int y);
//	static void handleKeyDown(std::string key);
//	static void handleKeyUp(std::string key);
//	static void handleWindowResize(int x, int y);
//	static void handleWindowClose();
//
//	static int WindowWidth;
//	static int WindowHeight;
//
//	static void draw();
//	static UIElement* getUIElementByName(std::string name);
//
//	static int getMouseX();
//	static int getMouseY();
//
//
//	static void showMsgBox(std::string message);
//	static void popMsgBox();
//
//private:
//	static void convertCoords(int* x, int* y);
//	static int _mouseX;
//	static int _mouseY;
//
//	static std::vector<UIElement*>* getCurrentSceneUIElements();
//	static std::vector<UIElement*> _uiElements[GameState::GameState_Length];
//	static UIElement* _currentFocusedElement;
//
//	static UIMessageBox _messageBox;
//};