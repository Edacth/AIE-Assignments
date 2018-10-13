#pragma once
#include <iostream>
#include "raylib.h"

class Wizard;

class Corpse
{
public:
	Corpse();           // sets default values
	Corpse(Wizard wiz);
	~Corpse();

	std::string name;
	bool enabled = false;
	int gold;

	Vector2 position;
	Texture2D sprite = LoadTexture("resources//corpse.png");

	void draw();      
};