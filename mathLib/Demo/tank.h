#pragma once
#include "raylib.h"
#include "transform2d.h"
#include "vec2.h"

class tank
{
	
public:
	transform2d transform;
	Texture2D texture;

	tank();
	tank(vec2 _localPos, Texture2D _texture);


	void draw();
	void update();

private:

};