//FallingFactory.cpp
#include "FallingFactory.h"

size_t FallingFactory::spriteCount = NULL;
FallingObject* FallingFactory::spriteMasters = nullptr;
Texture2D* FallingFactory::textureMasters = nullptr;

void FallingFactory::init()
{
    //Load in the various sprites
    spriteCount = 4;
    spriteMasters = new FallingObject[spriteCount];
    //spriteMasters[0] = *(new FallingObject("resources/spaceMeteors_001.png", "rock", .1f));
    //spriteMasters[1] = *(new FallingObject("resources/spaceMeteors_002.png", "rock", .1f));
    //spriteMasters[2] = *(new FallingObject("resources/spaceMeteors_003.png", "rock", .1f));
    //spriteMasters[3] = *(new FallingObject("resources/spaceMeteors_004.png", "rock", .1f));

	textureMasters = new Texture2D[spriteCount];
	textureMasters[0] = LoadTexture("resources/spaceBuilding_007.png");
	textureMasters[1] = LoadTexture("resources/spaceBuilding_001.png");
	textureMasters[2] = LoadTexture("resources/spaceBuilding_003.png");
	textureMasters[3] = LoadTexture("resources/spaceBuilding_020.png");
}

FallingFactory::FallingFactory()
{
	init();
}

FallingFactory::~FallingFactory()
{
}

FallingFactory& FallingFactory::GetInstance()
{
	static FallingFactory instance;
	return instance;
}

FallingObject* FallingFactory::GetRandom()
{
	return &(spriteMasters[GetRandomValue(0, spriteCount)]);
}

FallingObject* FallingFactory::Create(Vector2 _pos)
{
	FallingObject* object = new FallingObject{ _pos, textureMasters[GetRandomValue(0, spriteCount-1)], std::string("rock"), 0.5f };
	//return &object;

	return object;
}