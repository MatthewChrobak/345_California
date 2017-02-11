#pragma once
#include "GraphicsSystem.h"
#include "SfmlSurfaceManager.h"
#include "GameRenderer.h"
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

namespace SFML
{
	class SfmlSystem : public GraphicsSystem, private SurfaceManager, GameRenderer
	{
	public:
		SfmlSystem(const char* title, unsigned int contextWidth, unsigned int contextHeight, unsigned int windowWidth, unsigned int windowHeight);
		~SfmlSystem();

		void SfmlSystem::destroyContext();
		void SfmlSystem::restartContext();
		void SfmlSystem::drawContext();
		void SfmlSystem::renderSurface(const char* surfacename, SurfaceContext& ctx);

		void SfmlSystem::setContextSize(unsigned int width, unsigned int height);
		void SfmlSystem::setWindowSize(unsigned int width, unsigned int height);
		void SfmlSystem::setWindowTitle(const char* title);

		bool SfmlSystem::isDestroyed();

	private:
		sf::RenderWindow* _windowContext;
		sf::Vector2u _windowSize;
		sf::Vector2u _contextSize;

		void SfmlSystem::createContext();
		void centerWindow();
	};
}

