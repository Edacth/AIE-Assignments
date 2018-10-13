#include "meep.h"
#include <iostream>
#include <string>
#include <cstring>

meep::meep()
{
	enabled = true;
	texture = LoadTexture("resources/default.png");
}

meep::meep(bool _enabled)
{
	enabled = _enabled;
	texture = LoadTexture("resources/default.png");
}

meep::meep(bool _enabled, std::string texturePath)
{
	enabled = _enabled;
	texture = LoadTexture( (texturePath.c_str()) );
	std::cout << texturePath << std::endl;
}

meep::meep(bool _enabled, std::string texturePath, bool _playerControlled)
{
	enabled = _enabled;
	//texture = LoadTexture(texturePath.c_str);
	playerControlled = _playerControlled;
}

meep::~meep()
{
	std::cout << "A meep just died." << std::endl;
}

void meep::refresh()
{
	if (enabled)
	{
		DrawTextureEx(texture, {200, 200}, 0, 4.0, WHITE);
	}
}