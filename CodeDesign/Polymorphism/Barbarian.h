#pragma once
#include "Player.h"
class Barbarian :
	public Player
{
public:
	Vector2 direction = {0,0};
	Barbarian(const std::string & fileName);
	~Barbarian();
	bool moveTo();
	bool Update();
};

