#pragma once
#include "Decorator.h"
#include "Subject.h"


class City : virtual public Decorator, public Subject
{
private:
	int IDcityNumber = 0;
	int redInfectedCube = 0;
	int yellowInfectedCube = 0;
	int blackInfectedCube = 0;
	int blueInfectedCube = 0;

public:
	vector<Observer*> *observers;
	void attach(Observer* o);
	void detach(Observer* o);
	void notify();
	City();
	~City();
	int getCityID();
	virtual void getNumber();
};

