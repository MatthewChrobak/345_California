/*!
	Author: Matthew Chrobak
	Contributors:
	Purpose: Defines the SFML implementation of the Graphics System.
			 Handles all reqeusts for drawn-surfaces and text.
*/
#pragma once
#include "GraphicsSystem.h"
#include "SfmlFontManager.h"
#include "SfmlSurfaceManager.h"
#include "GameRenderer.h"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

namespace SFML
{
    class SfmlGraphicsSystem : public GraphicsSystem, private SfmlSurfaceManager, SfmlFontManager, GameRenderer
    {
    public:
        SfmlGraphicsSystem(std::string title, unsigned int contextWidth, unsigned int contextHeight, unsigned int windowWidth, unsigned int windowHeight);
        ~SfmlGraphicsSystem();

        void destroyContext();
        void restartContext();
        void drawContext();
        void renderSurface(std::string text, SurfaceContext& ctx);
        void renderText(std::string text, TextContext& ctx);

        void setContextSize(unsigned int width, unsigned int height);
        void setWindowSize(unsigned int width, unsigned int height);
        void setWindowTitle(std::string title);

        bool isDestroyed() const;

    private:
        sf::RenderWindow* _windowContext;
        sf::Vector2u _windowSize;
        sf::Vector2u _contextSize;

        void handleEvent(sf::Event e);
        void createContext();
        void centerWindow();

        std::string keycodeToString(sf::Keyboard::Key key, bool caps);
    };
}