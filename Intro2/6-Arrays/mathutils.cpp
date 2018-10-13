#include <iostream>

bool arrayUniqueness(int arr[], int size)
{
	bool isUnique = true;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i] == arr[j] && i != j)
			{
				isUnique = false;
			}

		}

	}

	return isUnique;
}

int insertionSort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		/*
		if (arr[i] > arr[i-1])
		{

			int temp = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = temp;

		}
		*/
		
		for (int j = i; j > 0; j--)
		{
			int b = arr[j];
			int a = arr[j - 1];
			if (b > a)
			{
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;

				//display the current array
				for (int k = 0; k < size; k++)
				{
					std::cout << arr[k];
				}
				std::cout << std::endl;
			}
		}
		
		
	}

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i];
	}
	std::cout << std::endl;
	return 0;
}