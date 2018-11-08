//SpriteFactory.cpp
#include "SpriteFactory.h"
SimpleSprite* SpriteFactory::Create(std::string type)
{
	

	return NULL;
}

SpriteFactory::SpriteFactory()
{

}

SpriteFactory::~SpriteFactory()
{

}

SpriteFactory& SpriteFactory::GetInstance()
{
	static SpriteFactory instance;
	return instance;
}

