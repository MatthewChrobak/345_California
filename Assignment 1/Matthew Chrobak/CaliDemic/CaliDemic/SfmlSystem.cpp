#pragma once
#include "SfmlSystem.h"
#include <assert.h>
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
		if (event.type == sf::Event::Closed) {
			this->destroyContext();
			return;
		}
	}

	// Invoke the method which draws the game.
	this->drawGame();

	// Swap the buffers.
	this->_windowContext->display();
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
	sf::Text renderText = sf::Text(text, this->_font, ctx.FontSize);

	// Set the fill color if the context specifies so.
	if (ctx.FillColor != nullptr) {
		sf::Color color = sf::Color(
			(sf::Uint8)ctx.FillColor->R,
			(sf::Uint8)ctx.FillColor->G,
			(sf::Uint8)ctx.FillColor->B,
			(sf::Uint8)ctx.FillColor->A
			);
		renderText.setFillColor(color);
	}

	// Set the outline color if the context specifies so.
	if (ctx.OutlineColor != nullptr) {
		sf::Color color = sf::Color(
			(sf::Uint8)ctx.OutlineColor->R,
			(sf::Uint8)ctx.OutlineColor->G,
			(sf::Uint8)ctx.OutlineColor->B,
			(sf::Uint8)ctx.OutlineColor->A
			);
		renderText.setOutlineColor(color);
		renderText.setOutlineThickness(ctx.OutlineThickness);
	}

	// Set the position if the context specifies.
	if (ctx.Position != nullptr) {
		sf::Vector2f pos;

		// Treat the given position as a centerpoint, or as absolute.
		if (ctx.HorizontalCenter) {
			int textWidth = renderText.findCharacterPos(text.size() - 1).x - renderText.findCharacterPos(0).x;
			pos = sf::Vector2f(ctx.Position->X - (textWidth) / 2, ctx.Position->Y);
		}
		else {
			pos = sf::Vector2f(ctx.Position->X, ctx.Position->Y);
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
	if (ctx.Color != nullptr) {
		sf::Color color = sf::Color(
			(sf::Uint8)ctx.Color->R,
			(sf::Uint8)ctx.Color->G,
			(sf::Uint8)ctx.Color->B,
			(sf::Uint8)ctx.Color->A
			);
		sprite.setColor(color);
	}

	// Set the surface rect if the context specifies.
	if (ctx.SurfaceRect != nullptr) {
		sf::IntRect rect = sf::IntRect(
			ctx.SurfaceRect->Left,
			ctx.SurfaceRect->Top,
			ctx.SurfaceRect->Width,
			ctx.SurfaceRect->Height);
		sprite.setTextureRect(rect);
	}

	// Scale the surface if the context specifies.
	if (ctx.Size != nullptr) {
		sf::Vector2f scale;
		// Either compare it to the full-size, or the rect-size.
		if (ctx.SurfaceRect != nullptr) {
			scale = sf::Vector2f(
				(float)ctx.Size->X / ctx.SurfaceRect->Width,
				(float)ctx.Size->Y / ctx.SurfaceRect->Height
				);
		}
		else {
			scale = sf::Vector2f(
				(float)ctx.Size->X / sprite.getTexture()->getSize().x,
				(float)ctx.Size->Y / sprite.getTexture()->getSize().y
				);
		}
		sprite.scale(scale);
	}

	// Set the position if the context specifies.
	if (ctx.Position != nullptr) {
		sf::Vector2f pos = sf::Vector2f(ctx.Position->X, ctx.Position->Y);
		sprite.setPosition(pos);
	}

	// Rotate it.
	sprite.rotate(ctx.Rotation);

	// Draw it.
	this->_windowContext->draw(sprite);
}