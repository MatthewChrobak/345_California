#include "SfmlFontManager.h"
#include "FileSystem.h"
#ifdef DEBUG
#include <assert.h>
#endif
using namespace SFML;

SfmlFontManager::SfmlFontManager(std::string path)
{
    this->_fonts = new std::map<std::string, sf::Font*>();
    this->_loadFontsInPath(path);
}


SfmlFontManager::~SfmlFontManager()
{
    for (auto it = this->_fonts->begin(); it != this->_fonts->end(); it = this->_fonts->begin()) {
        this->_fonts->erase(it);
    }
    delete this->_fonts;
}

void SfmlFontManager::_loadFontsInPath(std::string path)
{
    std::vector<std::string> files = FileSystem::getFiles(path);

    // Go through all of the font files in the folder.
    for (unsigned int i = 0; i < files.size(); i++) {
        sf::Font* font = new sf::Font();
        font->loadFromFile(path + files.at(i));
        this->_fonts->insert(std::pair<std::string, sf::Font*>(files.at(i), font));
    }
}

sf::Font* SfmlFontManager::_getFont(std::string fontname)
{
#ifdef DEBUG
    assert(this->_fonts->count(fontname));
#endif
    return this->_fonts->at(fontname);
}