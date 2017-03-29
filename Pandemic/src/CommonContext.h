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
	RGBA(char r, char g, char b);
	RGBA(char r, char g, char b, char a);

	void setR(char r);
	void setG(char g);
	void setB(char b);
	void setA(char a); 
	
	char getR() const;
	char getG() const;
	char getB() const;
	char getA() const;

private:
	char _r;
	char _g;
	char _b;
	char _a;
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