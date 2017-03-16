#pragma once
#include "Observer.h"
#include <vector>

class Observable
{
public:
	void attach(Observer* observer);
	void detach(Observer* observer);

	virtual void notify();

private:
	std::vector<Observer*> _observers;
};

