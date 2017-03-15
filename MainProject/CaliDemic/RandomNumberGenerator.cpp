#include "RandomNumberGenerator.h"
#include <time.h>
#include <iostream>

bool RandomNumberGenerator::_seeded = false;

int RandomNumberGenerator::next(int low, int high)
{
	// Seed the random number generator if we haven't already.
	if (!RandomNumberGenerator::_seeded) {
		RandomNumberGenerator::_seeded = true;
		srand(time(0));
	}

	return (rand() % (high - low) + low);
}