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
	gameObjectsPtr = _gameObjects;
	objectType = Crate;
}

crate::~crate()
{
}

void crate::update()
{
	for (size_t i = 0; i < 3; i++)
	{
		

		if (!isGrounded())
		{
			position.y += 1;
		}

	}

	rectangle.y = position.y;
}

void crate::draw()
{
	DrawTextureEx(texture, { position.x, position.y - 10 * 7 }, 0.0f, 8.0f, WHITE);
	DrawRectangleV(position, { 5,5 }, BLUE);
	DrawLineEx({ rectangle.x, rectangle.y }, { rectangle.x + rectangle.width, rectangle.y }, 2.0f, RED);
	DrawLineEx({ rectangle.x, rectangle.y + rectangle.height }, { rectangle.x + rectangle.width, rectangle.y + rectangle.height }, 2.0f, RED);
}

bool crate::push(Vector2 direction)
{
	bool horizontalCollision = false;
	bool verticalCollision = false;
	rectangle.x += direction.x;
	rectangle.y += direction.y;

	if (direction.x != 0)
	{
		for (size_t j = 0; j < tilesPtr->size(); j++)
		{
			if ((CheckCollisionRecs(rectangle, *(*(*tilesPtr)[j]).getRectangle())))
			{
				horizontalCollision = true;
			}
		}

		for (size_t j = 0; j < gameObjectsPtr->size(); j++)
		{
			if ((*(*gameObjectsPtr)[j]).objectType == Crate && (*(*gameObjectsPtr)[j]).uuid != uuid)
			{
				if ((CheckCollisionRecs(rectangle, *(*(*gameObjectsPtr)[j]).getRectangle())))

				{
					horizontalCollision = true;
					(*(*gameObjectsPtr)[j]).push(direction);
				}
			}

		}

		if (!horizontalCollision)
		{
			position.x = rectangle.x;
		}

		rectangle.x = position.x;
	}
	else if (direction.y != 0)
	{
		for (size_t j = 0; j < tilesPtr->size(); j++)
		{
			if ((CheckCollisionRecs(rectangle, *(*(*tilesPtr)[j]).getRectangle())))
			{
				verticalCollision = true;
			}
		}

		for (size_t j = 0; j < gameObjectsPtr->size(); j++)
		{
			if ((*(*gameObjectsPtr)[j]).objectType == Crate && (*(*gameObjectsPtr)[j]).uuid != uuid)
			{
				if ((CheckCollisionRecs(rectangle, *(*(*gameObjectsPtr)[j]).getRectangle())))

				{
					//verticalCollision = true;
					(*(*gameObjectsPtr)[j]).push({ direction.x, direction.y * 2 });
					DrawText("Yup", 10, 10, 20, BLACK);
				}
			}

		}

		if (!verticalCollision)
		{
			position.y = rectangle.y;
		}

		rectangle.y = position.y;
	}

	return true;
}

bool crate::isGrounded()
{
	bool verticalCollision = false;
	rectangle.y += 1;
	for (size_t i = 0; i < tilesPtr->size(); i++)
	{
		if (CheckCollisionRecs(rectangle, *(*(*tilesPtr)[i]).getRectangle()))
		{
			//verticalCollision = true;
			return true;
		}
	}


	for (size_t j = 0; j < gameObjectsPtr->size(); j++)
	{
		if ((*(*gameObjectsPtr)[j]).objectType == Crate && (*(*gameObjectsPtr)[j]).uuid != uuid)
		{
			if ((CheckCollisionRecs(rectangle, *(*(*gameObjectsPtr)[j]).getRectangle())))

			{
				//verticalCollision = true;
				return true;
			}
		}

		if ((*(*gameObjectsPtr)[j]).objectType == Player)
		{
			if ((CheckCollisionRecs(rectangle, *(*(*gameObjectsPtr)[j]).getRectangle())))

			{
				//verticalCollision = true;
				return true;
			}
		}

	}
	return false;
}