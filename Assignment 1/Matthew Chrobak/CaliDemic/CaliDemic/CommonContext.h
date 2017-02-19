#pragma once

struct Vector2D
{
	Vector2D();
	Vector2D(int x, int y);
	int x;
	int y;
};

struct Rect
{
	Rect();
	Rect(int top, int left, int width, int height);

	int top;
	int left;
	int width;
	int height;
};

struct RGBA
{
	RGBA();
	RGBA(int r, int g, int b);
	RGBA(int r, int g, int b, float a);

	int r;
	int g;
	int b;
	float a;
};