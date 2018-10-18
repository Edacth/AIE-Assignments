#include "Barbarian.h"



Barbarian::Barbarian(const std::string & fileName) : Player(fileName)
{
	speed = 1;
}


Barbarian::~Barbarian()
{
}

bool Barbarian::moveTo()
{
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