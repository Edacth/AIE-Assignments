#include "Player.h"

Player::Player(const std::string & fileName)
{
	mySprite = LoadTexture(fileName.c_str());

}

Player::~Player()
{

}

bool Player::moveTo()
{
	return true;
}

void Player::Draw()
{
	DrawTextureV(mySprite, position, WHITE);
}