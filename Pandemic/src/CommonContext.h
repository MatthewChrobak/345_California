/*!
	Author: Matthew Chrobak
	Contributors:

	Purpose: Provides common data-structures meant to be used with Surface and Text contexts.
*/
#pragma once

class Vector2D
{
public:
	Vector2D();
	Vector2D(int x, int y);

	void setXY(int x, int y);
	void setX(int x);
	void setY(int y);

	int getX() const;
	int getY() const;

private:
	int _x;
	int _y;
};

class Rect
{
public:
	Rect();
	Rect(int top, int left, int width, int height);

	void set(int top, int left, int width, int height);
	void setTop(int top);
	void setLeft(int left);
	void setWidth(int width);
	void setHeight(int height);

	int getTop() const;
	int getLeft() const;
	int getWidth() const;
	int getHeight() const;

private:
	int _top = 0;
	int _left = 0;
	int _width = 0;
	int _height = 0;
};

class RGBA
{
public:
	RGBA();
	RGBA(int r, int g, int b);
	RGBA(int r, int g, int b, int a);

	void set(int r, int g, int b);
	void set(int r, int g, int b, int a);

	void setR(int r);
	void setG(int g);
	void setB(int b);
	void setA(int a);
	
	int getR() const;
	int getG() const;
	int getB() const;
	int getA() const;

private:
	int _r;
	int _g;
	int _b;
	int _a;
};

class CommonContext
{
public:
	virtual ~CommonContext();
	virtual void reset();

	void setPosition(int x, int y);
	Vector2D* getPosition() const;

private:
	void setPosition(Vector2D* ptr);
	Vector2D* _renderPosition = nullptr;
};