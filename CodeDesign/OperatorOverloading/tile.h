#pragma once
//Tile.h
#include <string>
#include <iostream>
#include "raylib.h"
class Tile
{
public:
	Texture2D* Background = new Texture2D();
	Color* tint = new Color();
	std::string* imageFilename = new std::string;
	Tile(std::string _imageFilename);
	Tile(const Tile& rhs);
	Tile();
	~Tile();


	Tile & operator = (const Tile& rhs);
	Tile & operator = (const std::string* rhs);
};