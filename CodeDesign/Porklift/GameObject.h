#pragma once
#include <iostream>
#include "raylib.h"
#include <vector>

class tile;

class GameObject
{
protected:
	std::vector<tile*>* tilesPtr;
	bool enabled;   // is this gameObject enabled?
	Vector2 position; //Position of this object
	Rectangle rectangle; //This object's rectangle
	Texture2D texture; //Texture of this object
public:
	
	void virtual update();
	void virtual draw();
	Rectangle getRectangle();
	void setPosition(Vector2 _position);
	Vector2 getPosition();

	GameObject();
	~GameObject();
};