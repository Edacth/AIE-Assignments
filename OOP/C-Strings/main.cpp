#include <iostream>
#include "C-String.h"

int main()
{
	/*
	char name[20];
	std::cout << "What is your name?" << std::endl;
	std::cin.getline(name, 50);

	std::cout << name << std::endl;
	*/

	/*
	char string1[20];
	char string2[20];
	
	std::cout << "Tell me something." << std::endl;
	std::cin.getline(string1, 20);

	//topper(string, 20);
	//removeWhites(string);
	substring(string2, string1, 1, 5);

	std::cout << string2 << std::endl;
	*/
	char string1[100];
	char string2[100];

	std::cout << "Tell me something." << std::endl;
	std::cin.getline(string1, 100);

	shiftCipher(string2, string1, -1);

	std::cout << string2 << std::endl;

	return 0;

}
