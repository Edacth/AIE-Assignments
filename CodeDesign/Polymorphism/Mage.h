#pragma once
#include "Player.h"
class Mage :
	public Player
{
public:
	Mage(const std::string & fileName);
	~Mage();
	bool moveTo();
};

