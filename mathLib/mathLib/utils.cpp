#include "utils.h"

/*Returns a value no smaller than min and no larger than max*/
int cMath::min(int a, int b)
{
	return a < b ? a : b;
}

/*Returns the larger of the two values*/
int cMath::max(int a, int b)
{
	return a > b ? a : b;
}

/*Returns a value no smaller than min and no larger than max*/
int cMath::clamp(int value, int min, int max)
{
	if (value <= min)
	{
		return min;
	}
	else if (value >= max)
	{
		return max;
	}
	return value;
}

/*Returns the absolute value of val*/
int cMath::abs(int val)
{
	if (val < 0)
	{
		return (val * -1);
	}
	return val;
}

/*Returns base to the power of exp (i.e. base^power)*/
int cMath::pow(int base, int power)
{
	if (power == 0)
	{
		return 1;
	}

	int acc = base; //accumulator
	for (size_t i = 0; i < power - 1; i++)
	{
		acc *= base;
	}

	return acc;
}

/*Returns true if the value is a power of two, otherwise returns false.*/
bool cMath::isPowerOfTwo(int val)
{

	size_t pow = 1;
	while (pow < val)
	{
		pow *= 2;
	}

	return (pow == val);
}

/*Returns the next power of two after the given value.*/
/*The behavior of this function if the next power of two
is beyond the range of int is not defined.*/
int cMath::nextPowerOfTwo(int val)
{
	int nextPower = 0;
	for (size_t i = 0; nextPower <= val; i++)
	{
		nextPower = cMath::pow(2, i);
	}

	return nextPower;
}

/*Moves the current value towards the target value. The maximum change should not exceed maxDelta*/
float cMath::moveTowards(float current, float target, float maxDelta)
{
	if (current < target)
	{
		if (current + maxDelta <= target)
		{
			return current + maxDelta;
		}
		else
		{
			return target;
		}
	}
	else if (current > target)
	{
		if (current - maxDelta >= target)
		{
			return current - maxDelta;
		}
		else
		{
			return target;
		}
	}
	return current;
}