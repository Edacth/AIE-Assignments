#include "FallingObject.h"
#include <iostream>
#include <string>

FallingObject::FallingObject(Vector2 _pos, const Texture2D _texture, const std::string _sprType, float _scale)
{
	pos = _pos;
	texture = _texture;
	sprType = _sprType;
	scale = _scale;
	rot = 0;
	age = 0;
}

FallingObject::FallingObject()
{
	age = 0;
}


FallingObject::~FallingObject()
{
}

void FallingObject::Draw()
{
	//DrawRectangleV(pos, {20, 20}, RED);
	DrawTextureEx(texture, pos, rot, scale, WHITE);
	//DrawText((std::to_string(age)).c_str(), pos.x, pos.y, 10, BLACK);
}

void FallingObject::Update()
{
	pos.y += 1;
	rot += 1;
	//age++;
	//std::cout << pos.x << " " << pos.y << std::endl;
}

FallingObject* FallingObject::Clone()
{
	FallingObject* newObject = new FallingObject;
	newObject->pos = { (float)GetRandomValue(0, 800), -10 };
	newObject->scale = scale;
	newObject->texture = texture;
	newObject->sprType = sprType;
	newObject->rot = rot;

	return newObject;
}

void FallingObject::Init(Vector2 _pos, const Texture2D _texture, const std::string _sprType, float _scale)
{
	pos = _pos;
	texture = _texture;
	sprType = _sprType;
	scale = _scale;
	rot = 0;
	age = 0;
}