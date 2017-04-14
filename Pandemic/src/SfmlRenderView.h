#pragma once
#include "RenderView.h"
#include "SfmlFontManager.h"
#include "SfmlSurfaceManager.h"
#include "SurfaceContext.h"
#include "TextContext.h"

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include <SFML\System.hpp>

class SfmlRenderView : public RenderView, public SfmlSurfaceManager, public SfmlFontManager
{
public:
	SfmlRenderView(Controller* controller, std::string title, unsigned int contextWidth, unsigned int contextHeight);

	virtual void clear();
	virtual void draw();
	virtual void display();

private:
	sf::RenderWindow* _windowContext;
	sf::Vector2u _originalWindowSize;

	std::string keycodeToString(sf::Keyboard::Key key, bool caps);
	std::string mousebuttonToString(sf::Mouse::Button button);

	void handleEvents();
	void renderSurface(std::string text, SurfaceContext& ctx);
	void renderText(std::string text, TextContext& ctx);
};