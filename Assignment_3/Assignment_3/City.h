#pragma once
#include "Decorator.h"
#include "Observer.h"

class City : virtual public Decorator, public Observer
{
private:
	int IDcityNumber = 0;
	int redInfectedCube = 0;
	int yellowInfectedCube = 0;
	int blackInfectedCube = 0;
	int blueInfectedCube = 0;

public:
	City();
	~City();
	int getCityID();
	void update();
	void cityInfected();
	virtual void getNumber();
	void setRedInfectedCube();
	void setYellowInfectedCube();
	void setBlueInfectedCube();
	void setBlackInfectedCube();
};

