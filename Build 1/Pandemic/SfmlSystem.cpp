#pragma once
#include "SfmlSystem.h"
#include <assert.h>
#include "Game.h"
#include "GuiManager.h"
using namespace SFML;

SfmlSystem::SfmlSystem(std::string title, unsigned int contextWidth, unsigned int contextHeight, unsigned int windowWidth, unsigned int windowHeight)
{
	this->setContextSize(contextWidth, contextHeight);
	this->createContext();
	this->setWindowTitle(title);
	this->setWindowSize(windowWidth, windowHeight);

	// TODO:	 Load fonts to a hash-table, similarly to how surfaces are loaded.
	//			 This will ensure multiple fonts can be loaded and referenced by name.

	// Load the font.
	this->_font.loadFromFile(FileSystem::getStartupPath() + "fonts\\default.ttf");
}

SfmlSystem::~SfmlSystem()
{
	if (!this->isDestroyed()) {
		this->destroyContext();
	}

#ifdef DEBUG
	assert(this->_windowContext == nullptr);
#endif
}


void SfmlSystem::createContext()
{
#ifdef DEBUG
	assert(this->_windowContext == nullptr);
#endif

	this->_windowContext = new sf::RenderWindow(
		sf::VideoMode(this->_contextSize.x, this->_contextSize.y), "New Window"
	);
}

void SfmlSystem::destroyContext()
{
#ifdef DEBUG
	assert(!this->isDestroyed());
#endif

	this->_windowContext->close();
	this->setContextSize(0, 0);
	this->setWindowSize(0, 0);

	if (this->_windowContext != nullptr) {
		delete this->_windowContext;
		this->_windowContext = nullptr;
	}
}

void SfmlSystem::restartContext()
{
	this->destroyContext();
	this->createContext();
}

void SfmlSystem::drawContext()
{
#ifdef DEBUG
	assert(this->_windowContext->isOpen());
#endif

	// Clear the contents of the backbuffer with a solid color.
	this->_windowContext->clear(sf::Color(75, 75, 75));

	// Handle every window event.
	sf::Event event;
	while (this->_windowContext->pollEvent(event)) 
	{
		this->handleEvent(event);
	}

	// Invoke the method which draws the game.
	this->drawGame();

	// Draw the user interface.
	GuiManager::draw();

	// Swap the buffers.
	this->_windowContext->display();
}

void SfmlSystem::handleEvent(sf::Event e)
{
	switch (e.type) {
		// Window Events
		case sf::Event::Closed:
			GuiManager::handleWindowClose();
			break;
		case sf::Event::Resized:
			GuiManager::handleWindowResize(e.size.width, e.size.height);
			break;


			// Mouse Events
		case sf::Event::MouseButtonPressed:
			if (e.mouseButton.button == sf::Mouse::Button::Left) {
				GuiManager::handleMouseDown(e.mouseButton.x, e.mouseButton.y, "left");
			} else if (e.mouseButton.button == sf::Mouse::Button::Right) {
				GuiManager::handleMouseDown(e.mouseButton.x, e.mouseButton.y, "right");
			}
			break;
		case sf::Event::MouseButtonReleased:
			if (e.mouseButton.button == sf::Mouse::Button::Left) {
				GuiManager::handleMouseUp(e.mouseButton.x, e.mouseButton.y, "left");
			} else if (e.mouseButton.button == sf::Mouse::Button::Right) {
				GuiManager::handleMouseUp(e.mouseButton.x, e.mouseButton.y, "right");
			}
			break;
		case sf::Event::MouseMoved:
			GuiManager::handleMouseMove(e.mouseMove.x, e.mouseMove.y);
			break;


			// Key Events
		case sf::Event::KeyPressed:
			GuiManager::handleKeyDown(this->keycodeToString(e.key.code, e.key.shift));
			break;
		case sf::Event::KeyReleased:
			GuiManager::handleKeyUp(this->keycodeToString(e.key.code, e.key.shift));
			break;
	}
}

void SfmlSystem::centerWindow()
{
	int x = (sf::VideoMode::getDesktopMode().width / 2) - (this->_windowSize.x / 2);
	int y = (sf::VideoMode::getDesktopMode().height / 2) - (this->_windowSize.y / 2);
	this->_windowContext->setPosition(sf::Vector2i(x, y));
}

bool SfmlSystem::isDestroyed() {
	return this->_windowContext == nullptr;
}



