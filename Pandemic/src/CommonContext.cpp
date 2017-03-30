#include "CommonContext.h"
#ifdef DEBUG
#include <assert.h>
#endif

RGBA::RGBA() : RGBA::RGBA(255, 255, 255, 255)
{

}

RGBA::RGBA(int r, int g, int b)
{
	this->set(r, g, b, 255);
}

RGBA::RGBA(int r, int g, int b, int a) : RGBA::RGBA(r, g, b)
{
	this->setA(a);
}

void RGBA::set(int r, int g, int b)
{
	this->set(r, g, b, 255);
}

void RGBA::set(int r, int g, int b, int a)
{
	this->setR(r);
	this->setG(g);
	this->setB(b);
	this->setA(a);
}

void RGBA::setR(int r)
{
	this->_r = r;
}

void RGBA::setG(int g)
{
	this->_g = g;
}

void RGBA::setB(int b)
{
	this->_b = b;
}

void RGBA::setA(int a)
{
	this->_a = a;
}

int RGBA::getR() const
{
	return this->_r;
}

int RGBA::getG() const
{
	return this->_g;
}

int RGBA::getB() const 
{
	return this->_b;
}

int RGBA::getA() const
{
	return this->_a;
}




Rect::Rect()
{
	this->setWidth(0);
	this->setHeight(0);
	this->setTop(0);
	this->setLeft(0);
}

Rect::Rect(int top, int left, int width, int height)
{
	this->set(top, left, width, height);
}

void Rect::set(int top, int left, int width, int height)
{
	this->setTop(top);
	this->setLeft(left);
	this->setWidth(width);
	this->setHeight(height);
}

void Rect::setTop(int top)
{
	this->_top = top;
}

void Rect::setLeft(int left)
{
	this->_left = left;
}

void Rect::setWidth(int width)
{
	this->_width = width;
}

void Rect::setHeight(int height)
{
	this->_height = height;
}

int Rect::getTop() const
{
	return this->_top;
}

int Rect::getLeft() const
{
	return this->_left;
}

int Rect::getWidth() const
{
	return this->_width;
}

int Rect::getHeight() const
{
	return this->_height;
}


Vector2D::Vector2D()
{
	this->setXY(0, 0);
}

Vector2D::Vector2D(int x, int y)
{
	this->setXY(x, y);
}

void Vector2D::setXY(int x, int y)
{
	this->setX(x);
	this->setY(y);
}

void Vector2D::setX(int x)
{
	this->_x = x;
}

void Vector2D::setY(int y)
{
	this->_y = y;
}

int Vector2D::getX() const
{
	return this->_x;
}

int Vector2D::getY() const 
{
	return this->_y;
}



CommonContext::~CommonContext()
{
	this->reset();
}

void CommonContext::reset()
{
	if (this->getPosition() != nullptr) {
		delete this->getPosition();
		this->setPosition(nullptr);
	}
}

void CommonContext::setPosition(int x, int y)
{
	// Modify the current existing object if it exists.
	if (this->getPosition() != nullptr) {
		this->getPosition()->setXY(x, y);
	}
	else {
		// Otherwise, create a new one.
		this->setPosition(new Vector2D(x, y));
	}
}

void CommonContext::setPosition(Vector2D* ptr)
{
#ifdef DEBUG
	assert(this->_renderPosition != nullptr);
#endif
	this->_renderPosition = ptr;
}

Vector2D* CommonContext::getPosition() const
{
	return this->_renderPosition;
}