// HighScoreEntry.h
#pragma once
#include <iostream>
class HighScoreEntry
{
public:
	std::string name;
	int score;
	int level;

	HighScoreEntry();
	//HighScoreEntry(std::string _name, int _score, int _level);
	~HighScoreEntry();
};

HighScoreEntry::HighScoreEntry()
{
	name = "none";
	score = -1;
	level = -1;
}

HighScoreEntry::~HighScoreEntry()
{

}