#include "sprite.h"

Sprite::Sprite(const std::string filename, const  int _cellCount, const float _frameRate)
{
	cellCount = _cellCount;
	spriteCells = new Texture2D[cellCount];
	//const char* fileExtension = ".png";
	//const char* filePath = "resources//";
	std::string fileExtension = ".png";
	std::string filePath = "resources\\";
	
	

	for (int i = 0; i < cellCount; i++)
	{
		std::string fullPath = (filePath + filename.c_str() + std::to_string(i+1) + fileExtension).c_str();
		spriteCells[i] = LoadTexture( fullPath.c_str() );
	}
	frameRate = _frameRate;

	x = 100;
	y = 100;
}

void Sprite::Draw()
{
	frameCount++;
	if (((frameCount / (60 / (int)frameRate )) % 2) == 1)
	{
		cellToDraw++;
		if (cellToDraw > cellCount - 1)
		{
			cellToDraw = 0;
		}
		frameCount = 0;
	}
	DrawTexture(spriteCells[cellToDraw], x, y, WHITE);
}

Sprite::~Sprite()
{

}