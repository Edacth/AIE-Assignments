#pragma once
#include "raylib.h"
#include "player.h"


class Enemy
{
private:
	Player* target;
	Vector2 dir;
	Vector2 dirNorm;
	float dirLength;
	Texture sprite;

public:
	//Vars
	Vector2 position;

	//Constructors
	Enemy();
	Enemy(Texture _sprite, Vector2 _position);
	~Enemy();

	//Funtions
	void draw();
	void setTarget(Player* _target);
	void update();
};