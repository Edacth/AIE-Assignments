#pragma once
#include <string>
#include "raylib.h"
class Potion
{
public:
	Potion()
	{
		name = "Green Potion";
		HPModifier = 10;
		quality = 0.5;
		UseByDate = 2088;
	}
	Potion(int _HPModifier, double _quality)
	{
		name = "Green Potion";
		HPModifier = _HPModifier;
		quality = _quality;
		UseByDate = 2088;
	}
	std::string name;
	int HPModifier;
	double quality;
	int UseByDate;
};

class MyHero
{
public:
	//vars
	std::string name;
	std::string special;
	int age;
	int hitPoints;
	int wealth;
	Texture2D textures[5];

	//constructors and destructor
	MyHero()
	{
		name = "Doomguy";
		special = "shoot gun";
		age = 36;
		hitPoints = 100;
		wealth = 0;
		textures[0] = LoadTexture("resources/ouch1.png");
		textures[1] = LoadTexture("resources/ouch2.png");
		textures[2] = LoadTexture("resources/ouch3.png");
		textures[3] = LoadTexture("resources/ouch4.png");
		textures[4] = LoadTexture("resources/ouch5.png");
	};
	~MyHero();

	void draw();

	MyHero& operator += (Potion &ptn);
};

