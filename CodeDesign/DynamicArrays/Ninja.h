#pragma once
#include <iostream>
#include "raylib.h"
class Ninja
{
public:
	Vector2 position = { 100,100 };

	Ninja();
	Ninja(int _x, int _y);
	~Ninja();
	void update();

	void render();
};

