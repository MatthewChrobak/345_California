#pragma once
#include "SfmlSystem.h"

#ifdef DEBUG

// Sample main for debugging and testing purposes.
int main() {
	SfmlSystem* system = new SfmlSystem("SFML is working", 960, 640, 960, 640);
	
	int tick = 0, tmrRender = 0;

	while (!system->isDestroyed())
	{
		tick = clock();

		if (tmrRender < tick) {
			system->drawContext();
			tmrRender = tick + 16;
		}
	}

	delete system;
}

#endif