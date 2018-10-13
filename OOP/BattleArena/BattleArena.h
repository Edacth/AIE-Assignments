#pragma once
#include <string>
//Global variables



class unit
{
public:
	int health; //Health of unit
	int attack;	//Attack value of unit
	std::string type; 	//Unit type


	
	void takeDamage(int dam);
	void initalize(int h, int a, std::string t);
	void dealDamage(unit& target);
	void attackFoe(unit* opposingTeam);
	int getHealth();
	bool isAlive();
};

void printTeam(unit* team);
int countAlive(unit* team, size_t arrSize);
void sortArray(unit* arr, int length);