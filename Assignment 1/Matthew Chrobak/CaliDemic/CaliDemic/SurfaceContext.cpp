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
	if (this->Color != nullptr) {
		delete this->Color;
		this->Color = nullptr;
	}

	// Delete the position if we can.
	if (this->Position != nullptr) {
		delete this->Position;
		this->Position = nullptr;
	}

	// Delete the size if we can.
	if (this->Size != nullptr) {
		delete this->Size;
		this->Size = nullptr;
	}

	// Delete the surface rect if we can.
	if (this->SurfaceRect != nullptr) {
		delete this->SurfaceRect;
		this->SurfaceRect = nullptr;
	}

	this->Rotation = 0.0f;
}