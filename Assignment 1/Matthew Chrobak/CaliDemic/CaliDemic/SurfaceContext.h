#pragma once
#include "CommonContext.h"

class SurfaceContext
{
public:
	SurfaceContext();
	~SurfaceContext();
	void reset();

	Rect* SurfaceRect = nullptr;
	Vector2D* Size = nullptr;
	Vector2D* Position = nullptr;
	RGBA* Color = nullptr;
	float Rotation = 0.0f;
};