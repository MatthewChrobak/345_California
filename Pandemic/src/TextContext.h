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
    void reset();

    void setThickness(float thickness);
    void setColor(RGBA& color);
    void setColor(int r, int g, int b);
    void setColor(int r, int g, int b, int a);

    float getThickness() const;
    RGBA* getColor() const;

private:
    float _thickness = 1.0f;
    RGBA* _color = nullptr;
};

class TextContext : public CommonContext
{
public:
    virtual ~TextContext() override;
    virtual void reset() override;

    void setFontSize(unsigned int value);
    void setHorizontalCenter(bool value);
    void setFont(const char* fontFileName);
    void setFontColor(RGBA& color);
    void setFontColor(int r, int g, int b);
    void setFontColor(int r, int g, int b, int a);

    TextOutline& getOutline();
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