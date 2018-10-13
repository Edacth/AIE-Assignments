#include <iostream>
#include "Binary Files.h"
#include <string>
#include <Windows.h>

int main()
{

	saveData player1 = { "Dave", 6, 3, false, 134.55f };
	//CLOSED AND OPEN SOLUTIONS vv
	//------------------------------
	//helloWorld();
	//vectorz();
	//saveGame(player1);
	//loadGame("playerData.dat");
	//------------------------------


	//BESTIARY CODE
	//------------------------------
	bool keepGoing = true;

	CreateDirectory("bestiary", NULL);
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		std::cout << "Looks like you already have a data folder. Nice!" << std::endl;
		system("pause");
	}
	else
	{
		
		std::cout << "Monster data folder does not exsist . . . \nCreating" << std::endl;

	}

	while (keepGoing)//Main game loop
	{
		
		bestiaryPrint(); //Print the menu

		char input; 
		std::cin >> input; //Prompt input
		switch (input) //Run a funtion based on their input
		{
		case '1':
			bestiaryAdd();
			break;
		case '2':
			bestiaryRemove();
			break;
		case '3':
			bestiaryView();
			break;
		case '4':
			bestiaryList();
			break;
		case '5':
			std::cout << "Take care! DON'T DIE. :)" << std::endl;
			keepGoing = false;
			break;
		default:
			break;
		}
		std::cin.clear();
		std::cin.ignore(50, '\n');
	}
	
	
	return 0;
}