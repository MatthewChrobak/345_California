#pragma once
#include "SfmlGraphicsSystem.h"
#include "Game.h"
#include "GuiManager.h"
#include "FileSystem.h"
#include "Paths.h"
#ifdef DEBUG
#include <assert.h>
#endif
using namespace SFML;

SfmlGraphicsSystem::SfmlGraphicsSystem(std::string title, unsigned int contextWidth, unsigned int contextHeight, unsigned int windowWidth, unsigned int windowHeight) 
	: SfmlSurfaceManager(FileSystem::getStartupPath() + GRAPHICS_PATH), SfmlFontManager(FileSystem::getStartupPath() + FONTS_PATH)
{
	this->setContextSize(contextWidth, contextHeight);
	this->createContext();
	this->setWindowTitle(title);
	this->setWindowSize(windowWidth, windowHeight);
}

SfmlGraphicsSystem::~SfmlGraphicsSystem()
{
	if (!this->isDestroyed()) {
		this->destroyContext();
	}

#ifdef DEBUG
	assert(this->_windowContext == nullptr);
#endif
}


void SfmlGraphicsSystem::createContext()
{
#ifdef DEBUG
	assert(this->_windowContext == nullptr);
#endif

	this->_windowContext = new sf::RenderWindow(
		sf::VideoMode(this->_contextSize.x, this->_contextSize.y), "New Window"
		);
}

void SfmlGraphicsSystem::destroyContext()
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

void SfmlGraphicsSystem::restartContext()
{
	this->destroyContext();
	this->createContext();
}

void SfmlGraphicsSystem::drawContext()
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

