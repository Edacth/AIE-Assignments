#include "player.h"


player::player()
{
}

player::player(Vector2 _position)
{
	position = _position;
	rectangle.x = position.x;
	rectangle.y = position.y;
}

player::player(const Texture2D _texture, const Texture2D _forkTexture, Vector2 _position, std::vector<tile*>* _tiles)
{
	texture = _texture;
	position = _position;
	rectangle.x = position.x;
	rectangle.y = position.y;
	rectangle.height = texture.height * 8;
	rectangle.width = 14 * 8;
	tilesPtr = _tiles;
	myFork = fork{ _forkTexture, this };
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
			bool collision = false;
			rectangle.x -= 1;
			for (size_t j = 0; j < tilesPtr->size(); j++)
			{
				if (CheckCollisionRecs(rectangle, (*(*tilesPtr)[j]).getRectangle()))
				{
					collision = true;
				}
			}

			if (!collision)
			{
				position.x -= 1;
			}
		}
	}
	if (IsKeyDown(KEY_D))
	{
		for (size_t i = 0; i < 3; i++)
		{
			bool collision = false;
			rectangle.x += 1;
			for (size_t j = 0; j < tilesPtr->size(); j++)
			{
				if (CheckCollisionRecs(rectangle, (*(*tilesPtr)[j]).getRectangle()))
				{
					collision = true;
				}
			}

			if (!collision)
			{
				position.x += 1;
			}
		}
	}

	for (size_t i = 0; i < 3; i++)
	{
		bool collision = false;
		rectangle.y += 1;
		for (size_t i = 0; i < tilesPtr->size(); i++)
		{
			if (CheckCollisionRecs(rectangle, (*(*tilesPtr)[i]).getRectangle() ))
			{
				collision = true;
			}
		}
		
		if (!collision)
		{
			position.y += 1;
		}
		
	}

	rectangle.x = position.x;
	rectangle.y = position.y;
	//myFork.setPosition({position.x+80, position.y});
	myFork.update();
}

void player::draw()
{
	DrawTextureEx(texture, position, 0.0f, 8.0f, WHITE);
	myFork.draw();
}