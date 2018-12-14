#undef PI
#include "utils.h"
#include "player.h"
#include <string>


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

	int rise = (mousePos.y - (rectangle.y + (rectangle.height / 2.0f)));
	int run = (mousePos.x - (rectangle.x + (rectangle.width / 2.0f)));
	angle = (atan2(rise, run));
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
	vec2 normDirectionToCursor = directionToCursor.getNormalised();
	float rot = -atan2(normDirectionToCursor.x, normDirectionToCursor.y);
	DrawText(std::to_string(rot).c_str(), 30, 30, 20, BLACK);
	DrawText(std::to_string(rot * cMath::RAD_TO_DEG).c_str(), 30, 50, 20, BLACK);

	float sin = directionToCursor.y / directionToCursor.magnitude();
	
	DrawLineV(position, (position + directionToCursor.normalise().scale(80)), RED);
	DrawLineV(position, (position + directionToCursor.normalise().scale(80)), GREEN);
	DrawRectanglePro({position.x, position.y, rectangle.width, rectangle.height}, { rectangle.height / 2.0f, rectangle.width / 2.0f }, rot * cMath::RAD_TO_DEG, BLUE);
}