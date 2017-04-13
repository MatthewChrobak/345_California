#pragma once
class RandomNumberGenerator
{
public:
	static int next(int low, int high);

private:
	static bool _seeded;
};
