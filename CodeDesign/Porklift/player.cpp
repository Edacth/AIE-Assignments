#include "player.h"
#include "tile.h"

player::player()
{
}

player::player(Vector2 _position)
{
	position = _position;
	rectangle.x = position.x;
	rectangle.y = position.y;
}

player::player(const Texture2D _texture, Vector2 _position, std::vector<tile*>* _tiles)
{
	texture = _texture;
	position = _position;
	rectangle.x = position.x;
	rectangle.y = position.y;
	rectangle.height = texture.height * 8;
	rectangle.width = texture.width * 8;
	tilesPtr = _tiles;
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
}

void player::draw()
{
	DrawTextureEx(texture, position, 0.0f, 8.0f, WHITE);
}