// highscoretable.h
#pragma once
#include "HighScoreEntry.h"
#include <vector>

class HighScoreTable
{
public:
	std::vector<HighScoreEntry> hsVector;
	std::vector<HighScoreEntry> topNNScores(int topRows);
	bool pruneBottomNNScores(int bottomRows);

	HighScoreTable();
	HighScoreTable(std::string fileName);
	~HighScoreTable();

	void sortAccending();
};

HighScoreTable::HighScoreTable()
{

}

HighScoreTable::~HighScoreTable()
{
}

void HighScoreTable::sortAccending()
{
	for (size_t i = 0; i < hsVector.size()-1; i++)
	{
		if (hsVector[i].score > hsVector[i + 1].score)
		{
			int temp = hsVector[i + 1].score;
			hsVector[i + 1].score = hsVector[i].score;
			hsVector[i].score = temp;
		}
		
	}
}