#include "ResourceIndexer.h"

std::string ResourceIndexer::generateRValue()
{
	static unsigned int rValue = 0;
	return std::to_string(rValue++);
}