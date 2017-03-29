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
	void setColor(char r, char g, char b);
	void setColor(char r, char g, char b, char a);
	void setRotation(float rotation);

private:
	Rect* surfaceRect = nullptr;
	Vector2D* renderSize = nullptr;
	RGBA* color = nullptr;
	float rotation = 0.0f;
};