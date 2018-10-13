#include <iostream>
int getFirstNumber(int* arr)
{
	return arr[0];
	//return *(arr + 2);
}

int example()
{
	int coffeeCup = 0;
	int* pointer = &coffeeCup;

	//Value
	std::cout << coffeeCup << std::endl;
	//Location of value in the memory
	std::cout << pointer << std::endl;
	//Value at the location in memory
	std::cout << *pointer << std::endl;

	//Sets the pointer's location's value to 7
	*pointer = 7;
	std::cout << *pointer << std::endl;

	int numbers[3] = { 3, 5, 6 };
	std::cout << getFirstNumber(numbers) << std::endl;

	int gummyBear = 5;
	std::cout << getFirstNumber(&gummyBear) << std::endl;
	return 0;
}

void printFloats(float* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << arr[i];
	}
}

int arraySum(int* arr, int length)
{
	int sum = 0;
	for (int i = 0; i < length; i++)
	{
		sum += arr[i];
	}
	
	return sum;
}

void boolSet(bool* arr, int length, bool defaultValue)
{
	//std::cout << arr;
	for (int i = 0; i < length; i++)
	{
		arr[i] = defaultValue;
		
	}

}

int arraySubset(int* fromArr, int* toArr, int start, int end)
{
	int j = 0;
	for (int i = start; i <= end; i++)
	{

		toArr[j] = fromArr[i];
		
		std::cout << toArr[j] << std::endl;
		j++;
	}
	return 0;
}

char* pointerToElement(char* arr, char searched, int length, bool caseMatters)
{
	//Make case irrelevant if case doesnt matter.
	if (caseMatters == false)
	{
		searched = toupper(searched);
		for (int i = 0; i < length; i++)
		{
			arr[i] = toupper(arr[i]);
		}

	}

	for (int i = 0; i < length; i++)
	{
		if (arr[i] == searched)
		{
			std::cout << "Found at " << i << std::endl;
			return &(arr[i]);
		}
	}
	return nullptr;
}

void swap(int** a, int** b)
{
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	int* temp = *a;
	*a = *b;
	*b = temp;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
}

