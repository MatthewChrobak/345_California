/*!
	Author: Matthew Chrobak
	Contributors:

	Purpose: Provides a data-structure meant to be used to describe how text should be rendered.
*/
#pragma once
#include "CommonContext.h"

class TextOutline
{
public:
	~TextOutline();

	void setThickness(float thickness);
	void setColor(RGBA& color);

	float getThickness() const;
	RGBA* getColor() const;

private:
	float _thickness = 1.0f;
	RGBA* color = nullptr;
};

class TextContext : public CommonContext
{
public:
	TextContext();
	virtual ~TextContext() override;
	virtual void reset() override;

	void setFontSize(unsigned int value);
	void setHorizontalCenter(bool value);
	void setFont(const char* fontFileName);
	void setFontColor(RGBA& color);
	void setFontColor(char r, char g, char b);
	void setFontColor(char r, char g, char b, char a);

	TextOutline& getOutline() const;
	RGBA* getFontColor() const;
	unsigned int getFontSize() const;
	bool getHorizontalCenter() const;
	const char* getFontName() const;

private:
	TextOutline _outline;
	RGBA* _fontColor = nullptr;
	unsigned int _fontSize = 11;
	bool _horizontalCenter = false;
	const char* _fontname = "default.ttf";
};
