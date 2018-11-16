// highscoretable.h
#pragma once
#include "HighScoreEntry.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
std::vector<std::string> split(std::string& line);
class HighScoreTable
{
public:
	//vars
	std::vector<HighScoreEntry> hsVector;


	//constructors
	HighScoreTable();
	HighScoreTable(std::string fileName);
	~HighScoreTable();

	//funtions
	std::vector<HighScoreEntry> topNNScores(int topRows);
	bool pruneBottomNNScores(int bottomRows);
	void bubbleSortDecending();
	void bubbleSortAscending();
	void insertionSortDecending();
	void insertionSortAscending();
	void printTable();
};

HighScoreTable::HighScoreTable()
{

}

HighScoreTable::HighScoreTable(std::string fileName)
{
	std::fstream file(fileName, std::ios::in);
	std::string buffer;
	std::vector <std::string> rtn;

	HighScoreEntry tmpEntry;
	while (std::getline(file, buffer))  // iterates until error or EOF
	{
		rtn = split(buffer);
		std::string temp = (rtn.back());
		tmpEntry.level = std::stoi(rtn.back());
		rtn.pop_back();
		tmpEntry.score = std::stoi(rtn.back().c_str());
		rtn.pop_back();
		tmpEntry.name = rtn.back();
		rtn.pop_back();
		hsVector.push_back(tmpEntry);

	}
	file.close();

	insertionSortDecending();
}

HighScoreTable::~HighScoreTable()
{
}
std::vector<HighScoreEntry> HighScoreTable::topNNScores(int topRows)
{
	std::vector<HighScoreEntry> tempVector;
	for (size_t i = 0; i < topRows; i++)
	{
		tempVector.push_back(hsVector[i]);
	}

	return tempVector;
}

void HighScoreTable::bubbleSortAscending()
{
	for (size_t i = 0; i < hsVector.size()-1; i++)
	{
		for (size_t j = hsVector.size()-1; j > i; j--)
		{
			if (hsVector[j].score < hsVector[j - 1].score)
			{
				int tempScore = hsVector[j - 1].score;
				hsVector[j - 1].score = hsVector[j].score;
				hsVector[j].score = tempScore;

				std::string tempName = hsVector[j - 1].name;
				hsVector[j - 1].name = hsVector[j].name;
				hsVector[j].name = tempName;


				
			}
			std::cout << "i = " << i << " j = " << j << std::endl;
			printTable();
			
		}
	}
}
void HighScoreTable::bubbleSortDecending()
{
	for (size_t i = 0; i < hsVector.size() - 1; i++)
	{
		for (size_t j = hsVector.size() - 1; j > i; j--)
		{
			if (hsVector[j].score > hsVector[j - 1].score)
			{
				int tempScore = hsVector[j - 1].score;
				hsVector[j - 1].score = hsVector[j].score;
				hsVector[j].score = tempScore;

				std::string tempName = hsVector[j - 1].name;
				hsVector[j - 1].name = hsVector[j].name;
				hsVector[j].name = tempName;



			}
			std::cout << "i = " << i << " j = " << j << std::endl;
			//printTable();

		}
	}
}
void HighScoreTable::insertionSortAscending()
{
	for (size_t i = 1; i < hsVector.size(); i++)
	{
		int scoreKey = hsVector[i].score;
		int levelKey = hsVector[i].level;
		std::string nameKey = hsVector[i].name;
		int j = i - 1;
		while (j >= 0 && hsVector[j].score > scoreKey)
		{
			hsVector[j + 1].score = hsVector[j].score;
			hsVector[j + 1].level = hsVector[j].level;
			hsVector[j + 1].name = hsVector[j].name;
			j = j - 1;
			hsVector[j + 1].score = scoreKey;
			hsVector[j + 1].level = levelKey;
			hsVector[j + 1].name = nameKey;
		}
	}
}
void HighScoreTable::insertionSortDecending()
{
	for (size_t i = 1; i < hsVector.size(); i++)
	{
		int scoreKey = hsVector[i].score;
		int levelKey = hsVector[i].level;
		std::string nameKey = hsVector[i].name;
		int j = i - 1;
		while (j >= 0 && hsVector[j].score < scoreKey)
		{
			hsVector[j + 1].score = hsVector[j].score;
			hsVector[j + 1].level = hsVector[j].level;
			hsVector[j + 1].name = hsVector[j].name;
			j = j - 1;
			hsVector[j + 1].score = scoreKey;
			hsVector[j + 1].level = levelKey;
			hsVector[j + 1].name = nameKey;
		}
	}
}
bool HighScoreTable::pruneBottomNNScores(int bottomRows)
{
	for (size_t i = 0; i < bottomRows; i++)
	{
		if (hsVector.size() > 0)
		{
			hsVector.pop_back();
		}
	}
	

	std::fstream file;
	std::string filePath = "aftermath.txt";

	file.open(filePath.c_str(), std::ios::out);
	for (size_t i = 0; i < hsVector.size(); i++)
	{
		file << hsVector[i].name << "," << hsVector[i].score << "," << hsVector[i].level << "\n";
	}
	file.close();

	return 1;
}

void HighScoreTable::printTable()
{
	for (size_t i = 0; i < hsVector.size(); i++)
	{
		std::cout << "[" << i << "]" << hsVector[i].name.c_str() << " ";
		std::cout << hsVector[i].score << std::endl;
	}
}


std::vector<std::string> split(std::string& line)
{
	std::vector<std::string> result;
	std::stringstream lineStream(line);
	std::string cell;
	while (std::getline(lineStream, cell, ','))
		result.push_back(cell);
	if (!lineStream && cell.empty())
		result.push_back("");
	return result;
}