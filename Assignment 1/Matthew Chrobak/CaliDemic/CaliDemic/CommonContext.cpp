#include "CommonContext.h"

RGBA::RGBA() : RGBA::RGBA(255, 255, 255, 1.0f)
{

}

RGBA::RGBA(int r, int g, int b)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = 255.0f;
}

RGBA::RGBA(int r, int g, int b, float a) : RGBA::RGBA(r, g, b)
{
	this->a = a;
}



Rect::Rect()
{
	this->width = 0;
	this->height = 0;
	this->top = 0;
	this->left = 0;
}

Rect::Rect(int top, int left, int width, int height)
{
	this->top = top;
	this->left = left;
	this->width = width;
	this->height = height;
}


Vector2D::Vector2D()
{
	this->x = 0;
	this->y = 0;
}

Vector2D::Vector2D(int x, int y)
{
	this->x = x;
	this->y = y;
}