#pragma once

//Player.h
#pragma once
#include "raylib.h"
#include <iostream>
class Player
{
public:
	Vector2 position = { 100,100 };
	Vector2 destination = position;
	float speed = 0;
	Texture2D mySprite;
	bool virtual moveTo();
	Player(const std::string & fileName);//assign the sprite image.
	~Player();
	void Draw();
};