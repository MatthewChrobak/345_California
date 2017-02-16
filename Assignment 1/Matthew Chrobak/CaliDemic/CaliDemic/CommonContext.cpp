#include "CommonContext.h"

RGBA::RGBA() : RGBA::RGBA(255, 255, 255, 1.0f)
{

}

RGBA::RGBA(int r, int g, int b)
{
	this->R = r;
	this->G = g;
	this->B = b;
	this->A = 255.0f;
}

RGBA::RGBA(int r, int g, int b, float a) : RGBA::RGBA(r, g, b)
{
	this->A = a;
}



Rect::Rect()
{
	this->Width = 0;
	this->Height = 0;
	this->Top = 0;
	this->Left = 0;
}

Rect::Rect(int top, int left, int width, int height)
{
	this->Top = top;
	this->Left = left;
	this->Width = width;
	this->Height = height;
}


Vector2D::Vector2D()
{
	this->X = 0;
	this->Y = 0;
}

Vector2D::Vector2D(int x, int y)
{
	this->X = x;
	this->Y = y;
}