#pragma once
#include <iostream>
#include "raylib.h"
#include "vec2.h"
#include <vector>
#include <string>

class GameObject
{
protected:
	std::vector<GameObject*>* gameObjectsPtr;
	bool enabled;   // is this gameObject enabled?
	vec2 position; //Position of this object
	Rectangle rectangle; //This object's rectangle
	Texture2D texture; //Texture of this object
	std::string uuid;
public:
	void virtual update();
	void virtual draw();
	Rectangle* getRectangle();
	vec2* getPosition();
	void setPosition(vec2 _position);
	
	GameObject();
	~GameObject();
};