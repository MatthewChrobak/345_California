/*!
	Author: Matthew Chrobak
	Contributors:

	Purpose: Defines the SFML implementation of the Graphics System.
			 Handles all reqeusts for drawn-surfaces and text.
*/
#pragma once
#include "GraphicsSystem.h"
#include "SfmlFontManager.h"
#include "SfmlSurfaceManager.h"

namespace SFML
{
	class SfmlGraphicsSystem : public GraphicsSystem, private SfmlSurfaceManager, SfmlFontManager, GameRenderer
	{

	};
}