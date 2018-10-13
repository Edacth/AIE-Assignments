#include <iostream>
#include "mathutils.h"


int main()
{
	/*
	//messy interpolation
	int val = sum(5, 2);
	float fval = sum(5.5f, 1.2f);


	float num1 = 5.0f;
	float num2 = 10.0f;
	float normalizer = 0.5f;

	float diff = num2 - num1;
	float normalized = diff * normalizer;
	float solution = num1 + normalized;

	std::cout << solution << std::endl;
	*/

	//Clamp v2
	/*
	std::cout << min(5, 10) << std::endl;
	std::cout << min(10, 5) << std::endl;
	std::cout << max(5, 10) << std::endl;
	std::cout << max(10, 5) << std::endl;
	*/

	int number, min, max;
	std::cin >> min >> max >> number;
	std::cout << clamp(min, max, number);

	return 0;
}

