#include "SfmlRenderView.h"
#include "FileSystem.h"
#ifdef DEBUG
#include <assert.h>
#endif

#define GRAPHICS_PATH (FileSystem::getStartupPath() + "/graphics/")
#define FONTS_PATH (FileSystem::getStartupPath() + "/fonts/")


SfmlRenderView::SfmlRenderView(Controller* controller, std::string title, unsigned int contextWidth, unsigned int contextHeight)
	: SfmlSurfaceManager(GRAPHICS_PATH), SfmlFontManager(FONTS_PATH)
{
#ifdef DEBUG
	// Make sure the window context is null.
	assert(this->_windowContext == nullptr);
#endif

	// Set the original window size.
	this->_originalWindowSize = sf::Vector2u(contextWidth, contextHeight);

	// Create the context.
	this->_windowContext = new sf::RenderWindow(
		sf::VideoMode(contextWidth, contextHeight),
		title
	);

	this->controller = controller;
}

void SfmlRenderView::clear()
{
#ifdef DEBUG
	assert(this->_windowContext != nullptr);
#endif
	this->_windowContext->clear(sf::Color(75, 75, 75));
}

void SfmlRenderView::draw()
{
#ifdef DEBUG
	assert(this->_windowContext != nullptr);
#endif

	// Handle any input here.
	this->handleEvents();
}

void SfmlRenderView::display()
{
#ifdef DEBUG
	assert(this->_windowContext != nullptr);
#endif
	this->_windowContext->display();
}

void SfmlRenderView::handleEvents()
{
#ifdef DEBUG
	assert(this->_windowContext != nullptr);
#endif

	sf::Event event;
	while (this->_windowContext->pollEvent(event))
	{
		switch (event.type)
		{
			// Window Events
			case sf::Event::Closed:

				break;
			case sf::Event::Resized:

				break;


			// Mouse events
			case sf::Event::MouseButtonPressed:
				this->controller->handleMouseDown(event.mouseButton.x, event.mouseButton.y, this->mousebuttonToString(event.mouseButton.button));
				break;
			case sf::Event::MouseButtonReleased:
				this->controller->handleMouseUp(event.mouseButton.x, event.mouseButton.y, this->mousebuttonToString(event.mouseButton.button));
				break;
			case sf::Event::MouseMoved:
				this->controller->handleMouseMove(event.mouseButton.x, event.mouseButton.y);
				break;


			// Key Events
			case sf::Event::KeyPressed:
				this->controller->handleKeyDown(this->keycodeToString(event.key.code, false));
				break;
			case sf::Event::KeyReleased:
				this->controller->handleKeyDown(this->keycodeToString(event.key.code, false));
				break;
		}
	}
}

std::string SfmlRenderView::keycodeToString(sf::Keyboard::Key key, bool caps)
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

std::string SfmlRenderView::mousebuttonToString(sf::Mouse::Button button)
{
	switch (button)
	{
		case sf::Mouse::Button::Left:
			return "left";
		case sf::Mouse::Button::Right:
			return "right";
		default:
			return "Invalid mouse button handler";
	}
}

void SfmlRenderView::renderText(std::string text, TextContext& ctx)
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

void SfmlRenderView::renderSurface(std::string surfacename, SurfaceContext& ctx)
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