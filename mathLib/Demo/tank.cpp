#include "tank.h"

tank::tank(vec2 _localPos, Texture2D _texture)
{
	transform.setLocalPosition(_localPos);
	texture = _texture;
}
