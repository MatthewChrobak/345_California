#pragma once
#include "SfmlSystem.h"
#include <assert.h>
using namespace SFML;

SfmlSystem::SfmlSystem(const char* title, unsigned int contextWidth, unsigned int contextHeight, unsigned int windowWidth, unsigned int windowHeight)
{
	this->setContextSize(contextWidth, contextHeight);
	this->createContext();
	this->setWindowTitle(title);
	this->setWindowSize(windowWidth, windowHeight);
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

void SfmlSystem::setWindowTitle(const char* title)
{
	if (this->_windowContext != nullptr) {
		this->_windowContext->setTitle(title);
	}
}

void SfmlSystem::renderSurface(const char* surfacename, SurfaceContext& ctx)
{
	sf::Texture* texture = this->_getSurface(surfacename);
#ifdef DEBUG
	assert(texture != nullptr);
#endif
	sf::Sprite sprite = sf::Sprite(*texture);

	// Set the color if the context specifies so.
	if (ctx.Color != nullptr) {
		sf::Color color = sf::Color(
			ctx.Color->R,
			ctx.Color->G,
			ctx.Color->B,
			ctx.Color->A
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

	// Draw it.
	this->_windowContext->draw(sprite);
}