void SfmlSystem::setWindowSize(unsigned int width, unsigned int height)
{
	this->_windowSize = sf::Vector2u(width, height);

	if (this->_windowContext != nullptr) {
		this->_windowContext->setSize(this->_windowSize);
		this->centerWindow();
	}
}

void SfmlSystem::setContextSize(unsigned int width, unsigned int height)
{
	this->_contextSize = sf::Vector2u(width, height);
}

void SfmlSystem::setWindowTitle(std::string title)
{
	if (this->_windowContext != nullptr) {
		this->_windowContext->setTitle(title);
	}
}

void SfmlSystem::renderText(std::string text, TextContext& ctx)
{
	// Create a new drawable object based on the text given.
	sf::Text renderText = sf::Text(text, this->_font, ctx.fontSize);

	// Set the fill color if the context specifies so.
	if (ctx.fillColor != nullptr) {
		sf::Color color = sf::Color(
			(sf::Uint8)ctx.fillColor->r,
			(sf::Uint8)ctx.fillColor->g,
			(sf::Uint8)ctx.fillColor->b,
			(sf::Uint8)ctx.fillColor->a
			);
		renderText.setFillColor(color);
	}

	// Set the outline color if the context specifies so.
	if (ctx.outlineColor != nullptr) {
		sf::Color color = sf::Color(
			(sf::Uint8)ctx.outlineColor->r,
			(sf::Uint8)ctx.outlineColor->g,
			(sf::Uint8)ctx.outlineColor->b,
			(sf::Uint8)ctx.outlineColor->a
			);
		renderText.setOutlineColor(color);
		renderText.setOutlineThickness(ctx.outlineThickness);
	}

	// Set the position if the context specifies.
	if (ctx.position != nullptr) {
		sf::Vector2f pos;

		// Treat the given position as a centerpoint, or as absolute.
		if (ctx.horizontalCenter) {
			int textWidth = (int)(renderText.findCharacterPos(text.size() - 1).x - renderText.findCharacterPos(0).x);
			pos = sf::Vector2f(ctx.position->x - (textWidth) / 2.0f, (float)ctx.position->y);
		}
		else {
			pos = sf::Vector2f((float)ctx.position->x, (float)ctx.position->y);
		}

		renderText.setPosition(pos);
	}

	// Draw it.
	this->_windowContext->draw(renderText);
}

void SfmlSystem::renderSurface(std::string surfacename, SurfaceContext& ctx)
{
	sf::Texture* texture = this->_getSurface(surfacename);
#ifdef DEBUG
	assert(texture != nullptr);
#endif
	sf::Sprite sprite = sf::Sprite(*texture);

	// Set the color if the context specifies so.
	if (ctx.color != nullptr) {
		sf::Color color = sf::Color(
			(sf::Uint8)ctx.color->r,
			(sf::Uint8)ctx.color->g,
			(sf::Uint8)ctx.color->b,
			(sf::Uint8)ctx.color->a
			);
		sprite.setColor(color);
	}

	// Set the surface rect if the context specifies.
	if (ctx.surfaceRect != nullptr) {
		sf::IntRect rect = sf::IntRect(
			ctx.surfaceRect->left,
			ctx.surfaceRect->top,
			ctx.surfaceRect->width,
			ctx.surfaceRect->height);
		sprite.setTextureRect(rect);
	}

	// Scale the surface if the context specifies.
	if (ctx.size != nullptr) {
		sf::Vector2f scale;
		// Either compare it to the full-size, or the rect-size.
		if (ctx.surfaceRect != nullptr) {
			scale = sf::Vector2f(
				(float)ctx.size->x / ctx.surfaceRect->width,
				(float)ctx.size->y / ctx.surfaceRect->height
				);
		}
		else {
			scale = sf::Vector2f(
				(float)ctx.size->x / sprite.getTexture()->getSize().x,
				(float)ctx.size->y / sprite.getTexture()->getSize().y
				);
		}
		sprite.scale(scale);
	}

	// Set the position if the context specifies.
	if (ctx.position != nullptr) {
		sf::Vector2f pos = sf::Vector2f((float)ctx.position->x, (float)ctx.position->y);
		sprite.setPosition(pos);
	}

	// Rotate it.
	sprite.rotate(ctx.rotation);

	// Draw it.
	this->_windowContext->draw(sprite);
}

