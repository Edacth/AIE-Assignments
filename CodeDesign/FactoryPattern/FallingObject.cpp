#include "FallingObject.h"


FallingObject::FallingObject(Vector2 _pos, const Texture2D _texture, const std::string _sprType, float _scale)
{
	pos = _pos;
	texture = _texture;
	sprType = _sprType;
	scale = _scale;
	rot = 0;
}

FallingObject::FallingObject()
{
	pos = { 100, 100 };
}


FallingObject::~FallingObject()
{
}

void FallingObject::Draw()
{
	//DrawRectangleV(pos, {20, 20}, RED);
	DrawTextureEx(texture, pos, rot, scale, WHITE);
}

void FallingObject::Update()
{
	pos.y += 1;
	rot++;
}
