#include "tVector.h"
#include <iostream>


int main()
{

	tVector<int> array1;
	tVector<int> array2;
	array1.push_back(5);
	array1.push_back(10);
	array1.push_back(15);
	array1.push_back(20);
	array1.push_back(25);
	array1.push_back(30);

	array1.print();
	//array2 = array1;
	array1.reserve(20);
	array1.print();

	return 0;
}