std::string SfmlSystem::keycodeToString(sf::Keyboard::Key key, bool caps = false)
{
	switch (key) {
		case sf::Keyboard::Key::Escape:
			return "escape";
		case sf::Keyboard::Key::Menu:
			return "menu";
		case sf::Keyboard::Key::Space:
			return " ";
		case sf::Keyboard::Key::Return:
			return "enter";
		case sf::Keyboard::Key::BackSpace:
			return "backspace";
		case sf::Keyboard::Key::Tab:
			return "tab";
		case sf::Keyboard::Key::Delete:
			return "delete";


		case sf::Keyboard::Key::LControl:
		case sf::Keyboard::Key::LShift:
		case sf::Keyboard::Key::LAlt:
		case sf::Keyboard::Key::LSystem:
		case sf::Keyboard::Key::RControl:
		case sf::Keyboard::Key::RShift:
		case sf::Keyboard::Key::RAlt:
		case sf::Keyboard::Key::RSystem:
		case sf::Keyboard::Key::PageUp:
		case sf::Keyboard::Key::PageDown:
		case sf::Keyboard::Key::End:
		case sf::Keyboard::Key::Home:
		case sf::Keyboard::Key::Insert:
		case sf::Keyboard::Key::Pause:
			return "";

		case sf::Keyboard::Key::LBracket:
			if (caps) {
				return "{";
			}
			else {
				return "[";
			}
			
		case sf::Keyboard::Key::RBracket:
			if (caps) {
				return "}";
			}
			else {
				return "]";
			}


		case sf::Keyboard::Key::SemiColon:
			if (caps) {
				return ":";
			}
			else {
				return ";";
			}
		case sf::Keyboard::Key::Comma:
			if (caps) {
				return "<";
			}
			else {
				return ",";
			}
		case sf::Keyboard::Key::Period:
			if (caps) {
				return ">";
			}
			else {
				return ".";
			}
		case sf::Keyboard::Key::Quote:
			if (caps) {
				return "\"";
			}
			else {
				return "'";
			}
		case sf::Keyboard::Key::Slash:
			if (caps) {
				return "?";
			}
			else {
				return "/";
			}
		case sf::Keyboard::Key::BackSlash:
			if (caps) {
				return "|";
			}
			else {
				return "\\";
			}
		case sf::Keyboard::Key::Tilde:
			if (caps) {
				return "~";
			}
			else {
				return "`";
			}
		case sf::Keyboard::Key::Equal:
			if (caps) {
				return "+";
			}
			else {
				return "=";
			}
		case sf::Keyboard::Key::Dash:
			if (caps) {
				return "_";
			}
			else {
				return "-";
			}


		case sf::Keyboard::Key::Add:
			return "+";
		case sf::Keyboard::Key::Subtract:
			return "-";
		case sf::Keyboard::Key::Multiply:
			return "*";
		case sf::Keyboard::Key::Divide:
			return "/";

		case sf::Keyboard::Key::Up:
			return "up";
		case sf::Keyboard::Key::Down:
			return "down";
		case sf::Keyboard::Key::Left:
			return "left";
		case sf::Keyboard::Key::Right:
			return "right";

	}

	int integerKeyValue = (int)key;

	// Is it a character?
	if (integerKeyValue >= sf::Keyboard::Key::A && integerKeyValue <= sf::Keyboard::Key::Z)
	{
		if (caps) {
			return std::string(1, (char)(integerKeyValue + 65));
		}
		else {
			return std::string(1, (char)(integerKeyValue + 97));
		}
	}

	// Is it a digit?
	if (integerKeyValue >= sf::Keyboard::Num0 && integerKeyValue <= sf::Keyboard::Num9) {
		if (caps) {
			switch (key) {
			case sf::Keyboard::Key::Num0:
				return ")";
			case sf::Keyboard::Key::Num1:
				return "!";
			case sf::Keyboard::Key::Num2:
				return "@";
			case sf::Keyboard::Key::Num3:
				return "#";
			case sf::Keyboard::Key::Num4:
				return "$";
			case sf::Keyboard::Key::Num5:
				return "%";
			case sf::Keyboard::Key::Num6:
				return "^";
			case sf::Keyboard::Key::Num7:
				return "&";
			case sf::Keyboard::Key::Num8:
				return "*";
			case sf::Keyboard::Key::Num9:
				return "(";
			}
		} else {
			// Zero is a special case.
			if (key == sf::Keyboard::Key::Num0) {
				return "0";
			}
			return std::string(1, (char)(integerKeyValue + 22));
		}
	}

	// The key has no handler.
	return "Handler does not exist";
}