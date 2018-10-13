#include <iostream>
#include "references.h"

void product(float a, float b, float& product)
{
	product = a * b;
}

void swap(float &a, float &b)
{
	float temp;
	temp = a;
	a = b;
	b = temp;
}

void feedAussie(Aussiegochi& aus)
{
	aus.hunger += 10;
}

void printAussie(Aussiegochi& aus)
{
	std::cout << "------------------" << std::endl;
	std::cout << "Happiness: " << aus.happiness << std::endl;
	std::cout << "Hunger: " << aus.hunger << std::endl;
	std::cout << "Thirst: " << aus.thirst << std::endl;
	std::cout << "Sanity: " << aus.sanity << std::endl;
	std::cout << "------------------" << std::endl;
}

void enterShadowForm(Aussiegochi& aus)
{
	aus.sanity = 0;
}

void coddleAussie(Aussiegochi& aus)
{
	aus.sanity += 10;
}