#pragma once
#include "raylib.h"
#undef PI;
#include "utils.h"
#include "vec2.h"

class healthBar
{
public:
	vec2 position;
	float t;
	healthBar();
	healthBar(vec2 _position);
	~healthBar();
	void update(int health, int maxHealth);
	void draw();
};