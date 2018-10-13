// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

// Last modified by Terry Nguyen (terryn@aie.edu.au)
// 10/09/2018

#include <iostream>
#include "Marine.h"
#include "Zergling.h"
bool marineAlive(Marine * squadArr, size_t arrSize);
bool zerglingAlive(Zergling * swarmArr, size_t arrSize);
int marineCount(Marine * squadArr, size_t arrSize);

using std::cout;
using std::endl;

int main()
{
	int squadSize = 10;
	int swarmSize = 20;
	Marine squad[10];
	Zergling swarm[20];
	

	//marineAlive(squad, 10);
	//zerglingAlive(swarm, 20);

	
	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!" << endl;
	// Attack each other until only one team is left alive
	while (marineAlive(squad, squadSize) || zerglingAlive(swarm, swarmSize)) // If anyone is left alive to fight . . .
	{
		cout << "Marine status: " << marineAlive(squad, squadSize) << endl;
		cout << "Zerg status: " << zerglingAlive(swarm, swarmSize) << endl;
		if (marineAlive(squad, squadSize)) // if there's at least one marine alive
		{
			for (size_t i = 0; i < squadSize; i++) // go through the squad
			{
				if (squad[i].isAlive())
				{
					// each marine will attack the first zergling in the swarm
					cout << "Marine " << i << " fires for " << squad[i].getAttack() << " damage. " << endl;
					int damage = squad[i].getAttack();
					for (size_t j = 0; j < swarmSize; j++)
					{
						if (swarm[j].isAlive())
						{
							swarm[j].takeDamage(damage);
							if (!swarm[j].isAlive()) // if the zergling dies, it is marked as such
							{
								cout << "Zergling " << j << " dies" << endl;
							}
							break;
						}
					}
				}
				
				
			}
		}
		if (zerglingAlive(swarm, swarmSize)) // if there's at least one zergling alive
		{
			for (size_t i = 0; i < swarmSize; i++) // loop through zerglings
			{
				if (swarm[i].isAlive())
				{
					cout << "Zergling " << i << " attacks for " << swarm[i].getAttack() << " damage." << endl;
					int damage = swarm[i].getAttack();
					for (size_t j = 0; j < squadSize; j++)
					{
						if (squad[j].isAlive())
						{
							squad[j].takeDamage(damage);
							if (!squad[j].isAlive()) // if the zergling dies, it is marked as such
							{
								cout << "Marine " << j << " succumbs to his wounds." << endl;
								cout << "There are " << marineCount(squad, squadSize) << " marines left." << endl;
							}
							break;
						}
					}
				}
					
					
			}
		}

		if ( !(marineAlive(squad, squadSize) && zerglingAlive(swarm, swarmSize) ) )
		{
			break;
		}
	}

	// Once one team is completely eliminated, the fight ends and one team wins
	cout << "The fight is over. ";
	if (marineAlive(squad, squadSize))
	{
		cout << "The Marines win." << endl;
	} 
	else
	{
		cout << "The Zerg win." << endl;
	}
	
	return 0;
}

// Is there a Marine Alive?
bool marineAlive(Marine * squadArr, size_t arrSize)
{
	for (size_t i = 0; i < arrSize; i++)
	{
		if (squadArr[i].isAlive())
		{
			return true;
		}
		//cout << i << " is " << (squadArr[i].isAlive() ? "alive" : "dead") << endl;
	}

	return false;
}

// Is there a zergling Alive
bool zerglingAlive(Zergling * swarmArr, size_t arrSize)
{
	for (size_t i = 0; i < arrSize; i++)
	{
		if (swarmArr[i].isAlive())
		{
			return true;
		}
		//cout << i << " is " << (swarmArr[i].isAlive() ? "alive" : "dead") << endl;
	}
	
	return false;
}

int marineCount(Marine * squadArr, size_t arrSize)
{
	int marinesAlive = 0;
	for (size_t i = 0; i < arrSize; i++)
	{
		if (squadArr[i].isAlive())
		{
			marinesAlive++;
		}
	}
	return marinesAlive;
}