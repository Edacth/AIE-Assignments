#pragma once
#include "SimpleSprite.h"

class FallingObject
{
public:
	std::string sprType;
	float scale;
	float rot;
	Texture2D texture;
	Vector2 pos;
	int age;
	

	//funtions
	void Draw();
	void Update();
	FallingObject* Clone();
	void Init(Vector2 _pos, const Texture2D _texture, const std::string _sprType = "", float _scale = 1);

	//constructor
	FallingObject(Vector2 _pos, const Texture2D _texture, const std::string _sprType = "", float _scale = 1);
	FallingObject(const Texture2D _texture, const std::string _sprType = "", float _scale = 1);
	FallingObject();
	~FallingObject();
};

