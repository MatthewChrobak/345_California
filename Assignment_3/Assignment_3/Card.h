#pragma once
#include "Decorator.h"

class Card : virtual public Decorator
{
public:
	Card();
	~Card();

	virtual void getNumber();
};

