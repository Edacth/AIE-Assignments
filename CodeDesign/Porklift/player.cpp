#include "player.h"

player::player()
{
}

player::player(Vector2 _position)
{
	position = _position;
}

player::player(const Texture2D _texture, Vector2 _position)
{
	texture = _texture;
	position = _position;
}

player::~player()
{
}

void player::update()
{
	if (IsKeyDown(KEY_A))
	{
		position.x -= 1;
	}
	if (IsKeyDown(KEY_D))
	{
		position.x += 1;
	}
}

void player::draw()
{
	DrawTextureV(texture, position, WHITE);
}