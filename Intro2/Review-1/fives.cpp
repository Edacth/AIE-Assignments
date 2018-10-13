#include<iostream>
#include "fives.h"

void printFives(int start, int end)
{
	for (int i = start; i <= end; i++)
	{
		std::cout << (i * 5) << std::endl;

	}
}