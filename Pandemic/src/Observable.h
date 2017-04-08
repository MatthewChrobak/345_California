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
	void attach(Observer* observer);
	void detatch(Observer* observer);

	virtual void notify();

private:
	std::vector<Observer*> _observers;
};

