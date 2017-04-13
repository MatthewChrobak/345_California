#include "TextContext.h"
#ifdef DEBUG
#include <assert.h>
#endif

TextOutline::~TextOutline()
{
    this->reset();
}

void TextOutline::reset()
{
    if (this->getColor() == nullptr) {
        delete this->_color;
        this->_color = nullptr;
    }
    this->_thickness = 1.0f;
}

void TextOutline::setThickness(float thickness)
{
#ifdef DEBUG
    assert(thickness > 0);
#endif
    this->_thickness = thickness;
}

void TextOutline::setColor(RGBA& color)
{
    if (this->getColor() != nullptr) {
        this->getColor()->setR(color.getR());
        this->getColor()->setG(color.getG());
        this->getColor()->setB(color.getB());
        this->getColor()->setA(color.getA());
    }
    else {
        this->_color = new RGBA(color.getR(), color.getG(), color.getB(), color.getA());
    }
}

void TextOutline::setColor(int r, int g, int b)
{
    RGBA rgba (r,g,b);

    this->setColor(rgba);
}

void TextOutline::setColor(int r, int g, int b, int a)
{
    RGBA rgba (r,g,b, a);

    this->setColor(rgba);
}

float TextOutline::getThickness() const
{
    return this->_thickness;
}

RGBA* TextOutline::getColor() const
{
    return this->_color;
}



TextContext::~TextContext()
{
    this->reset();
}

void TextContext::reset()
{
    // Delete the fill color if we can.
    if (this->getFontColor() != nullptr) {
        delete this->_fontColor;
        this->_fontColor = nullptr;
    }

    this->setFont("default.ttf");
    this->getOutline().reset();
    this->setFontSize(11);
    this->setHorizontalCenter(false);
}

void TextContext::setFontSize(unsigned int value)
{
    this->_fontSize = value;
}

void TextContext::setHorizontalCenter(bool value)
{
    this->_horizontalCenter = value;
}

void TextContext::setFont(const char* fontFileName)
{
    this->_fontname = fontFileName;
}

void TextContext::setFontColor(RGBA& color)
{
    if (this->getFontColor() != nullptr) {
        this->getFontColor()->setR(color.getR());
        this->getFontColor()->setG(color.getG());
        this->getFontColor()->setB(color.getB());
        this->getFontColor()->setA(color.getA());
    }
    else {
        this->_fontColor = new RGBA(color.getR(), color.getG(), color.getB(), color.getA());
    }
}

void TextContext::setFontColor(int r, int g, int b)
{
    RGBA rgba (r,g,b);
    this->setFontColor(rgba);
}

void TextContext::setFontColor(int r, int g, int b, int a)
{
    RGBA rgba (r,g,b, a);

    this->setFontColor(rgba);
}


TextOutline& TextContext::getOutline()
{
    return this->_outline;

}

RGBA* TextContext::getFontColor() const
{
    return this->_fontColor;
}

unsigned int TextContext::getFontSize() const
{
    return this->_fontSize;
}

bool TextContext::getHorizontalCenter() const
{
    return this->_horizontalCenter;
}

const char* TextContext::getFontName() const
{
    return this->_fontname;
}