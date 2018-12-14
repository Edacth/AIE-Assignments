#pragma once
#include <ctgmath>

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

	/*Float version of pow*/
	float pow(float base, int power);

	/*Returns true if the value is a power of two, otherwise returns false.*/
	bool isPowerOfTwo(int val);

	/*Returns the next power of two after the given value.*/
	/*The behavior of this function if the next power of two 
	is beyond the range of int is not defined.*/
	int nextPowerOfTwo(int val);

	/*Moves the current value towards the target value. The maximum change should not exceed maxDelta*/
	float moveTowards(float current, float target, float maxDelta);

	/*Linearly Interpolate between two values*/
	// implementation one
	template <typename T>
	T lerp(const T& a, const T& b, float t)
	{
		return a * (1 - t) + b * t;
	}
	
	// implementation two
	template <typename T>
	T lerp2(const T& a, const T& b, float t)
	{
		return a + (b - a) * t;
	}

	template <typename T>
	T quadraticBezier(const T& a, const T& b, const T& c, float t)
	{
		T x = lerp(a, b, t);
		T y = lerp(b, c, t);
		return lerp(x, y, t);
	}

	template <typename T>
	T quadraticBezier(const T& a, const T& b, const T& c, const T& d, float t)
	{
		T x = lerp(a, b, t);
		T y = lerp(b, c, t);
		T z = lerp(c, d, t);
		return quadraticBezier(x, y, z, t);
	}

	template <typename T>
	T cubicBezier(const T& a, const T& b, const T& c, const T& d, float t)
	{
		float x = lerp(a, b, t);
		float y = lerp(b, c, t);
		float z = lerp(c, d, t);
		float u = lerp(x, y, t);
		float v = lerp(y, z, t);
		return lerp(u, v, t);
	}

	extern int seed;
	/* returns a random value between min and max */
	template <typename T>
	T rand(T min, T max)
	{
		T n = max - min + 1;
		T _seed = seed;
		cMath::regenSeed();
		return _seed % n + 1;
	}

	/* returns a random value between min and max
	 - the value may contain decimal components */
	template <typename T>
	T randDecimal(T min, T max)
	{
		T n = max - min + 1.0f;
		n *= 100;
		T _seed = seed;
		cMath::regenSeed();
		return (fmod(_seed, n) + 1) /100;
	}

	/* seed the random number generator */
	void seedRand(int seedValue);

	/* returns the seed used for the random number generator */
	int getRandSeed();

	/*Runs the seed through the middle square method*/
	void regenSeed();
}

