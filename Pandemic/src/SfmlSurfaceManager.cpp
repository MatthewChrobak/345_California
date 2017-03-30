#include "SfmlSurfaceManager.h"
#include "FileSystem.h"
#ifdef DEBUG
#include <assert.h>
#endif
using namespace SFML;

SfmlSurfaceManager::SfmlSurfaceManager(std::string path)
{
	this->_surfaces = new std::map<std::string, sf::Texture*>();
	this->_loadTexturesInPath(path);
}

SfmlSurfaceManager::~SfmlSurfaceManager()
{
	for (auto it = this->_surfaces->begin(); it != this->_surfaces->end(); it = this->_surfaces->begin()) {
		this->_surfaces->erase(it);
	}
	delete this->_surfaces;
}


void SfmlSurfaceManager::_loadTexturesInPath(std::string path)
{
	std::vector<std::string> directories = FileSystem::getDirectories(path + "*");

	// Go through all the directories in the graphics folder.
	for (unsigned int i = 0; i < directories.size(); i++) {
		std::string subDirectory = directories.at(i) + "\\";

		// Get all the files in the sub-directory.
		std::vector<std::string> files = FileSystem::getFiles(path + subDirectory + "*");

		for (unsigned int j = 0; j < files.size(); j++) {
			std::string relativeFilepath = subDirectory + files.at(j);
			std::string fullFilepath = path + relativeFilepath;

			// Load the texture and add it to the collection.
			sf::Texture* texture = new sf::Texture();
			texture->loadFromFile(fullFilepath);
			this->_surfaces->insert(std::pair<std::string, sf::Texture*>(relativeFilepath, texture));
		}
	}
}

sf::Texture* SfmlSurfaceManager::_getSurface(std::string surfacename)
{
#ifdef DEBUG
	assert(this->_surfaces->count(surfacename));
#endif
	return this->_surfaces->at(surfacename);
}