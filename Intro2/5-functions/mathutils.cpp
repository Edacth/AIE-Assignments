#include "mathutils.h"
#include <iostream>

int sum(int a, int b)
{

	return a + b;
}

float sum(float a, float b)
{

	return a + b;
}

int Min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int Max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int clamp(int min, int max, int number)
{
	number = Max(min, number);
	number = Min(max, number);
	return number;
}


