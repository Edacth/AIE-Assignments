#include "player.h"


player::player()
{
}

player::player(Vector2 _position)
{
	position = _position;
	rectangle.x = position.x;
	rectangle.y = position.y;
	objectType = Player;
}

player::player(const Texture2D _texture, const Texture2D _forkTexture, Vector2 _position, std::vector<tile*>* _tiles, std::vector<GameObject*>* _gameObjects)
{
	texture = _texture;
	position = _position;
	rectangle.x = position.x;
	rectangle.y = position.y;
	rectangle.height = 11 * 8;
	rectangle.width = 14 * 8;
	tilesPtr = _tiles;
	gameObjectsPtr = _gameObjects;
	myFork = fork{ _forkTexture, this, _tiles, _gameObjects };
	objectType = Player;
	gameObjectsPtr->push_back(&myFork);
}

player::~player()
{
}

void player::update()
{
	if (IsKeyDown(KEY_A))
	{
		for (size_t i = 0; i < 3; i++)
		{
			bool horizontalCollision = false;
			rectangle.x -= 1;
			for (size_t j = 0; j < tilesPtr->size(); j++)
			{
				if (CheckCollisionRecs(rectangle, *(*(*tilesPtr)[j]).getRectangle()) ||
					(CheckCollisionRecs(*myFork.getRectangle(), *(*(*tilesPtr)[j]).getRectangle())))
				{
					horizontalCollision = true;
				}
			}

			for (size_t j = 0; j < gameObjectsPtr->size(); j++)
			{
				if ((*(*gameObjectsPtr)[j]).objectType == Crate)
				{
					if ((CheckCollisionRecs(rectangle, *(*(*gameObjectsPtr)[j]).getRectangle())))

					{
						horizontalCollision = true;
						if ((*(*gameObjectsPtr)[j]).push({ -1, 0 }))
						{
							horizontalCollision = false;
						}
					}
				}

			}

			if (!horizontalCollision)
			{
				position.x -= 1;
			}
		}
	}
	if (IsKeyDown(KEY_D))
	{
		for (size_t i = 0; i < 3; i++)
		{
			bool horizontalCollision = false;
			rectangle.x += 1;
			((*myFork.getRectangle()).x) += 1;
			for (size_t j = 0; j < tilesPtr->size(); j++)
			{
				if ( (CheckCollisionRecs(rectangle, *(*(*tilesPtr)[j]).getRectangle())) ||
					(CheckCollisionRecs(*myFork.getRectangle(), *(*(*tilesPtr)[j]).getRectangle())))
					
				{
					horizontalCollision = true;
				}
			}

			for (size_t j = 0; j < gameObjectsPtr->size(); j++)
			{
				if ((*(*gameObjectsPtr)[j]).objectType == Crate)
				{
					if ((CheckCollisionRecs(rectangle, *(*(*gameObjectsPtr)[j]).getRectangle())))

					{
						horizontalCollision = true;
						if ((*(*gameObjectsPtr)[j]).push({ 1, 0 }))
						{
							horizontalCollision = false;
						}
					}
				}
				
			}

			if (!horizontalCollision)
			{
				position.x += 1;
			}
		}
	}
	rectangle.x = position.x;
	((*myFork.getRectangle()).x) = ((*myFork.getPosition()).x);

	for (size_t i = 0; i < 3; i++)
	{
		bool verticalCollision = false;
		rectangle.y += 1;
		for (size_t i = 0; i < tilesPtr->size(); i++)
		{
			if (CheckCollisionRecs(rectangle, *(*(*tilesPtr)[i]).getRectangle() ))
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
	//myFork.setPosition({position.x+80, position.y});
	//myFork.update();
}

void player::draw()
{
	DrawTextureEx(texture, position, 0.0f, 8.0f, WHITE);
	//myFork.draw();
}