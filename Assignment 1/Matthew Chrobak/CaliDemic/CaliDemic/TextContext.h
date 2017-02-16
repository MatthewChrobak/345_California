#pragma once
#include "CommonContext.h"

class TextContext
{
public:
	TextContext();
	~TextContext();
	void reset();

	Vector2D* Position = nullptr;
	RGBA* OutlineColor = nullptr;
	RGBA* FillColor = nullptr;
	float OutlineThickness = 1.0f;
	int FontSize = 11;
	bool HorizontalCenter = false;
};

