#pragma once
#include "raylib.h"
#include <iostream>
#include <string>
class Enemy
{
public:
	Vector2 position = { 100,100 };
	Vector2 destination = position;
	Vector2 direction = {0, 0};
	float speed = 0;
	Texture2D mySprite;
	bool virtual Update(Vector2 _destination);
	Enemy(const std::string & fileName, int _x, int _y);
	~Enemy();
	void Draw();
};

