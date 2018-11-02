#include "Player.h"



Player::Player()
{
}

Player::Player(Texture _sprite, Vector2 _position)
{
	sprite = _sprite;
	position = _position;
}


Player::~Player()
{
}

void Player::draw()
{
	//DrawTextureV(sprite, position, WHITE);
	DrawTextureEx(sprite, position, 0, 3.0, WHITE);

}