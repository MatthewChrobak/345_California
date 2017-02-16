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
	if (this->OutlineColor != nullptr) {
		delete this->OutlineColor;
		this->OutlineColor = nullptr;
	}

	// Delete the fill color if we can.
	if (this->FillColor != nullptr) {
		delete this->FillColor;
		this->FillColor = nullptr;
	}

	// Delete the position if we can.
	if (this->Position != nullptr) {
		delete this->Position;
		this->Position = nullptr;
	}
}