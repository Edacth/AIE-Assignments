#include "raylib.h"
#undef PI;
#include "utils.h"
#include "vec2.h"
#include <string>
#include <iostream>

int main()
{
	//int seed = 675248;
	int seed = 259500;

	cMath::seedRand(seed);
	/*for (size_t i = 0; i < 100; i++)
	{
		std::cout << cMath::rand(1, 100) << std::endl;
	}*/
	for (size_t i = 0; i < 100; i++)
	{
	std::cout << cMath::randDecimal(1.0f, 100.0f) << std::endl;
	}
	return 0;
}