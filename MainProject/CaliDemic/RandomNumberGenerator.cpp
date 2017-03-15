#include "RandomNumberGenerator.h"
#include <time.h>
#include <iostream>

int RandomNumberGenerator::next(int low, int high)
{
	const int AMOUNT = 11; //amount of random numbers that need to be generated
	const int MAX = high; //maximum value (of course, this must be at least the same as AMOUNT;

	int value[53]; //array to store the random numbers in

	srand(time(NULL)); //always seed your RNG before using it

	//generate random numbers:
	for (int i = 0; i < AMOUNT; i++)
	{
		bool check; //variable to check or number is already used
		int n; //variable to store the number in
		do
		{
			n = (rand() % MAX) + low;
			//check or number is already used:
			check = true;
			for (int j = 0; j < i; j++) {
				if (n == value[j]) //if number is already used
				{
					check = false; //set check to false
					break; //no need to check the other elements of value[]
				}
			}
			
		} while (!check); //loop until new, unique number is found
		return n;
	}
}