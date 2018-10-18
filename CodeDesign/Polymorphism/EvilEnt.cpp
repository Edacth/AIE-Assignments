#include "EvilEnt.h"



EvilEnt::EvilEnt(const std::string & fileName, int _x, int _y) : Enemy(fileName, _x, _y)
{

}


EvilEnt::~EvilEnt()
{

}

bool EvilEnt::MoveTo()
{
	return true;
}
