#include "enemy.h"

enemy::enemy()
{
}

enemy::enemy(vec2 _position)
{
	position = _position;
	rectangle.x = position.x;
	rectangle.y = position.y;
}

enemy::enemy(vec2 _position, std::vector<GameObject*>* _gameObjects)
{
	position = _position;
	rectangle.x = position.x;
	rectangle.y = position.y;
	rectangle.height = 30;
	rectangle.width = 30;
	gameObjectsPtr = _gameObjects;
	lookDir = { 3, 2 };
}

enemy::~enemy()
{
}

void enemy::update()
{
	//position += lookDir.normalise();
}

void enemy::draw()
{
	DrawRectangleV(position, { rectangle.height, rectangle.width }, RED);
	DrawTriangle(position + lookDir, position + )
}