#include "tile.h"
#include <string>
#include <random>
#include <ctime>

Tile::Tile()
{
	*Background = LoadTexture("resources//mapTile_188.png");
	srand(time(NULL));
	int rand = (std::rand() % 255);
	*tint = WHITE;
	tint->a = rand;
}

Tile::Tile(std::string _imageFilename)
{
	*imageFilename = _imageFilename;
	std::string filePath = "resources//" + *imageFilename;
	*Background = LoadTexture(filePath.c_str());
	*tint = WHITE;
}

Tile::~Tile()
{

}

Tile & Tile::operator = (const Tile& rhs)
{
	
	Background =  rhs.Background;
	imageFilename = rhs.imageFilename;

	return *this;
}

Tile & Tile::operator = (const std::string* _imageFilename)
{
	*imageFilename = *_imageFilename;
	std::string filePath = "resources//" + *imageFilename;
	*Background = LoadTexture(filePath.c_str());

	return *this;
}
