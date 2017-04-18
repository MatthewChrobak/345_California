/*!
	Author: Matthew Chrobak
	Contributors:
	Purpose: Identifies and loads all font files in a given directory, retrivable by name.
*/
#pragma once
#include <map>
#include <SFML/Graphics/Font.hpp>

namespace SFML
{
    class SfmlFontManager
    {
    public:
        SfmlFontManager(std::string path);
        ~SfmlFontManager();

    protected:
        sf::Font* _getFont(std::string name);

    private:
        std::map<std::string, sf::Font*>* _fonts;
        void _loadFontsInPath(std::string path);
    };
}