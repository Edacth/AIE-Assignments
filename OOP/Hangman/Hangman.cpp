#include <iostream>
#include <string>
#include "Hangman.h"

void initGame(std::string chosenWord, std::string& solution, std::string& progress)
{
	solution = chosenWord;
	std::cout << solution << std::endl;

	for (int i = 0; i < solution.length(); i++)
	{
		progress = progress + "_";
	}
	
}

void printString(std::string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		std::cout << str[i];
		std::cout << ' ';
	}
	std::cout << std::endl;
}

void printScene(int strikes, std::string progress)
{
	clearScreen();

	std::cout << "Strikes" << std::endl;
	for (int i = 0; i <= 4; i++)
	{	
		if (i < strikes)
		{
			std::cout << "[X] ";
		}
		else
		{
			std::cout << "[ ] ";
		}
		
	}
	std::cout << std::endl;

	printString(progress);
}

void clearScreen()
{
	for (int i = 0; i < 30; i++)
	{
		std::cout << std::endl;
	}
}