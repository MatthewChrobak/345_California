#pragma once
#include "FileSystem.h"
#include <map>
#include <SFML\Graphics\Texture.hpp>

namespace SFML {
	class SurfaceManager
	{
	public:
		SurfaceManager();
		~SurfaceManager();

	protected:
		sf::Texture* _getSurface(std::string name);
	
	private:
		std::map<std::string, sf::Texture*>* _surfaces;
		void _loadTextures();
	};
}