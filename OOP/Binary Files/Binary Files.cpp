#include <iostream>
#include "Binary Files.h"
#include <cstring>
#include <fstream>

//Write a string to a file
void helloWorld()
{
	std::string str1 = "Hello world";
	int arraySize = str1.length();

	std::fstream fout("hello.dat", std::ios::out | std::ios::binary);
	if (!fout.good())
	{
		return;
	}
		for (int i = 0; i < arraySize; i++)
		{
			fout.write((char*)&str1[i], sizeof(char));
		}
		fout.flush();
		fout.close();
	
	
}

//Write a vector3 to a file
struct Vector3{
	float x, y, z;
};

void vectorz() {
	Vector3 myVecArray[] = { { 0, 1, 2 },{ 1, 2, 3 },{ 4, 5, 6 },{ 32, 1, 98 } };
	int arraySize = sizeof(myVecArray) / sizeof(Vector3);

	std::ofstream fout("data.dat", std::ios::out | std::ios::binary);
	if (fout.good()) {
		for (int i = 0; i < arraySize; i++) {
			fout.write((char*)&myVecArray[i], sizeof(Vector3));
		}
		fout.flush();
		fout.close();
	}
}

//Example of saving game data
void saveGame(saveData data)
{
	int arraySize = sizeof(data);

	std::ofstream fout("playerData.dat", std::ios::out | std::ios::binary);
	if (!fout.good())
	{
		return;
	}
		//for (int i = 0; i < arraySize; i++) {
			fout.write((char*)&data, sizeof(saveData));
		//}
		//fout.flush();
		fout.close();
}

//Example of loading game data
void loadGame(std::string path)
{
	saveData mySave;
	std::ifstream fin(path, std::ios::in | std::ios::binary);
	if (!fin.good())
	{
		return;
	}
	while(!fin.eof() && fin.peek() != EOF) {
		fin.read((char*)&mySave, sizeof(saveData));
		std::cout << mySave.playerName << " " << mySave.deathCount 
			<< " " << mySave.deepestFloor << " " << mySave.hasBeenBeatenGame 
			<< " " << mySave.timePlayed << std::endl;
	}
	fin.close();
}

//Prints the main menu of the bestiary
void bestiaryPrint()
{
		std::cout << "What would you like to do?" << std::endl << std::endl;
		std::cout << "1) Add a monster by ID" << std::endl;
		std::cout << "2) Remove a monster by ID" << std::endl;
		std::cout << "3) Visit a monster by ID" << std::endl;
		std::cout << "4) Browse monsters" << std::endl;
		std::cout << "5) Exit" << std::endl;
		std::cout << std::endl << "> ";
	
}

//Adds a monster to the bestiary by creating a file
void bestiaryAdd()
{
	beasiaryEntry myEntry;
	std::string filePath;

	while (true) { //Gets valid ID input
		std::cout << "Enter the ID of the new Monster (This will overwrite existing IDs)" << std::endl << " >";
		std::cin >> myEntry.ID;
		if (std::cin.fail()) {
			std::cout << "Invalid input" << std::endl;
			std::cin.ignore(50, '\n');
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			
			continue;
		}
		else { break; }
	}

	std::cin.ignore(50, '\n');
	std::cout << "Enter the name of the new Monster" << std::endl << " >"; //Prompt name input
	std::cin.getline(myEntry.name, 20);
	
	std::cout << "Enter some flavor text" << std::endl << " >"; //Prompt flavor input
	std::cin.getline(myEntry.flavorText, 50);


	filePath = "bestiary\\" + std::to_string(myEntry.ID) + ".dat"; //Creates the filepath
	std::ofstream fout(filePath, std::ios::out | std::ios::binary);
	if (!fout.good())
	{
		return;
	}
	fout.write((char*)&myEntry, sizeof(beasiaryEntry)); //Writes data to file

	fout.flush();
	fout.close();
}

//Deletes a bestiary entry file
void bestiaryRemove()
{
	int ID;

	while (true) { //Gets valid ID input
		std::cout << "Enter the ID of the monster you wish to delete" << std::endl << "> "; //Prompt input
		std::cin >> ID;
		if (std::cin.fail()) {
			std::cout << "Invalid input" << std::endl;
			std::cin.ignore(50, '\n');
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			continue;
		}
		else { break; }
	}
	std::string filePath = "bestiary\\" + std::to_string(ID) + ".dat"; //Creates the filepath
	remove(filePath.c_str()); //Deletes file
	std::cout << std::endl << ID << " has been deleted." << std::endl;
	std::cout << std::endl;
}

//Prints the data on a specified file
void bestiaryView()
{
	int ID;
	beasiaryEntry myEntry;

	while (true) { //Gets valid ID input
		std::cout << "Enter the ID of the monster to view" << std::endl << std::endl << "> "; //Prompt ID input
		std::cin >> ID;
		if (std::cin.fail()) {
			std::cout << "Invalid input" << std::endl;
			std::cin.ignore(50, '\n');
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			continue;
		}
		else { break; }
	}

	std::string filePath = "bestiary\\" + std::to_string(ID) + ".dat";

	std::ifstream fin(filePath, std::ios::in | std::ios::binary);
	if (!fin.good()) //Looks if the file exists
	{
		std::cout << std::endl << "-------------" << std::endl;
		std::cout <<  "That entry does not exist." << std::endl << std::endl; //Rejection
		std::cout << "-------------" << std::endl;
		return;
	}
	while (!fin.eof() && fin.peek() != EOF) { //Reads the file
		fin.read((char*)&myEntry, sizeof(beasiaryEntry));
		
	}
	
	std::cout << "-------------" << std::endl; //Prints the entry
	std::cout << "ID: " << myEntry.ID << std::endl << "Name: " << myEntry.name << std::endl << "Flavor Text: " << myEntry.flavorText
		<< std::endl << std::endl << "-------------" << std::endl << std::endl;
	fin.close();
}

//Lists entries between two values specified by the user
void bestiaryList()
{
	int min, max;
	std::cout << "Enter a range of ids to view " << std::endl << std::endl << "> ";
	while (true) { //Gets valid ID input
		std::cin >> min;
		if (std::cin.fail()) {
			std::cout << "Invalid input" << std::endl;
			std::cin.ignore(50, '\n');
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			continue;
		}
		else { break; }
	}

	while (true) { //Gets valid ID input
		std::cin >> max;
		if (std::cin.fail()) {
			std::cout << "Invalid input" << std::endl;
			std::cin.ignore(50, '\n');
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			continue;
		}
		else { break; }
	}

	if (min > max)
	{
		int temp = max;
		max = min;
		min = temp;
	}

	max += 1; //Account for arrays starting at 0
	std::cout << std::endl;
	for (int i = min; i < max; i++) //Iterate through the values
	{
		beasiaryEntry myEntry;
		std::string filePath = "bestiary\\" + std::to_string(i) + ".dat";

		std::ifstream fin(filePath, std::ios::in | std::ios::binary);
		if (fin.good()) //Check if the file exists
		{
			while (!fin.eof() && fin.peek() != EOF) { //Reads the file
				fin.read((char*)&myEntry, sizeof(beasiaryEntry));

			}
			std::cout << i << " " << myEntry.name << std::endl; //Prints entry name if found
			fin.close();
		}
		else
		{
			std::cout << i << " NO ENTRY" << std::endl;
		}
		
		
	}
	std::cout << std::endl;
}