#include "healthBar.h"

healthBar::healthBar()
{
	position = { 100, 100 };
}

healthBar::healthBar(vec2 _position)
{
	position = _position;
	t = 1;
}

healthBar::~healthBar()
{
}

void healthBar::update(int health, int maxHealth)
{
	t = (float)health / (float)maxHealth;
}

void healthBar::draw()
{
	DrawRectangleV(position, { 800, 40 }, GRAY);
	DrawRectangleV({ position.x + 10.0f, position.y + 10.0f }, { cMath::lerp(0.0f, 780.0f, t), 20.0f }, GREEN);
}