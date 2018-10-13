#include <iostream>
#include "tictactoe.h"

int main()
{
	//Declaring the selection variables
	char columnChar;
	int columnNum;
	int row;

	bool showColumnMessage = true;
	bool boardFull = false;

	while (boardFull == false && checkWin() == false)
	{
		//Prompt the user for their input

		//Column
		if (showColumnMessage == true)
		{
			clearScreen();
			printBoard(1);
		}
		showColumnMessage = true;
		
		//Get the input
		std::cin >> columnChar;
		columnNum = (int)(toupper(columnChar));
		columnNum -= 65;
		std::cin >> row;
		row--;
		//Validate the input
		while ((!std::cin) || (!((int)columnNum >= 0 && (int)columnNum <= 2)) || (!(row >= 0 && row <= 2)) )
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			clearScreen();
			printBoard(2);
			std::cin >> columnChar;
			columnNum = (int)(toupper(columnChar));
			columnNum -= 65;
			std::cin >> row;
			row--;
		}

		if (spaces[columnNum][row] == blank)
		{
			spaces[columnNum][row] = whosTurn;
			if (checkWin())
			{
				break;
			}
			else
			{
				switch (whosTurn)
				{
				case 'X':
					whosTurn = o; break;
				case 'O':
					whosTurn = x; break;
				}
			}
		}
		else
		{
			clearScreen();
			printBoard(3);
			showColumnMessage = false;
		}

		boardFull = true;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (spaces[i][j] == blank)
				{
					boardFull = false;
				}
			}

			
		}
		
	}
	if (checkWin())
	{
		clearScreen();
		printBoard(4);
	}
	else if (boardFull == true)
	{
		clearScreen();
		printBoard(5);
	}
	system("pause");
	return 0;
}

