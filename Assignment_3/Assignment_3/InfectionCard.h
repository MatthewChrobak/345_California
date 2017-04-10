#pragma once
#include "Decorator.h"
#include "Subject.h"

class InfectionCard : virtual public Decorator, public Observer
{
public:
	InfectionCard();
	~InfectionCard();

	virtual void getNumber();
	void update();
	void infectCityCard();

};

