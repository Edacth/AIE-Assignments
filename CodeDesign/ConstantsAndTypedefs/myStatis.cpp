//myStasis.cpp
#include "myStatis.h"
#include <iostream>
int myStatis::petShop;
void myStatis::goWest()
{
	static int callMe = 0;
	std::cout << myName.c_str() << ".callMe=" << callMe++ << std::endl;
}
void myStatis::petShopBoys() {
	std::cout << "petShop=" << petShop++ << std::endl;
}