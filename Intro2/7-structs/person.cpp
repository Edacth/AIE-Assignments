#include "person.h"
#include <iostream>


void printPerson(person target)
{
	std::cout << "The age of this person is" << target.age << std::endl
		<< "The cash of this person is" << target.cash << std::endl
		<< "The points of this person is" << target.points << std::endl;
}