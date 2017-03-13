#pragma once
#include "CommonContext.h"

class SurfaceContext
{
public:
	SurfaceContext();
	~SurfaceContext();
	void reset();

	Rect* surfaceRect = nullptr;
	Vector2D* size = nullptr;
	Vector2D* position = nullptr;
	RGBA* color = nullptr;
	float rotation = 0.0f;
};