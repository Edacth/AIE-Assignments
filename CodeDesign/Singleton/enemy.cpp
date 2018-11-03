#include "enemy.h"
#include <math.h>

Enemy::Enemy()
{
}

Enemy::Enemy(Texture _sprite, Vector2 _position)
{
	sprite = _sprite;
	position = _position;
	dir = { 0, 0 };
	dirNorm = { 0,0 };
	dirLength = 0.0;
}


Enemy::~Enemy()
{
}

void Enemy::draw()
{
	//DrawTextureV(sprite, position, WHITE);
	DrawTextureEx(sprite, position, 0, 3.0, WHITE);

}

void Enemy::update()
{
	if (target != nullptr)
	{


		dir.x = position.x - target->position.x;
		dir.y = position.y - target->position.y;
		dirLength = sqrt(pow(dir.x, 2) + pow(dir.y, 2));

		if (dir.x != 0)
		{
			dirNorm.x = dir.x / dirLength;
		}
		if (dir.y != 0)
		{
			dirNorm.y = dir.y / dirLength;
		}

		position.x -= dirNorm.x * 1;
		position.y -= dirNorm.y * 1;
	}
	
}

void Enemy::setTarget(Player* _target)
{
	target = _target;
}