#pragma once

#include "GameObject.h"

class player :
	public GameObject
{
protected:


public:

	player();
	player(vec2 _position);
	player(vec2 _position, std::vector<GameObject*>* _gameObjects);
	player(const Texture2D _texture, vec2 _position, std::vector<GameObject*>* _gameObjects);
	~player();

	void update();
	void draw();
};
