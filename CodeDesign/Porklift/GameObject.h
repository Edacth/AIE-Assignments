enum objectType
{
	Tile=0,
	Player,
	Crate
};

#pragma once
#include <iostream>
#include "raylib.h"
#include <vector>
#include <string>

class tile;
class fork;

class GameObject
{
protected:
	std::vector<tile*>* tilesPtr;
	std::vector<GameObject*>* gameObjectsPtr;
	bool enabled;   // is this gameObject enabled?
	Vector2 position; //Position of this object
	Rectangle rectangle; //This object's rectangle
	Texture2D texture; //Texture of this object
public:
	void virtual update();
	void virtual draw();
	bool virtual push(Vector2 direction);
	Rectangle* getRectangle();
	void setPosition(Vector2 _position);
	Vector2* getPosition();
	
	int objectType;
	std::string uuid;

	GameObject();
	~GameObject();
};