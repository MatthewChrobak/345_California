/*!
	Author: Matthew Chrobak
	Contributors:

	Purpose: 
*/

#pragma once
#include "Observable.h"
#include "Resource.h"

class Drawable : public Observable, public Resource
{
public:
	Drawable(unsigned int zindex, std::string type);
	int getZIndex();

private:
	unsigned int _z_index;
	bool _assigned = false;
};