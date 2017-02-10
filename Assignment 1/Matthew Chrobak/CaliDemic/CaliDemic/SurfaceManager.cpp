#include "SurfaceManager.h"


SurfaceManager::SurfaceManager()
{
	this->_surfaces = new std::map<std::string, sf::Texture*>();
	this->_loadTextures();
}

SurfaceManager::~SurfaceManager()
{
	// TOO: Delete allocated memory in the map of textures.
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