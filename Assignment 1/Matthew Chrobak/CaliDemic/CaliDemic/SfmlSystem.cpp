#pragma once
#include "SfmlSystem.h"
#include <assert.h>

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