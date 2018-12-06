#pragma once

namespace cMath
{


	/*Returns the smaller of the two values*/
	int min(int a, int b);

	/*Returns the larger of the two values*/
	int max(int a, int b);

	/*Returns a value no smaller than min and no larger than max*/
	int clamp(int value, int min, int max);

	/*Defined as PI*/
	const double PI = 3.141592653589793238;

	/*Multiply this with an angle measure expressed in degrees to get its equivalent in radians*/
	const double DEG_TO_RAD = (PI / 180);

	/*Multiply this with a angle measure expressed in radians to get its equivalent in degrees.*/
	const double RAD_TO_DEG = (180 / PI);

	/*Returns the absolute value of val*/
	int abs(int val);

	/*Returns base to the power of exp (i.e. base^power)*/
	int pow(int base, int power);

	/*Returns true if the value is a power of two, otherwise returns false.*/
	bool isPowerOfTwo(int val);
}