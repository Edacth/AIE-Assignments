#pragma once
#include "Enemy.h"
class EvilEnt :
	public Enemy
{
public:
	EvilEnt(const std::string & fileName, int _x, int _y);
	~EvilEnt();
	bool MoveTo();
};

