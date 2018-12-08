#pragma once

#include "GameObject.h"

class enemy :
	public GameObject
{
protected:
	vec2 lookDir;

public:

	enemy();
	enemy(vec2 _position);
	enemy(vec2 _position, std::vector<GameObject*>* _gameObjects);
	enemy(const Texture2D _texture, vec2 _position, std::vector<GameObject*>* _gameObjects);
	~enemy();

	void update();
	void draw();
};
