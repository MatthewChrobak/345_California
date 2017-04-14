/*!
	Author: Matthew Chrobak
	Contributors:

	Purpose: A generic observable class.
*/
#pragma once
#include "Observer.h"
#include <vector>

class Observable
{
public:
	virtual void attach(Observer* observer);
	virtual void detatch(Observer* observer);

	virtual void notify(UpdateType type);

private:
	std::vector<Observer*> _observers;
};

