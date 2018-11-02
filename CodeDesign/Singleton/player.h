#pragma once
#include "raylib.h"

class Player
{
private:
	
	Texture sprite;

public:
	//Vars
	Vector2 position;

	//Constructors
	Player();
	Player(Texture _sprite, Vector2 _position);
	~Player();

	//Funtions
	void draw();
};

