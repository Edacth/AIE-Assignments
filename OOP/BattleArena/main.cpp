#include <iostream>
#include "BattleArena.h"
#include <windows.h>



int main()
{
	//Declare variables
	int team1Living;
	int team2Living;
	int teamSize = 3;
	int turnCount = 0;

	//Declare and instantiate team 1
	unit team1[3];
	team1[0].initalize(60, 15, "Goblin1");
	team1[1].initalize(200, 40, "Goblin2");
	team1[2].initalize(60, 15, "Goblin3");

	//Declare and instantiate team 2
	unit team2[3];
	team2[0].initalize(100, 20, "Human1");
	team2[1].initalize(100, 20, "Human2");
	team2[2].initalize(100, 20, "Human3");
	
	while ( (countAlive(team1, teamSize) >= 1) //Check if both teams are alive
		&&  (countAlive(team2, teamSize) >= 1))
	{
		turnCount++; //Increment the turn count
		std::cout << "     -=== TURN: " << turnCount << " ===-" << std::endl;

		//Have team1 attack
		for (int i = 0; i < teamSize; i++)
		{
			if (team1[i].isAlive()) //Checks if the team member is dead
			{
				team1[i].attackFoe(team2); //Attacks enemy team
				sortArray(team2, teamSize); //Sorts enemy array by health
			}
			
		}

		//Have team2 attack
		for (int i = 0; i < teamSize; i++)
		{
			if (team2[i].isAlive()) //Checks if the team member is dead
			{
				team2[i].attackFoe(team1); //Attacks enemy team
				sortArray(team1, teamSize); //Sorts enemy array by health
			}
			
		}

		//Prints the two team's data
		printTeam(team1); 
		printTeam(team2);
		system("pause");
	}
	

	std::cout << "The battle is over. ";
	if (countAlive(team1, teamSize) >= 1) //Determines the winner
	{
		std::cout << "The goblins are victorous" << std::endl;
	}
	else
	{
		std::cout << "The humans are victorous" << std::endl;
	}
	system("pause");
	return 0;
}