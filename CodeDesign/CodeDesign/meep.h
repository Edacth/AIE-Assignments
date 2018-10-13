#pragma once
#pragma once
#include "raylib.h"
#include <string>

class meep
{
public:

	//Vars
	bool enabled = true;
	Texture2D texture;
	bool playerControlled;

	// Constructors & Destructors
	meep();
	meep(bool _enabled);
	meep(bool _enabled, std::string texturePath);
	meep(bool _enabled, std::string texturePath, bool _playerControlled);
	~meep();

	// Misc Functions
	void refresh();

private:
};
