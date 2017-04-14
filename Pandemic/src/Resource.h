#pragma once
#include "ResourceIndexer.h"

class Resource
{
public:
	Resource(std::string resourceType);

	std::string getResourceID();
	std::string getResourceType();

private:
	std::string _resourceID;
	std::string _resourceType;
};