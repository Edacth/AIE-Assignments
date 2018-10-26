#pragma once
#include "raylib.h"
class projectile
{
	Vector2 position;
public:
	projectile();
	projectile(Color _color);
	~projectile();

	void draw();
	void update();
	Color color;
	
};

