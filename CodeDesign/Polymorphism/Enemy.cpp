#include "Enemy.h"



Enemy::Enemy(const std::string & fileName, int _x, int _y)
{
	mySprite = LoadTexture(fileName.c_str());
	position.x = _x;
	position.y = _y;

}

bool Enemy::Update(Vector2 _destination)
{
	
	return true;
}

Enemy::~Enemy()
{
}

void Enemy::Draw()
{
	DrawTextureV(mySprite, position, WHITE);
}