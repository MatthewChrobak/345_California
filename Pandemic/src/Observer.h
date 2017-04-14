/*!
	Author: Matthew Chrobak
	Contributors:

	Purpose: A generic abstract observer class.
*/
#pragma once

enum UpdateType : int
{
	Attatch_Update,
	Notify_Update
};

class Observer
{
public:
	virtual void update(void* subject, UpdateType type) = 0;
};

