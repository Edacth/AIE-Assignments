#include "raylib.h"
#include "Corpse.h"
#include "Wizard.h"

Corpse::Corpse()
{
	name = "Unknown";
	gold = 0;
	enabled = false;

	position = { 0, 0 };

}

Corpse::Corpse(Wizard wiz)
{
	name = wiz.name;
	gold = wiz.gold;
	enabled = true;
	position = wiz.position;
}

Corpse::~Corpse()
{

}

void Corpse::draw()
{
	if (enabled)
	{
		DrawTextureV(sprite, position, WHITE);

	}
}