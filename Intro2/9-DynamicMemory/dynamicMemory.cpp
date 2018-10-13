#include <iostream>
#include "dynamicMemory.h"

int example()
{
	//create a single object on the heap
	int * age = new int(0);
	//create an array object on the heap
	int * ages = new int[5];
	//pass a heap instantiated object to a funtion

	delete age;
	delete[] ages;

	return 0;
}

int* zeroArray(int size)
{
	int* arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = 0;
	}

	return arr;

}

int* duplicateArray(int* arr, size_t size)
{

	int* newArr = new int[size];

	for (int i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
		std::cout << newArr[i] << std::endl;
	}

	return newArr;
	delete[] newArr;
}

void love()
{
	int length;
	std::cout << "How many numbers are you going to feed me?";
	std::cin >> length;
	int* arr = new int[length];
	for (size_t i = 0; i < length; i++)
	{
		
		std::cout << "FEEEEED MEEE!" << std::endl;
		std::cin >> arr[i];

		
	}
	std::cout << "You fed me ";
	for (size_t i = 0; i < length; i++)
	{

		std::cout << arr[i] << " ";
	}
		int input = -1;
		std::cin >> input;	
	
}

player* randomizePlayers(int length)
{
	player* group = new player[length];

	for (size_t i = 0; i < length; i++)
	{
		group[i].ATK = rand() % 99 + 1;
		group[i].DEF = rand() % 99 + 1;
		group[i].EXP = rand() % 99 + 1;

		
		/* //Generate a random inventory
		for (size_t j = 0; j < 3; j++)
		{
			switch (rand() % 3)
			{
			case 0:
				group[i].inv[j].id = 1;
				group[i].inv[j].value = 10;
				break;
			case 1:
				group[i].inv[j].id = 2;
				group[i].inv[j].value = 5;
				break;
			case 2:
				group[i].inv[j].id = 3;
				group[i].inv[j].value = 1;
				break;
			}
		}
		*/
		
	}
	return group;
	delete[] group;
	
}

void printPlayer(player player)
{
	std::cout << "ATK: " << player.ATK << " DEF: " << player.DEF << " EXP: " << player.EXP << std::endl;
	std::cout << "Inventory:" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "[" << player.inv[i].id << "] ";
		
	}
	std::cout << std::endl;
}

bool addItem(player * recepient, item gift)
{
	(*recepient).inv[0] = gift;
	return true;
}