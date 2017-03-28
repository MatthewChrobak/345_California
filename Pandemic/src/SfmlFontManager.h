#pragma once
#include "FileSystem.h"
#include <map>
#include <SFML\Graphics\Font.hpp>

namespace SFML
{
	class FontManager
	{
	public:
		FontManager();
		~FontManager();

	protected:
		sf::Font* _getFont(std::string name);

	private:
		std::map<std::string, sf::Font*>* _fonts;
		void _loadFonts();
	};

}
