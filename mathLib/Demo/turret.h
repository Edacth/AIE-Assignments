#pragma once
#include "raylib.h"
#undef PI
#include "transform2d.h"
#include "vec2.h"

class turret
{

public:
	transform2d transform;
	Texture2D texture;

	turret();
	turret(vec2 _localPos, Texture2D _texture);


	void draw();
	void update();

private:

};
