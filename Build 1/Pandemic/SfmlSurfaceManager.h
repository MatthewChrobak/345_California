#pragma once
#include "FileSystem.h"
#include <map>
#include <SFML\Graphics\Texture.hpp>

namespace SFML {
	class SurfaceManager
	{
	private:
		std::map<std::string, sf::Texture*>* _surfaces;
		void _loadTextures();

	public:
		SurfaceManager();
		~SurfaceManager();

	protected:
		sf::Texture* _getSurface(std::string name);
	};
}