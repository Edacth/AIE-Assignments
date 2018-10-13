#include "Wizard.h"
#include "raylib.h"

Wizard::Wizard()
{
	name = "Defaulto";
	gold = 50;
	enabled = true;

	position = { 100, 100 };

}

Wizard::~Wizard()
{

}

void Wizard::draw()
{
	if (enabled)
	{
		DrawTextureV(sprite, position, WHITE);
	}
}