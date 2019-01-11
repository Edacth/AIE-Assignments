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
	Rectangle destRect = { transform.worldPosition().x, transform.worldPosition().y, 36, 36 };

	DrawTexturePro(texture, sourceRect, destRect, { 18, 18 }, transform.getLocalRotation() * cMath::RAD_TO_DEG - 90, WHITE);
}

void tank::update()
{
	vec2 translationAxis = { 0, 0 };
	if (IsKeyDown(KEY_W))
	{
		translationAxis = transform.getForward();
	}
	if (IsKeyDown(KEY_S))
	{
		translationAxis = -transform.getForward();
	}
	if (IsKeyDown(KEY_A))
	{
		transform.rotate(cMath::DEG_TO_RAD * -2);
		transform.getChildren()->rotate(cMath::DEG_TO_RAD * -2);
	}
	if (IsKeyDown(KEY_D))
	{
		transform.rotate(cMath::DEG_TO_RAD * 2);
		transform.getChildren()->rotate(cMath::DEG_TO_RAD * 2);
	}
	if (translationAxis != vec2{ 0, 0 })
	{
		transform.translate(translationAxis);
	}
}
