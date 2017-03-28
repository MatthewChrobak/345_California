#pragma once
#include "CommonContext.h"

class TextContext
{
public:
	TextContext();
	~TextContext();
	void reset();

	Vector2D* position = nullptr;
	RGBA* outlineColor = nullptr;
	RGBA* fillColor = nullptr;
	float outlineThickness = 1.0f;
	int fontSize = 11;
	bool horizontalCenter = false;
	const char* fontname = "default.ttf";
};

