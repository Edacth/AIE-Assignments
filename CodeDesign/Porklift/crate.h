#pragma once
#include "GameObject.h"
#include "tile.h"

class crate :
	public GameObject
{

public:
	crate();
	crate(Texture _texture, Vector2 position, std::vector<tile*>* _tiles, std::vector<GameObject*>* _gameObjects);
	~crate();

	void update();
	void draw();
	bool push(Vector2 direction);
};