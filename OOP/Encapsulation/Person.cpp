#include <iostream>
#include "Person.h"

void Person::Greet()
{
	std::cout << "Hey there!" << std::endl;
}

int Person::getAge()
{
	return age;
}
void Person::setAge(int a)
{
	age = a;
}
int Person::getPoundCake()
{
	return poundCake;
}
