#pragma once
#include "GameObject.h"

class player;

class fork :
	public GameObject
{
	player* playerPtr;
	Vector2 positionOffset;
public:
	fork();
	fork(const Texture2D _texture, player* _playerPtr);
	fork(const Texture2D _texture, player* _playerPtr, std::vector<tile*>* _tiles, std::vector<GameObject*>* _gameObjects);
	~fork();

	void update();
	void draw();
};