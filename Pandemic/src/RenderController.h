#pragma once
#include "Controller.h"

class RenderView;

class RenderController : public Controller
{
protected:
	RenderView* view;
};