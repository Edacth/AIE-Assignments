#include "raylib.h"
//#undef PI;
#include "random.h"
#include "mat3.h"
#include "vec2.h"
#include <string>
#include <iostream>
#undef PI
#include "utils.h"

int main()
{
	int seed1 = 675248;
	int seed2 = 259500;

	cMath::random randomizer1;
	cMath::random randomizer2(seed2);
	randomizer1.seedRand(seed1);
	vec2 vec2a(1, 0);
	vec2 vec2b(.7, .7);

	std::cout << "Test rot" << cMath::RAD_TO_DEG * vec2a.angleBetween(vec2b) << std::endl;
	/*cMath::seedRand(seed);
	for (size_t i = 0; i < 100; i++)
	{
		std::cout << cMath::rand(1, 100) << std::endl;
	}
	for (size_t i = 0; i < 100; i++)
	{
	std::cout << cMath::randDecimal(1.0f, 100.0f) << std::endl;
	}*/
	/*for (size_t i = 0; i < 100; i++)
	{
		std::cout << randomizer1.randDecimal(1, 100) << std::endl;
		std::cout << randomizer2.randDecimal(1, 100) << std::endl;
	}*/

	mat3 matrix1 =
	{1, 2, 3,
	 4, 5, 6,
	 7, 8, 9 };

	mat3 matrix2 =
	{9, 8, 7,
	 6, 5, 4,
	 3, 2, 1 };

	mat3 matrix3 =
	{1, 0, 0,
	 0, 1, 0,
	 0, 0, 1 };
	
	matrix1 *= matrix2;

	mat3::rotation(1.76f).print();
	//mat3::rotation(PI / 2).print();
	//std::cout << vector2.x << " " << vector2.y << " " << vector2.z << std::endl;
	//mat3::translation(3, 4).print();

	//(matrix3 * mat3::rotation(DEG2RAD * 90)).print();

	return 0;
}