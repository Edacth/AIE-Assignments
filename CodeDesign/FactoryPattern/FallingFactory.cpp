//FallingFactory.cpp
#include "FallingFactory.h"

size_t FallingFactory::spriteCount = NULL;
FallingObject* FallingFactory::spriteMasters = nullptr;
Texture2D* FallingFactory::textureMasters = nullptr;

void FallingFactory::init()
{
    //Load in the various sprites
    spriteCount = 8;
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
	textureMasters[4] = LoadTexture("resources/spaceMeteors_001.png");
	textureMasters[5] = LoadTexture("resources/spaceMeteors_002.png");
	textureMasters[6] = LoadTexture("resources/spaceMeteors_003.png");
	textureMasters[7] = LoadTexture("resources/spaceMeteors_004.png");
}

FallingFactory::FallingFactory()
{
	init();
}

FallingFactory::~FallingFactory()
{
	delete spriteMasters;
	delete textureMasters;
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

FallingObject* FallingFactory::Create(std::string _sprType)
{
	int spriteValue = 0;
	float scale = 1;
	if (_sprType == "debris")
	{
		spriteValue = GetRandomValue(0, 3);
		scale = 0.5f;
	}
	else if (_sprType == "rock")
	{
		spriteValue = GetRandomValue(4, 7);
		scale = 0.2f;
	}
	FallingObject* object = new FallingObject{ {(float)GetRandomValue(0, 800), -10}, textureMasters[spriteValue], _sprType, scale };
	

	return object;
	delete object;
}