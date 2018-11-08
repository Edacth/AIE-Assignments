//SpriteFactory.h
#pragma once
#include <iostream>
#include "SimpleSprite.h"
#include "IFactory.h"

class SpriteFactory
{
private:
	SpriteFactory();
	~SpriteFactory();

public:
	//This is virtual because it may have children that use the funtion. 
	//Virtual DOES NOT mean it cannot be called.
	virtual SimpleSprite * Create(std::string type);
	static SpriteFactory& GetInstance();

};
