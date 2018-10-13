#include <iostream>
#include "references.h"

int main()
{
	int myVal = 22;

	/*
	//Reference to myVal
	int& myRef = myVal;
	std::cout << myVal << std::endl;
	std::cout << myRef << std::endl;

	myVal = 2;
	std::cout << myVal << std::endl;
	std::cout << myRef << std::endl;
	//Whenever you change the variable or the
	//	reference, then it changes the same value.
	myRef = 3;
	std::cout << myVal << std::endl;
	std::cout << myRef << std::endl;


	// variables
	int num = 0;
	float dec = 0.0f;
	bool tf = false;
	char letter = 'a';

	// references to said variables
	int& numRef = num;  // a reference to an int
	float& decRef = dec;
	bool& tfRef = tf;
	char letterRef = letter;
	*/

	/*
	float a = 3.0;
	float b = 1.5;
	float productVal = -1.0;
	float& productRef = productVal;
	product( a,  b, productRef);

	//std::cout << productRef << std::endl;

	swap(a, b);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	*/
	Aussiegochi timmy = { 100, 50 , 50, 100 };
	Aussiegochi& timmyRef = timmy;
	printAussie(timmyRef);

	feedAussie(timmyRef);
	printAussie(timmyRef);

	enterShadowForm(timmy);
	printAussie(timmyRef);

	coddleAussie(timmy);
	printAussie(timmyRef);

	return 0;
}