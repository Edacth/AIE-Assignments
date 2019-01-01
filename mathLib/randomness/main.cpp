#include "raylib.h"
#undef PI;
#include "random.h"
#include "vec2.h"
#include <string>
#include <iostream>

int main()
{
	int seed1 = 675248;
	int seed2 = 259500;

	cMath::random randomizer1;
	cMath::random randomizer2(seed2);
	randomizer1.seedRand(seed1);


	/*cMath::seedRand(seed);
	for (size_t i = 0; i < 100; i++)
	{
		std::cout << cMath::rand(1, 100) << std::endl;
	}
	for (size_t i = 0; i < 100; i++)
	{
	std::cout << cMath::randDecimal(1.0f, 100.0f) << std::endl;
	}*/
	for (size_t i = 0; i < 100; i++)
	{
		std::cout << randomizer1.randDecimal(1, 100) << std::endl;
		std::cout << randomizer2.randDecimal(1, 100) << std::endl;
	}

	return 0;
}