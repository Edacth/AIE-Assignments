#include "tile.h"

tile::tile()
{
}

tile::tile(const Texture2D _texture, Vector2 _position)
{
	texture = _texture;
	position = _position;
	rectangle.x = position.x;
	rectangle.y = position.y;
	rectangle.height = texture.height * 8;
	rectangle.width = texture.width * 8;
}

tile::~tile()
{
}

void tile::update()
{
}

void tile::draw()
{
	DrawTextureEx(texture, position, 0.0f, 8.0f, WHITE);
}