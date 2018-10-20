//Item.h
#pragma once
#include <iostream>
#include <string>

class Item
{
public:
	Item(const std::string & _name, const std::string & _fluff = "", int  _cost = 1, const float _quality = 1);

	std::string name;
	int cost = 0;
	float quality = 1;
	std::string fluff;
};