
#include "myHero.h"
#include <string>
#include "raylib.h"

MyHero& MyHero::operator += (Potion &ptn)
{
	

	hitPoints += ptn.HPModifier * ptn.quality;
	return *this;
}

MyHero::~MyHero()
{

}

void MyHero::draw()
{
	if (hitPoints >= 0 && hitPoints <= 19)
	{
		DrawTextureEx(textures[4], {200, 200}, 0, 1.0, WHITE);
	}
	else if (hitPoints >= 20 && hitPoints <= 39)
	{
		DrawTextureEx(textures[3], { 200, 200 }, 0, 1.0, WHITE);
	}
	else if (hitPoints >= 40 && hitPoints <= 59)
	{
		DrawTextureEx(textures[2], { 200, 200 }, 0, 1.0, WHITE);
	}
	else if (hitPoints >= 60 && hitPoints <= 79)
	{
		DrawTextureEx(textures[1], { 200, 200 }, 0, 1.0, WHITE);
	}
	else if (hitPoints >= 80)
	{
		DrawTextureEx(textures[0], { 200, 200 }, 0, 1.0, WHITE);
	}
	
}