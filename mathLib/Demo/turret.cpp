#include "turret.h"

turret::turret(vec2 _localPos, Texture2D _texture)
{
	transform.setLocalPosition(_localPos);
	transform.setLocalScale({ 1, 1 });
	texture = _texture;
}

void turret::draw()
{
	Rectangle sourceRect = { 0, 0, 12, 30 };
	Rectangle destRect = { transform.worldPosition().x, transform.worldPosition().y, 12, 30 };

	DrawTexturePro(texture, sourceRect, destRect, { 6, 0 }, transform.getLocalRotation() * cMath::RAD_TO_DEG - 90, WHITE);
}

void turret::update()
{
	if (IsKeyDown(KEY_RIGHT))
	{
		transform.rotate(cMath::DEG_TO_RAD * 2);
	}
	if (IsKeyDown(KEY_LEFT))
	{
		transform.rotate(cMath::DEG_TO_RAD * -2);
	}
	if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
	{
		transform.lookAt(GetMousePosition());
	}
}