void SfmlGraphicsSystem::handleEvent(sf::Event e)
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
		}
		else if (e.mouseButton.button == sf::Mouse::Button::Right) {
			GuiManager::handleMouseDown(e.mouseButton.x, e.mouseButton.y, "right");
		}
		break;
	case sf::Event::MouseButtonReleased:
		if (e.mouseButton.button == sf::Mouse::Button::Left) {
			GuiManager::handleMouseUp(e.mouseButton.x, e.mouseButton.y, "left");
		}
		else if (e.mouseButton.button == sf::Mouse::Button::Right) {
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

void SfmlGraphicsSystem::centerWindow()
{
	int x = (sf::VideoMode::getDesktopMode().width / 2) - (this->_windowSize.x / 2);
	int y = (sf::VideoMode::getDesktopMode().height / 2) - (this->_windowSize.y / 2);
	this->_windowContext->setPosition(sf::Vector2i(x, y));
}

bool SfmlGraphicsSystem::isDestroyed() const
{
	return this->_windowContext == nullptr;
}



void SfmlGraphicsSystem::setWindowSize(unsigned int width, unsigned int height)
{
	this->_windowSize = sf::Vector2u(width, height);

	if (this->_windowContext != nullptr) {
		this->_windowContext->setSize(this->_windowSize);
		this->centerWindow();
	}
}

void SfmlGraphicsSystem::setContextSize(unsigned int width, unsigned int height)
{
	this->_contextSize = sf::Vector2u(width, height);
}

void SfmlGraphicsSystem::setWindowTitle(std::string title)
{
	if (this->_windowContext != nullptr) {
		this->_windowContext->setTitle(title);
	}
}

void SfmlGraphicsSystem::renderText(std::string text, TextContext& ctx)
{
	// Retrieve the font.
	sf::Font* font = this->_getFont(ctx.getFontName());

	// Create a new drawable object based on the text given.
	sf::Text renderText = sf::Text(text, *font, ctx.getFontSize());

	// Set the fill color if the context specifies so.
	if (ctx.getFontColor() != nullptr) {
		sf::Color color = sf::Color(
			(sf::Uint8)ctx.getFontColor()->getR(),
			(sf::Uint8)ctx.getFontColor()->getG(),
			(sf::Uint8)ctx.getFontColor()->getB(),
			(sf::Uint8)ctx.getFontColor()->getA()
			);
		renderText.setFillColor(color);
	}

	// Set the outline color if the context specifies so.
	if (ctx.getOutline().getColor() != nullptr) {
		sf::Color color = sf::Color(
			(sf::Uint8)ctx.getOutline().getColor()->getR(),
			(sf::Uint8)ctx.getOutline().getColor()->getG(),
			(sf::Uint8)ctx.getOutline().getColor()->getB(),
			(sf::Uint8)ctx.getOutline().getColor()->getA()
			);
		renderText.setOutlineColor(color);
		renderText.setOutlineThickness(ctx.getOutline().getThickness());
	}

	// Set the position if the context specifies.
	if (ctx.getPosition() != nullptr) {
		sf::Vector2f pos;

		// Treat the given position as a centerpoint, or as absolute.
		if (ctx.getHorizontalCenter()) {
			int textWidth = (int)(renderText.findCharacterPos(text.size() - 1).x - renderText.findCharacterPos(0).x);
			pos = sf::Vector2f(ctx.getPosition()->getX() - (textWidth) / 2.0f, (float)ctx.getPosition()->getY());
		}
		else {
			pos = sf::Vector2f((float)ctx.getPosition()->getX(), (float)ctx.getPosition()->getY());
		}

		renderText.setPosition(pos);
	}

	// Draw it.
	this->_windowContext->draw(renderText);
}

void SfmlGraphicsSystem::renderSurface(std::string surfacename, SurfaceContext& ctx)
{
	sf::Texture* texture = this->_getSurface(surfacename);
#ifdef DEBUG
	assert(texture != nullptr);
#endif
	sf::Sprite sprite = sf::Sprite(*texture);

	// Set the color if the context specifies so.
	if (ctx.getColor() != nullptr) {
		sf::Color color = sf::Color(
			(sf::Uint8)ctx.getColor()->getR(),
			(sf::Uint8)ctx.getColor()->getG(),
			(sf::Uint8)ctx.getColor()->getB(),
			(sf::Uint8)ctx.getColor()->getA()
			);
		sprite.setColor(color);
	}

	// Set the surface rect if the context specifies.
	if (ctx.getSurfaceRect() != nullptr) {
		sf::IntRect rect = sf::IntRect(
			ctx.getSurfaceRect()->getLeft(),
			ctx.getSurfaceRect()->getTop(),
			ctx.getSurfaceRect()->getWidth(),
			ctx.getSurfaceRect()->getHeight());
		sprite.setTextureRect(rect);
	}

	// Scale the surface if the context specifies.
	if (ctx.getRenderSize() != nullptr) {
		sf::Vector2f scale;
		// Either compare it to the full-size, or the rect-size.
		if (ctx.getSurfaceRect() != nullptr) {
			scale = sf::Vector2f(
				(float)ctx.getRenderSize()->getX() / ctx.getSurfaceRect()->getWidth(),
				(float)ctx.getRenderSize()->getY() / ctx.getSurfaceRect()->getHeight()
				);
		}
		else {
			scale = sf::Vector2f(
				(float)ctx.getRenderSize()->getX() / sprite.getTexture()->getSize().x,
				(float)ctx.getRenderSize()->getY() / sprite.getTexture()->getSize().y
				);
		}
		sprite.scale(scale);
	}

	// Set the position if the context specifies.
	if (ctx.getPosition() != nullptr) {
		sf::Vector2f pos = sf::Vector2f((float)ctx.getPosition()->getX(), (float)ctx.getPosition()->getY());
		sprite.setPosition(pos);
	}

	// Rotate it.
	sprite.rotate(ctx.getRotation());

	// Draw it.
	this->_windowContext->draw(sprite);
}

std::string SfmlGraphicsSystem::keycodeToString(sf::Keyboard::Key key, bool caps = false)
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
			return "/";
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
		}
		else {
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