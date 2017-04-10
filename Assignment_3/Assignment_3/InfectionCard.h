#pragma once
#include "Decorator.h"
#include "Subject.h"

class InfectionCard : virtual public Decorator, public Subject
{
public:
	InfectionCard();
	~InfectionCard();

	virtual void getNumber();

};

