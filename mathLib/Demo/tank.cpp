#include "tank.h"

tank::tank(vec2 _localPos, Texture2D _texture)
{
	transform.setLocalPosition(_localPos);
	transform.setLocalScale({ 1, 1 });
	texture = _texture;
}

void tank::draw()
{
	//DrawTextureEx(texture, transform.getLocalPosition(), transform.getLocalRotation(), 1, WHITE);
	Rectangle sourceRect = { 0, 0, 38, 36 };
	Rectangle destRect = { transform.getLocalPosition().x, transform.getLocalPosition().y, 36, 36 };

	DrawTexturePro(texture, sourceRect, destRect, { 18, 18 }, transform.getLocalRotation() * cMath::RAD_TO_DEG, WHITE);
}

void tank::update()
{
	vec2 translationAxis = { 0, 0 };
	if (IsKeyDown(KEY_W))
	{
		translationAxis.y += -1;
	}
	if (IsKeyDown(KEY_S))
	{
		translationAxis.y += 1;
	}
	if (IsKeyDown(KEY_A))
	{
		translationAxis.x += -1;
	}
	if (IsKeyDown(KEY_D))
	{
		translationAxis.x += 1;
	}
	if (IsKeyDown(KEY_RIGHT))
	{
		transform.rotate(cMath::DEG_TO_RAD * 1);
	}
	if (IsKeyDown(KEY_LEFT))
	{
		transform.rotate(cMath::DEG_TO_RAD * -1);
	}
	if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
	{
		transform.lookAt(GetMousePosition());
	}
	if (translationAxis != vec2{ 0, 0 })
	{
		transform.translate(translationAxis);
	}
}
