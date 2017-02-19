#include "TextContext.h"


TextContext::TextContext()
{
}


TextContext::~TextContext()
{
	this->reset();
}

void TextContext::reset()
{
	// Delete the outline color if we can.
	if (this->outlineColor != nullptr) {
		delete this->outlineColor;
		this->outlineColor = nullptr;
	}

	// Delete the fill color if we can.
	if (this->fillColor != nullptr) {
		delete this->fillColor;
		this->fillColor = nullptr;
	}

	// Delete the position if we can.
	if (this->position != nullptr) {
		delete this->position;
		this->position = nullptr;
	}

	this->outlineThickness = 1.0f;
	this->fontSize = 11;
	this->horizontalCenter = false;

}