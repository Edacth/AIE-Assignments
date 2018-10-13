#include <iostream>
#include "person.h"
#include "piggy.h"
#include "circle.h"




int main()
{
	person paul = {};
	person jon = {15, 1000, 20};
	//Passing structs
	//Printing structs

	//printPerson(jon);
	
	
	piggybank myBank = { 1, 1, 1, 1, 1, 1, 1 };
	deposit(myBank, 1, 0, 0, 0, 0, 0, 0);
	std::cout << calcPiggybankTotal(myBank);
	

	/*
	circle circle1 = { {-4, 5}, 2 };
	circle circle2 = { { 10, 0 }, 100 };

	std::cout << findCollision(circle1, circle2);
	*/
	return 0;
}

