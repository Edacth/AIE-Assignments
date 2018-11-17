#pragma once
#include "GameObject.h"
class player :
	public GameObject
{
public:
	player();
	player(Vector2 _position);
	player(const Texture2D _texture, Vector2 _position);
	~player();

	void update();
	void draw();
};

