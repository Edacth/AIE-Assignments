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
	fork(const Texture2D _texture, Vector2 _position, std::vector<tile*>* _tiles);
	~fork();

	void update();
	void draw();
};