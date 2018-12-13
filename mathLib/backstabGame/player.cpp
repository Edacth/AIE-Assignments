#include "player.h"
#include <string>;

player::player()
{
}

player::player(vec2 _position)
{
	position = _position;
	rectangle.x = position.x;
	rectangle.y = position.y;
	speed = 50.0;
}

player::player(vec2 _position,  std::vector<GameObject*>* _gameObjects)
{
	position = _position;
	rectangle.x = position.x;
	rectangle.y = position.y;
	rectangle.height = 30;
	rectangle.width = 30;
	gameObjectsPtr = _gameObjects;
	speed = 50.0;
}

player::~player()
{
}

void player::update()
{
	mousePos = GetMousePosition();
	directionToCursor = mousePos - position;
	/*
	if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
	{
		//position += -directionToCursor.getNormalised() * speed * GetFrameTime();
		//position = moveTowards(position, GetMousePosition(), speed * GetFrameTime());
	}
	*/

	
	if (IsKeyDown(KEY_A))
	{
		for (size_t i = 0; i < 3; i++)
		{
			position.x -= 1;

		}
	}
	if (IsKeyDown(KEY_D))
	{
		for (size_t i = 0; i < 3; i++)
		{
			position.x += 1;

		}
	}
	if (IsKeyDown(KEY_W))
	{
		for (size_t i = 0; i < 3; i++)
		{
			position.y -= 1;

		}
	}
	if (IsKeyDown(KEY_S))
	{
		for (size_t i = 0; i < 3; i++)
		{
			position.y += 1;

		}
	}
	
}

void player::draw()
{
	float sin = directionToCursor.y / directionToCursor.magnitude();
	DrawText(std::to_string(sin).c_str(), 30, 30, 20, BLACK);
	DrawLineV(position, (position + directionToCursor.normalise().scale(40)), RED);
	DrawRectangleV(position, {rectangle.height, rectangle.width}, BLUE);
}