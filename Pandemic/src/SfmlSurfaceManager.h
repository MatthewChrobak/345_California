/*!
	Author: Matthew Chrobak
	Contributors:

	Purpose: Identifies and loads all image files in a given directory, retrivable by name.
*/
#pragma once
#include <map>
#include <SFML\Graphics\Texture.hpp>

namespace SFML
{
	class SfmlSurfaceManager
	{
	public:
		SfmlSurfaceManager(std::string path);
		~SfmlSurfaceManager();

	protected:
		sf::Texture* _getSurface(std::string name);

	private:
		std::map<std::string, sf::Texture*>* _surfaces;
		void _loadTexturesInPath(std::string path);
	};
}