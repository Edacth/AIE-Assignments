#include <iostream>
#include "NumberGuessingGameAssessment.h"


int main()
{
	//Declare variables
	int guess;
	float guessFloat;
	int guessCount = 0;
	int min = 1;
	int max = 100;
	int difference;
	char playerInput;
	bool guessCorrect = false;
	bool validInput = false;
	bool cheated = false;

	//Display instructions
	std::cout << "Please guess a number between 1 and 100 (Inclusive)" << std::endl
		<< "Press enter when you've thought of one." << std::endl;

	while (guessCorrect == false) //Main game loop
	{
		//Calculate the guess
		difference = max - min;
		guess = max - (difference / 2);
		guessFloat = (float)max - ((float)difference / 2.0f);
		guessCount++;

		//Display the guess and prompt input 
		validInput = false;
		while ( validInput == false)
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "My guess is: " << guess << std::endl
				<< "Is my guess high (H), low (L), or spot on equal (E)" << std::endl;
			std::cin >> playerInput;
			playerInput = toupper(playerInput);

			switch (playerInput)
			{
			case 'H':
				max = guess;
				validInput = true;
				break;
			case 'L':
				min = guess;
				validInput = true;
				break;
			case 'E':
				guessCorrect = true;
				validInput = true;
				break;
			default:
				std::cout << "I don't recocnize that input. Please try again." << std::endl;
			}
		}

		//Detect if there is no more space and call the player a cheater
		if (guessCorrect == false)
		{
			guessCorrect = detectCheat(min, max);
			cheated = guessCorrect;
		}
		
	}

	//Display the end state message
	if (cheated == true)
	{
		std::cout << "YOU FILTHY CHEAT!" << std::endl;
		system("pause");
	}
	else
	{
		std::cout << "Thank you for playing with me! It took me " << guessCount << " guess(es)." << std::endl;
		system("pause");
	}
	
	return 0;
}