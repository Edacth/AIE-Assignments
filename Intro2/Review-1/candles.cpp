#include<iostream>
#include "candles.h"

int blow(int* arr, int size)
{
	int blownCandles = 0;
	int currentHeight = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] >= currentHeight)
		{
			//std::cout << "New height" << arr[i] << std::endl;
			currentHeight = arr[i];
			blownCandles++;
		}
	}
	std::cout << "Blown candles: " << blownCandles << std::endl;
	return blownCandles;
}