#pragma once

struct Vector2D
{
	Vector2D();
	Vector2D(int x, int y);
	int X;
	int Y;
};

struct Rect
{
	Rect();
	Rect(int top, int left, int width, int height);

	int Top;
	int Left;
	int Width;
	int Height;
};

struct RGBA
{
	RGBA();
	RGBA(int r, int g, int b);
	RGBA(int r, int g, int b, float a);

	int R;
	int G;
	int B;
	float A;
};

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
};