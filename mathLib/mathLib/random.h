#pragma once
#include <ctgmath>

namespace cMath
{

	class random
	{
		/*Seed of the randomizer*/
		int seed;

	public:
		/*Default constructor*/
		random();

		/*Constructor that takes a seed*/
		random(int seed);

		/*Deconstructor*/
		~random();
		

		
		/* returns a random value between min and max */
		template <typename T>
		T rand(T min, T max)
		{
			T n = max - min + 1;
			T _seed = seed;
			regenSeed();
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
			regenSeed();
			return (fmod(_seed, n) + 1) / 100;
		}

		/* seed the random number generator */
		void seedRand(int seedValue);

		/* returns the seed used for the random number generator */
		int getRandSeed();

		/*Runs the seed through the middle square method*/
		void regenSeed();

	};
}