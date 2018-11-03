#include "projectile.h"

Projectile::Projectile()
{
}

Projectile::Projectile(Texture _sprite, Vector2 _position, Vector2 _dir)
{
	sprite = _sprite;
	position = _position;
	dir = _dir;
	dirNorm = { 0,0 };
	dirLength = 0.0;
}


Projectile::~Projectile()
{
}

void Projectile::update()
{
	
		position.x += dir.x * 2;
		position.y += dir.y * 2;
	
	/*else if (target != nullptr)
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
	}*/

}

void Projectile::draw()
{
	DrawTextureEx(sprite, position, 0, 3.0, WHITE);
	//DrawRectangleV(position, { 10, 10 }, BLUE);
}