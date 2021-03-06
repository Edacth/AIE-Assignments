#include "player.h"

player::player()
{
}

player::player(vec2 _position)
{
	position = _position;
	rectangle.x = position.x;
	rectangle.y = position.y;
	speed = 100.0;
}

player::player(vec2 _position,  std::vector<GameObject*>* _gameObjects)
{
	position = _position;
	rectangle.x = position.x;
	rectangle.y = position.y;
	rectangle.height = 30;
	rectangle.width = 30;
	gameObjectsPtr = _gameObjects;
	speed = 100.0;
}

player::~player()
{
}

void player::update()
{
	directionToCursor = position - GetMousePosition();
	if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
	{
		//position += -directionToCursor.getNormalised() * speed * GetFrameTime();
		position = moveTowards(position, GetMousePosition(), speed * GetFrameTime());
	}

	/*
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
	*/
}

void player::draw()
{
	DrawRectangleV(position, {rectangle.height, rectangle.width}, BLUE);
}