#include "tVector.h"
#include <iostream>


int main()
{

	tVector<int> array1;
	array1.push_back(1);
	array1.push_back(3);

	std::cout << array1.at(0) << std::endl;
	std::cout << array1.at(1) << std::endl;

	return 0;
}