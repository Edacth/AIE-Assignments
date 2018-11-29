#include "crate.h"

crate::crate()
{
}

crate::crate(Texture _texture, Vector2 _positon, std::vector<tile*>* _tiles, std::vector<GameObject*>* _gameObjects)
{
	texture = _texture;
	position = _positon;
	rectangle.x = position.x;
	rectangle.y = position.y;
	rectangle.height = 7 * 8;
	rectangle.width = 7 * 8;
	tilesPtr = _tiles;
	objectType = Crate;
}

crate::~crate()
{
}

void crate::update()
{
	for (size_t i = 0; i < 3; i++)
	{
		bool verticalCollision = false;
		rectangle.y += 1;
		for (size_t i = 0; i < tilesPtr->size(); i++)
		{
			if (CheckCollisionRecs(rectangle, *(*(*tilesPtr)[i]).getRectangle()))
			{
				verticalCollision = true;
			}
		}

		if (!verticalCollision)
		{
			position.y += 1;
		}

	}

	rectangle.y = position.y;
}

void crate::draw()
{
	DrawTextureEx(texture, { position.x, position.y - 10 * 7 }, 0.0f, 8.0f, WHITE);
	DrawLineEx({ rectangle.x, rectangle.y }, { rectangle.x + rectangle.width, rectangle.y }, 2.0f, RED);
	DrawLineEx({ rectangle.x, rectangle.y + rectangle.height }, { rectangle.x + rectangle.width, rectangle.y + rectangle.height }, 2.0f, RED);
}

bool crate::push(Vector2 direction)
{
	bool horizontalCollision = false;
	rectangle.x += direction.x;
	rectangle.y += direction.y;

	for (size_t j = 0; j < tilesPtr->size(); j++)
	{
		if ((CheckCollisionRecs(rectangle, *(*(*tilesPtr)[j]).getRectangle())))
		{
			horizontalCollision = true;
		}
	}

	if (!horizontalCollision)
	{
		position.x = rectangle.x;
	}
	
	rectangle.y = position.y;

	return true;
}