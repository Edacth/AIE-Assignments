#include "projectile.h"


projectile::projectile()
{
	position = { 100, 100 };
	color = BLACK;
}

projectile::projectile(Color _color)
{
	position = { 100, 100 };
	color = _color;
}

projectile::~projectile()
{

}

void projectile::draw()
{
	DrawRectangleV(position, { 20, 20 }, color);
}

void projectile::update()
{
	position.x++;
}