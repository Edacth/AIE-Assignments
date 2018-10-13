#include <iostream>
#include "dynamicMemory.h"
#include <ctime>

int main()
{
	srand(time(NULL));
	/*
	int* test = zeroArray(5);
	std::cout << test;
	*/
	int original[] = { 1, 2, 3, 4 };

	/* 
	int* dupe = duplicateArray(original, 4);
	std::cout << *(dupe+1);
	*/


	//LEARN HOW TO DELETE PROPERLY
	
	//love();
	item sword = { 1, 10 };
	item hat = { 2, 5 };
	item rock = { 3, 1 };

	player* group = randomizePlayers(5);

	addItem(&group[0], sword);

	printPlayer(group[0]);
	printPlayer(group[4]);
	
	return 0;
}