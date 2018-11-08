#include "SimpleSprite.h"

SimpleSprite::SimpleSprite(const std::string & filename, const std::string _sprType, float _scale)
{
	sprType = _sprType;
	texture = LoadTexture(filename.c_str());
	scale = _scale;
}

SimpleSprite::SimpleSprite()
{
}


SimpleSprite::~SimpleSprite()
{
}

void SimpleSprite::draw()
{
	DrawTexturePro(texture, r1, r1, pos, rot, WHITE);
	
}