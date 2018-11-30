#include "fork.h"
#include "player.h"
#include <string>


fork::fork()
{
}

fork::fork(const Texture2D _texture, player* _playerPtr)
{
	texture = _texture;
	playerPtr = _playerPtr;
	positionOffset = { 70, 100 };
	objectType = Player;
}

fork::fork(const Texture2D _texture, player* _playerPtr, std::vector<tile*>* _tiles, std::vector<GameObject*>* _gameObjects)
{
	texture = _texture;
	playerPtr = _playerPtr;
	gameObjectsPtr = _gameObjects;
	position.x = (*playerPtr->getPosition()).x + positionOffset.x;
	position.x = (*playerPtr->getPosition()).y + positionOffset.y;
	rectangle.x = position.x;
	rectangle.y = position.y;
	rectangle.height = 1 * 8;
	rectangle.width = 5 * 8;
	positionOffset = { 112, 60};
	objectType = Player;
	tilesPtr = _tiles;
}

fork::~fork()
{
}

void fork::update()
{
	//40 bottom bound
	//104 top bound
	if (IsKeyDown(KEY_W))
	{

		bool collision = false;
		rectangle.y -= 1;
		for (size_t j = 0; j < tilesPtr->size(); j++)
		{
			if (CheckCollisionRecs(rectangle, *(*(*tilesPtr)[j]).getRectangle()))
			{
				collision = true;
				
			}
		}

		if (!collision && positionOffset.y > 0)
		{
			positionOffset.y -= 1;

			for (size_t j = 0; j < gameObjectsPtr->size(); j++)
			{
				if ((*(*gameObjectsPtr)[j]).objectType == Crate)
				{
					if ((CheckCollisionRecs(rectangle, *(*(*gameObjectsPtr)[j]).getRectangle())))

					{

						(*(*gameObjectsPtr)[j]).push({ 0, -1 });
					}
				}

			}
		}

		
		
	}
	if (IsKeyDown(KEY_S))
	{
		/*Detects if the arm starts inside a crate*/
		bool startedColliding = false;
		for (size_t j = 0; j < gameObjectsPtr->size(); j++)
		{
			if ((*(*gameObjectsPtr)[j]).objectType == Crate)
			{
				if ((CheckCollisionRecs(rectangle, *(*(*gameObjectsPtr)[j]).getRectangle())))

				{

					startedColliding = true;
				}
			}

		}

		/*Detect if the arm will collide with a tile*/
		bool collision = false;
		rectangle.y += 1;
		for (size_t j = 0; j < tilesPtr->size(); j++)
		{
			if (CheckCollisionRecs(rectangle, *(*(*tilesPtr)[j]).getRectangle()))
			{
				collision = true;
				DrawText("True", 10, 10, 20, BLACK);
			}
		}
		/*Detects if the arm will collide with the top of a crate*/
		for (size_t j = 0; j < gameObjectsPtr->size(); j++)
		{
			if ((*(*gameObjectsPtr)[j]).objectType == Crate && startedColliding == false)
			{
				if ((CheckCollisionRecs(rectangle, *(*(*gameObjectsPtr)[j]).getRectangle())))

				{

					collision = true;
					DrawText("True", 10, 10, 20, BLACK);
				}
			}

		}


		for (size_t j = 0; j < gameObjectsPtr->size(); j++)
		{
			if ((*(*gameObjectsPtr)[j]).objectType == Crate)
			{
				if ((CheckCollisionRecs(rectangle, *(*(*gameObjectsPtr)[j]).getRectangle())))

				{

					if (!(*(*gameObjectsPtr)[j]).push({ 0, 1 }))
					{
						collision = true;
					}
				}
			}

		}

		if (!collision && positionOffset.y < 80)
		{
			positionOffset.y += 1;

			
		}
		
	}

	/*Detects if the player has moved and pushes boxes if so*/
	if (position.x != (*playerPtr->getPosition()).x + positionOffset.x)
	{
		
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = 0; j < gameObjectsPtr->size(); j++)
			{
				if ((*(*gameObjectsPtr)[j]).objectType == Crate)
				{
					if ((CheckCollisionRecs(rectangle, *(*(*gameObjectsPtr)[j]).getRectangle())) 
						&& !(*(*gameObjectsPtr)[j]).isGrounded())
					{
						if ( (position.x - ((*playerPtr->getPosition()).x + positionOffset.x)) < 0)
						{
							(*(*gameObjectsPtr)[j]).push({ 1, 0 });
						}
						else
						{
							(*(*gameObjectsPtr)[j]).push({ -1, 0 });
						}

					}
				}

			}
		}
	}

	position.x = (*playerPtr->getPosition()).x + positionOffset.x;
	position.y = (*playerPtr->getPosition()).y + positionOffset.y;

	rectangle.x = position.x;
	rectangle.y = position.y;
}

void fork::draw()
{
	DrawTextureEx(texture, { position.x, position.y - 15 * 8 }, 0.0f, 8.0f, WHITE);
	DrawText(std::to_string((position.x - ((*playerPtr->getPosition()).x + positionOffset.x))).c_str(), 10, 10, 20, BLACK);

	//DrawText(std::to_string(positionOffset.x).c_str(), 10, 10, 20, BLACK);
	//DrawText(std::to_string(positionOffset.y).c_str(), 10, 30, 20, BLACK);

	//DrawLineEx({ rectangle.x, rectangle.y }, { rectangle.x + rectangle.width, rectangle.y}, 2.0f, RED);
	//DrawLineEx({ rectangle.x, rectangle.y + rectangle.height }, { rectangle.x + rectangle.width, rectangle.y + rectangle.height }, 2.0f, RED);
}