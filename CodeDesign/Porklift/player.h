#pragma once
#include "GameObject.h"
#include "tile.h"
#include "fork.h"

class player :
	public GameObject
{
protected:
	

public:
	fork myFork;

	player();
	player(Vector2 _position);
	player(const Texture2D _texture, const Texture2D _forkTexture, Vector2 _position, std::vector<tile*>* _tiles, std::vector<GameObject*>* _gameObjects);
	~player();

	void update();
	void draw();
};

