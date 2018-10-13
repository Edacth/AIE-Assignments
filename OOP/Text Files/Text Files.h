#pragma once

struct Entity
{
	// use std::string or cstrings to represent the name; it's up to you!

	float hitpoints;
	float armor;

	int strength;
	int defense;
	int agility;
	int luck;

	
};


int printer();
int saver();
int garble();
int commaSep();
int loadData();
int caeserMessage();