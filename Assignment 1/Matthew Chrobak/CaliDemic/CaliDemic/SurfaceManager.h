#pragma once
#include "FileSystem.h"
#include <map>
#include <SFML\Graphics\Texture.hpp>

class SurfaceManager
{
private:
	std::map<std::string, sf::Texture*>* _surfaces;
	
	void _loadTextures();

public:
	SurfaceManager();
	~SurfaceManager();
};

