#pragma once
#include <iostream>
#include "raylib.h"

class GameObject
{
protected:
	bool enabled;   // is this gameObject enabled?
	Vector2 position; //Position of this object
	Texture2D texture;
public:
	
	void virtual update();
	void virtual draw();

	GameObject();
	~GameObject();
};