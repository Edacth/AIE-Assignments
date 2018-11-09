//FallingFactory.h
#pragma once
#include "raylib.h"
#include "SimpleSprite.h"
#include "FallingObject.h"

class FallingFactory
{
private:
	FallingFactory();
	~FallingFactory();
	static FallingObject* spriteMasters;
	static Texture2D* textureMasters;
	static size_t spriteCount;

public:
	static void init();
	static FallingFactory& GetInstance();
	static FallingObject * GetRandom();// returns a random sprite from all sprites loaded
	static FallingObject * GetFromType(const std::string & _sprType);// Returns a random sprite from this type of sprites.
	static FallingObject* Create(std::string _sprType);

};