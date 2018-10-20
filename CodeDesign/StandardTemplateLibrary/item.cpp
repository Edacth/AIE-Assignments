//Item.cpp
#include "Item.h"
Item::Item(const std::string & _name, const std::string &_fluff, const int _cost, const float  _quality)
{
	name = _name;
	cost = _cost;
	quality = _quality;
	fluff = _fluff;
}