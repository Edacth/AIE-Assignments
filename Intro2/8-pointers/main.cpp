#include <iostream>
#include "pointers.h"

int main()
{
	float numbers[3] = { 3.0f, 5.0f, 6.0f };
	int ints[3] = { 3, 5, 6 };
	bool bools[3] = { false, false, true };
	int moreInts[6] = { 1, 2, 3, 4, 5, 6 };
	int newInts[5];
	char chars[6] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	int val1 = 3;
	int val2 = 5;
	int* a = &val1;
	int* b = &val2;
	//printFloats(numbers, 3);

	//std::cout << arraySum(ints, 3);

	/*
	boolSet(bools, 3, true);

	std::cout << bools[0] << std::endl;
	std::cout << bools[1] << std::endl;
	std::cout << bools[2] << std::endl;
	*/

	//arraySubset(moreInts, newInts, 1, 4);

	/*
	char* value = pointerToElement(chars, 'e', 6, false);
	if (value != nullptr)
	{
		std::cout << value << std::endl;
	}
	else
	{
		std::cout << "null pointer" << std::endl;
	}
	*/

	
	swap(&a, &b);
	std::cout << *a << std::endl;
	std::cout << *b << std::endl;
	

	return 0;
}