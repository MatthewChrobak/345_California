#include "SfmlSurfaceManager.h"
#ifdef DEBUG
#include <assert.h>
#endif
using namespace SFML;

SurfaceManager::SurfaceManager()
{
	this->_surfaces = new std::map<std::string, sf::Texture*>();
	this->_loadTextures();
}

SurfaceManager::~SurfaceManager()
{
	// TODO: Fix this.
	//// Dereference and remove all surfaces in the map.
	//while (this->_surfaces->size() != 0) {
	//	sf::Texture* tex = this->_surfaces->end()->second;
	//	delete tex;
	//	this->_surfaces->erase(this->_surfaces->end()->first);
	//}
}


void SurfaceManager::_loadTextures()
{
	std::string path = FileSystem::getStartupPath() + "graphics\\";
	std::vector<std::string> directories = FileSystem::getDirectories(path + "*");

	// Go through all the directories in the graphics folder.
	for (int i = 0; i < directories.size(); i++) {
		std::string subDirectory = directories.at(i) + "\\";

		// Get all the files in the sub-directory.
		std::vector<std::string> files = FileSystem::getFiles(path + subDirectory + "*");

		for (int j = 0; j < files.size(); j++) {
			std::string relativeFilepath = subDirectory + files.at(j);
			std::string fullFilepath = path + relativeFilepath;

			// Load the texture and add it to the collection.
			sf::Texture* texture = new sf::Texture();
			texture->loadFromFile(fullFilepath);
			this->_surfaces->insert(std::pair<std::string, sf::Texture*>(relativeFilepath, texture));

#ifdef DEBUG
			std::cout << "Loaded texture " << files.at(j) << std::endl;
#endif
		}
	}
}

sf::Texture* SurfaceManager::_getSurface(std::string surfacename)
{
#ifdef DEBUG
	assert(this->_surfaces->count(surfacename));
#endif
	return this->_surfaces->at(surfacename);
}