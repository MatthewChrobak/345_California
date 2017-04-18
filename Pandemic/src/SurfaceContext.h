/*!
	Author: Matthew Chrobak
	Contributors:
	Purpose: Provides a data-structure meant to be used to describe how a surface should be rendered.
*/
#pragma once
#include "CommonContext.h"

class SurfaceContext : public CommonContext
{
public:
    SurfaceContext();
    virtual ~SurfaceContext() override;
    virtual void reset() override;

    Rect* getSurfaceRect() const;
    Vector2D* getRenderSize() const;
    RGBA* getColor() const;
    float getRotation() const;

    void setSurfaceRect(int top, int left, int width, int height);
    void setRenderSize(int width, int height);
    void setColor(RGBA& color);
    void setColor(int r, int g, int b);
    void setColor(int r, int g, int b, int a);
    void setRotation(float rotation);

private:
    Rect* _surfaceRect = nullptr;
    Vector2D* _renderSize = nullptr;
    RGBA* _color = nullptr;
    float _rotation = 0.0f;
};