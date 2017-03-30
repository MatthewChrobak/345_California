#include "SurfaceContext.h"

SurfaceContext::SurfaceContext()
{

}

SurfaceContext::~SurfaceContext()
{
	this->reset();
}

void SurfaceContext::reset()
{
	// Delete the color if we can.
	if (this->getColor() != nullptr) {
		delete this->_color;
		this->_color = nullptr;
	}

	// Delete the size if we can.
	if (this->getRenderSize() != nullptr) {
		delete this->_renderSize;
		this->_renderSize = nullptr;
	}

	// Delete the surface rect if we can.
	if (this->getSurfaceRect() != nullptr) {
		delete this->_surfaceRect;
		this->_surfaceRect = nullptr;
	}

	this->setRotation(0.0f);
}

Rect* SurfaceContext::getSurfaceRect() const
{
	return this->_surfaceRect;
}

Vector2D* SurfaceContext::getRenderSize() const
{
	return this->_renderSize;
}

RGBA* SurfaceContext::getColor() const
{
	return this->_color;
}

float SurfaceContext::getRotation() const
{
	return this->_rotation;
}

void SurfaceContext::setSurfaceRect(int top, int left, int width, int height)
{
	if (this->getSurfaceRect() != nullptr) {
		this->getSurfaceRect()->set(top, left, width, height);
	}
	else {
		this->_surfaceRect = new Rect(top, left, width, height);
	}
}

void SurfaceContext::setRenderSize(int width, int height)
{
	if (this->getRenderSize() != nullptr){
		this->getRenderSize()->setXY(width, height);
	}
	else {
		this->_renderSize = new Vector2D(width, height);
	}
}

void SurfaceContext::setColor(RGBA& color)
{
	if (this->getColor() != nullptr) {
		this->getColor()->setA(color.getA());
		this->getColor()->setR(color.getR());
		this->getColor()->setG(color.getG());
		this->getColor()->setB(color.getB());
	}
	else {
		this->_color = new RGBA(color);
	}
}

void SurfaceContext::setColor(int r, int g, int b)
{
	this->setColor(RGBA(r, g, b));
}

void SurfaceContext::setColor(int r, int g, int b, int a)
{
	this->setColor(RGBA(r, g, b, a));
}

void SurfaceContext::setRotation(float rotation)
{
	this->_rotation = rotation;
}