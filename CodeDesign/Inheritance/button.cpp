#include "raylib.h"
#include "button.h"

Button::Button(const std::string filename, const  int _cellCount, int _x, int _y)
{
	cellCount = _cellCount;
	spriteCells = new Texture2D[cellCount];
	//const char* fileExtension = ".png";
	//const char* filePath = "resources//";
	std::string fileExtension = ".png";
	std::string filePath = "resources\\";
	


	for (int i = 0; i < cellCount; i++)
	{
		std::string fullPath = (filePath + filename.c_str() + std::to_string(i + 1) + fileExtension).c_str();
		spriteCells[i] = LoadTexture(fullPath.c_str());
	}
	width = spriteCells[0].width;
	height = spriteCells[0].height;
	x = _x;
	y = _y;
}

void Button::Draw()
{
	if ( (CheckCollisionPointRec(GetMousePosition(), *this) ) && IsMouseButtonDown(MOUSE_LEFT_BUTTON))
	{
		DrawTexture(spriteCells[2], x, y+4, WHITE);
	}
	else if (CheckCollisionPointRec(GetMousePosition(), *this))
	{
		DrawTexture(spriteCells[1], x, y, WHITE);
	}
	else if (true)
	{
		DrawTexture(spriteCells[0], x, y, WHITE);
	}
	
}

Button::~Button()
{

};