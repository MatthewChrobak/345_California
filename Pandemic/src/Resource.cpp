#include "Resource.h"

Resource::Resource(std::string resourceType)
{
	this->_resourceType = resourceType;
	this->_resourceID = ResourceIndexer::generateRValue();
}

std::string Resource::getResourceID()
{
	return this->_resourceID;
}