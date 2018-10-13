#pragma once
#include <string>

struct saveData
{
	char playerName[10];
	int deathCount;
	int deepestFloor;

	bool hasBeenBeatenGame;

	double timePlayed;  // given in seconds
};

struct beasiaryEntry
{
	int ID;
	char name[20] = {};
	char flavorText[50];
};
void helloWorld();
void vectorz();
void saveGame(saveData data);
void loadGame(std::string path);
void bestiaryPrint();
void bestiaryAdd();
void bestiaryRemove();
void bestiaryView();
void bestiaryList();

