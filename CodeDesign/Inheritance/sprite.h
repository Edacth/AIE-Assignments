#pragma once
#include "raylib.h"
#include <iostream>
#include <string>

class Sprite : public Vector2
{
public:
	//Variables
	Texture2D* spriteCells = NULL;
	float frameRate = 25.0;
	int frameCount = 0;
	int direction = 1;
	int cellCount = 1;
	int cellToDraw = 0;

	void Draw();

	//Constructor
	Sprite(const std::string filename, const  int cellCount = 1, const float _frameRate = 25.0);
	Sprite();
	~Sprite();
};