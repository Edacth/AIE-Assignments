//FallingFactory.h
#pragma once
#include "raylib.h"
#include "SimpleSprite.h"

class FallingFactory
{
	static SimpleSprite* spriteMasters;
	static size_t spriteCount;

public:
	static void init();
	static FallingFactory& GetInstance();
	static SimpleSprite * getRandom();// returns a random sprite from all sprites loaded
	static SimpleSprite * getFromType(const std::string & _sprType);// Returns a random sprite from this type of sprites.

private:
	FallingFactory();
	~FallingFactory();
};