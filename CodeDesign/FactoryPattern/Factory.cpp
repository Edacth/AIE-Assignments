//Factory.cpp
#include "Factory.h"
IBox* Factory::Create(std::string type)
{
	if (type == "Red")
		return new RedBox();

	if (type == "Blue")
		return new BlueBox();

	return NULL;
}

Factory::Factory() 
{

}

Factory::~Factory()
{

}

Factory& Factory::GetInstance()
{
	static Factory instance;
	return instance;
}

