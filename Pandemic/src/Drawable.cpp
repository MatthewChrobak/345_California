#include "Drawable.h"
#ifdef DEBUG
#include <assert.h>
#endif

Drawable::Drawable(unsigned int zindex, std::string type) : Resource(type)
{
	this->_z_index = zindex;
}

int Drawable::getZIndex()
{
	return this->_z_index;
}