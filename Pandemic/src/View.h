#pragma once
#include "Observer.h"
#include "Drawable.h"
#include "Controller.h"
#include <vector>
#include <map>

class View : public Observer
{
public:
	virtual void update(Drawable* subject, UpdateType type);
	virtual void update(void* subject, UpdateType type);

	virtual void attachController(Controller* controller);

protected:
	Controller* controller;

	std::vector<std::map<std::string, Drawable>> layers;
};

