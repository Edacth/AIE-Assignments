#include "Ninja.h"

Ninja::Ninja()
{
	position = {0, 0};

}

Ninja::Ninja(int _x, int _y)
{
	position.x = _x;
	position.y = _y;

}


Ninja::~Ninja()
{
}

void Ninja::update()
{
	position.x += 1;
}

void Ninja::render()
{
	DrawRectangleV(position, {10, 10}, BLACK);
}