#pragma once
#include "SimpleSprite.h"

class FallingObject
{
public:
	std::string sprType;
	float scale;
	float rot;
	Rectangle r1, r2;//r1 = size of texture , r2 = calculated destination size
	Texture2D texture;
	Vector2 pos;
	

	//funtions
	void Draw();
	void Update();

	//constructor
	FallingObject(Vector2 _pos, const Texture2D _texture, const std::string _sprType = "", float _scale = 1);
	FallingObject(const Texture2D _texture, const std::string _sprType = "", float _scale = 1);
	FallingObject();
	~FallingObject();
};

