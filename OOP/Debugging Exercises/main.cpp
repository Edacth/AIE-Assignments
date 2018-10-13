#include <iostream>

bool containsValue(int value, int * arr, int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] == value)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	int nums[] = { 0, 5, 7, 1, 2, 3 };

	bool result = containsValue(8, nums, 6);

	std::cout << "The value was " << (result ? "found" : "not found") << "!" << std::endl;

	return 0;
}