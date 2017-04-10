#pragma once
#include "Observer.h"
#include <vector>
using namespace std;

// This interface handles adding, deleting and updating
// all observers
class Subject
{
public:
	virtual void attach(Observer* o);
	virtual void detach(Observer* o);
	virtual void notify();
	Subject();
	~Subject();

private:
	vector<Observer*> _observers;
};

