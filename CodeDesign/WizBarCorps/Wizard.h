#pragma once

//Wizard.h
#include <iostream>
#include "raylib.h"
class Wizard
{
public:
	Wizard();           // sets default values
	~Wizard();

	std::string name;
	int mana = 50;
	bool enabled = false;
	int gold;

	Vector2 position;
	Texture2D sprite = LoadTexture("resources//wizard.png");

	void draw();        // call this in your draw loop to render the wizard
};