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
	if (this->color != nullptr) {
		delete this->color;
		this->color = nullptr;
	}

	// Delete the position if we can.
	if (this->position != nullptr) {
		delete this->position;
		this->position = nullptr;
	}

	// Delete the size if we can.
	if (this->size != nullptr) {
		delete this->size;
		this->size = nullptr;
	}

	// Delete the surface rect if we can.
	if (this->surfaceRect != nullptr) {
		delete this->surfaceRect;
		this->surfaceRect = nullptr;
	}

	this->rotation = 0.0f;
}