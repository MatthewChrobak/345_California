#pragma once
#include "View.h"

class RenderView : public View
{
public:
	RenderView();
	virtual void clear() = 0;
	virtual void draw() = 0;
	virtual void display() = 0;
};