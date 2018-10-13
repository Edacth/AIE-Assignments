#include<iostream>
#include "quiz.h"

bool checkAnswer(char answer, char correct)
{
	bool isCorrect = false;
	if (answer == correct)
	{
		isCorrect = true;
	}
	return isCorrect;
}

char getInput()
{
	char input;
	//Get the input
	std::cin >> input;
	input = (toupper(input));
	//Validate the input
	while ((!std::cin))
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cin >> input;
	}
	return input;
}

void quiz()
{
	char input;
	char answer1 = 'D';
	char answer2 = 'C';
	char answer3 = 'B';
	int score = 0;
	bool doRepeat = true;

	while (doRepeat)
	{

		//Question 1
		std::cout << "How many sides does a square have?" << std::endl
			<< "A. 1" << std::endl
			<< "B. 2" << std::endl
			<< "C. 3" << std::endl
			<< "D. 4" << std::endl;

		std::cin >> input;
		input = (toupper(input));


		if (input == answer1)
		{
			score++;
		}

		//Question 2
		std::cout << "How many corners does a triangle have?" << std::endl
			<< "A. 1" << std::endl
			<< "B. 2" << std::endl
			<< "C. 3" << std::endl
			<< "D. 4" << std::endl;
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cin >> input;
		input = (toupper(input));


		if (input == answer2)
		{
			score++;
		}
		
		//Question 2
		std::cout << "How many sides does a circle have?" << std::endl
			<< "A. 1" << std::endl
			<< "B. 2" << std::endl
			<< "C. 3" << std::endl
			<< "D. 4" << std::endl;
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cin >> input;
		input = (toupper(input));


		if (input == answer3)
		{
			score++;
		}

		if (score < 3)
		{
			std::cout << "You got a score of " << score << ". Would you like to try again?" << std::endl
				<< "Y? N?" << std::endl;

			bool validInput = false;
			while (validInput == false)
			{
				std::cin.clear();
				std::cin.ignore(100, '\n');
				std::cin >> input;
				input = (toupper(input));

				switch (input)
				{
				case 'Y':
					validInput = true;
					break;
				case 'N':
					doRepeat = false;
					validInput = true;
					break;
				default:
					std::cout << "I don't recocnize that input. Please try again." << std::endl;
				}
			}
		}
		else
		{
			std::cout << "you got a perfect score of " << score << ". Congrats!" << std::endl;
			doRepeat = false;
		}
	}
}