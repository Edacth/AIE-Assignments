#include "SimpleSprite.h"



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