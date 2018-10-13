#include <iostream>

bool detectCheat(int min, int max)
{
	int difference = max - min;
	if (difference <= 1)
	{
		
		return true;
	}
	else
	{
		return false;
	}
}