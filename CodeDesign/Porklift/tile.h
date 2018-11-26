#pragma once
#include "GameObject.h"
class tile :
	public GameObject
{
public:
	tile();
	tile(const Texture2D _texture, Vector2 _position);
	~tile();

	void update();
	void draw();
};

