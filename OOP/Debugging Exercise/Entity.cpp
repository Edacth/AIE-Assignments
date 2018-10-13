#include "Entity.h"



Entity::Entity()
{
}


Entity::~Entity()
{
}

bool Entity::isAlive()
{
	if (health <= 0)
	{
		return false;
	}
	return true;
}

int Entity::getAttack()
{
	return attackValue;
}

void Entity::takeDamage(int damage)
{
	health -= damage;
}