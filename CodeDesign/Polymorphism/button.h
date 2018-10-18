#pragma once
#include <string>

class Button : Rectangle
{
public:
	//Variables
	Texture2D * spriteCells = NULL;
	float frameRate = 25.0;
	int frameCount = 0;
	int direction = 1;
	int cellCount = 1;
	int buttonState = 0;
	int Update();
	void Draw();

	//Constructor
	Button(const std::string filename, const  int cellCount, int _x, int _y);
	Button();
	~Button();
};