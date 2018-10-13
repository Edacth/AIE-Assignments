#include<iostream>
#include "tictactoe.h"

//Declare global variables
char blank = (char)254;
char x = 'X';
char o = 'O';
char whosTurn = x;
char spaces[3][3] = { { blank, blank, blank },
{ blank, blank, blank },
{ blank, blank, blank } };

void printBoard(int i)
{
	std::cout << "----------------------" << std::endl;
	std::cout << "  1 2 3" << std::endl;

	for (int i = 0; i < 3; i++)
	{
		std::cout << (char)(i + 65) << ' ';
		for (int j = 0; j < 3; j++)
		{
			std::cout << spaces[i][j] << ' ';
		}

		std::cout << std::endl;
	}
	std::cout << "----------------------" << std::endl;
	switch (i)
	{
	case 1:
		std::cout << "It is " << whosTurn << "'s turn. Please enter your space of choice. (eg. A2)" << std::endl;
		break;
	case 2:
		std::cout << "That's not recognized input. Please try again." << std::endl;
		std::cout << "It is " << whosTurn << "'s turn. Please enter your space of choice. (eg. A2)" << std::endl;
		break;
	case 3:
		std::cout << "That space is taken. Please try again." << std::endl;
		std::cout << "It is " << whosTurn << "'s turn. Please enter your space of choice. (eg. A2)" << std::endl;
		break;
	case 4:
		std::cout << "The '" << whosTurn << "' player has won!" << std::endl;		break;
	case 5:
		std::cout << "The board is full. It's a tie!" << std::endl;		break;
	}
}

void clearScreen()
{
	for (int i = 0; i <= 30; i++)
	{
		std::cout << std::endl;

	}
}

bool checkWin()
{
	bool isWin = false;
	/*
	if (spaces[0][0] == spaces[0][1] && spaces[0][1] == spaces[0][2])
	{
		isWin = true;
	}
	*/
	
	for (int i = 0; i < 3; i++)
	{
		if (spaces[i][0] != blank)
		{
			if (spaces[i][0] == spaces[i][1] && spaces[i][1] == spaces[i][2])
			{
				isWin = true;
			}
		}
		if (isWin == true)
		{
			break;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (spaces[0][i] != blank)
		{
			if (spaces[0][i] == spaces[1][i] && spaces[1][i] == spaces[2][i])
			{
				isWin = true;
			}
		}
		if (isWin == true)
		{
			break;
		}
	}
	
	if (spaces[1][1] != blank)
	{
		if (spaces[0][0] == spaces[1][1] && spaces[1][1] == spaces[2][2])
		{
			isWin = true;
		}

		if (spaces[0][2] == spaces[1][1] && spaces[1][1] == spaces[2][0])
		{
			isWin = true;
		}
	}
	return isWin;
}