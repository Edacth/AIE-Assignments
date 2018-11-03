#pragma once
#include "raylib.h"
#include "player.h"
#include <math.h>

class Projectile
{
private:
	Player* target;
	Vector2 position;
	Vector2 dir;
	Vector2 dirNorm;
	int dirLength;
	Texture sprite;

public:
	Projectile();
	Projectile(Texture _sprite, Vector2 _position, Vector2 _dir);
	~Projectile();

	//Funtions
	void draw();
	void setTarget(Player* _target);
	void update();
};

