#pragma once

//Declaring the item struct
struct item
{
	int id;
	int value;
};

//Declaring the player struct
struct player
{
	int ATK;

	float DEF;

	int EXP;

	item inv[3] = { {-1, -1}, {-1, -1}, { -1, -1 } };
};



int* zeroArray(int size);
int* duplicateArray(int* arr, size_t size);
void love();
player* randomizePlayers(int length);
void printPlayer(player player);
bool addItem(player * recepient, item gift);
bool hasItem(player * holder, int itemID);
float totalValue(player * holder);