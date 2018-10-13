#include <iostream>
#include <string>
#include "Hangman.h"

int main()
{
	std::string wordList[][3] = { { "CAT", "BIRD", "DOG" }, {"FART", "ROBOT", "ORCA"}, {"KITTEN", "PUPPY", "ROTATION"} };
	std::string solution;
	std::string playerProgress;
	int strikes = 0;
	bool continueLoop = true;
	char input;
	int difficulty;

	std::cout << "Choose a difficulty (1-3)" << std::endl;
	std::cin >> difficulty;
	while ((!std::cin) || !(difficulty <= 3 && difficulty >= 1))
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Choose a difficulty (1-3)" << std::endl;

		std::cin >> input;
		input = toupper(input);
	}


	initGame(wordList[difficulty-1][rand() % 3], solution, playerProgress);
	

	while (continueLoop)
	{
		printScene(strikes, playerProgress);
		
		std::cin >> input;
		input = toupper(input);
		while ((!std::cin))
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			printScene(strikes, playerProgress);
			
			std::cin >> input;
			input = toupper(input);
		}
		bool found = false;
		for (int i = 0; i < solution.length(); i++)
		{
			
			if (input == solution[i])
			{
				std::cout << i << std::endl;
				playerProgress[i] = input;
				found = true;
			}
		}
		if (playerProgress == solution)
		{
			continueLoop = false;
		}
		if (!found)
		{
			strikes++;
		}
		if (strikes >= 5)
		{
			continueLoop = false;
		}
	}
	
	printScene(strikes, playerProgress);

	return 0;
}
