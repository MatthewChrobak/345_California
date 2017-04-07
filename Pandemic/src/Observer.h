/*!
	Author: Matthew Chrobak
	Contributors:

	Purpose: A generic abstract observer class.
*/
#pragma once

class Observer
{
public:
	virtual void update(void* subject) = 0;
};

