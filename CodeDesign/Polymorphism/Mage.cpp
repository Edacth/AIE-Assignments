#include "Mage.h"



Mage::Mage(const std::string & fileName) : Player(fileName)
{

}


Mage::~Mage()
{
}

bool Mage::moveTo()
{
	position = destination;
	return true;
}