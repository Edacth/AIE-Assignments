#include "fork.h"
#include "player.h"


fork::fork()
{
}

fork::fork(const Texture2D _texture, player* _playerPtr)
{
	texture = _texture;
	playerPtr = _playerPtr;
	positionOffset = { 80,0 };
}

fork::fork(const Texture2D _texture, Vector2 _position, std::vector<tile*>* _tiles)
{
	texture = _texture;
	position = _position;
	rectangle.x = position.x;
	rectangle.y = position.y;
	rectangle.height = texture.height * 8;
	rectangle.width = 14 * 8;
	tilesPtr = _tiles;
}

fork::~fork()
{
}

void fork::update()
{
	if (IsKeyDown(KEY_W))
	{
		positionOffset.y -= 1;
	}
	if (IsKeyDown(KEY_S))
	{
		positionOffset.y += 1;
	}
	position.x = playerPtr->getPosition().x + positionOffset.x;
	position.y = playerPtr->getPosition().y + positionOffset.y;
}

void fork::draw()
{
	DrawTextureEx(texture, position, 0.0f, 8.0f, WHITE);
}