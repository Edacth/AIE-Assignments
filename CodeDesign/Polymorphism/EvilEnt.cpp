#include "EvilEnt.h"



EvilEnt::EvilEnt(const std::string & fileName, int _x, int _y) : Enemy(fileName, _x, _y)
{

}


EvilEnt::~EvilEnt()
{

}

bool EvilEnt::Update(Vector2 _destination)
{
	destination = _destination;
	direction.x = position.x - destination.x;
	direction.y = position.y - destination.y;
	if (direction.x != 0)
	{
		direction.x /= abs(direction.x);
	}
	if (direction.y != 0)
	{
		direction.y /= abs(direction.y);
	}

	position.x = position.x - direction.x * speed;
	position.y = position.y - direction.y * speed;
	return true;
}
