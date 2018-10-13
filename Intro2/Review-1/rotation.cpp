#include "rotation.h"
#include <iostream>

void rotate(int* arr, int size, int shift)
{
	for (int i = 0; i < size; i++)
	{
		int temp = arr[i];
		if (i == 0)
		{

			arr[i] = arr[size - 1];
			arr[i + 1] = temp;
		}
		else
		{
			arr[0] = arr[i];
		}
	}
}