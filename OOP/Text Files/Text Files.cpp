#include "Text Files.h"
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <time.h>
#include <sstream> 


int printer()
{
	std::fstream file;
	std::string filePath;
	

	//std::cout << filePath << std::endl;
	do
	{
	std::cout << "Please enter a file path." << std::endl;
	std::getline(std::cin, filePath, '\n');
	file.open(filePath, std::ios::in);
	} while (!file.is_open());

	std::string buffer;
	while (std::getline(file, buffer))  // iterates until error or EOF
	{
		// print the line after it is buffered
		std::cout << buffer << std::endl;
	}
	file.close();
	return 0;
}

int saver()
{
	std::fstream file;
	std::string filePath;
	std::string name;
	std::string age;
	std::string favColor;

	std::cout << "Where would you like to save this?" << std::endl;
	std::getline(std::cin, filePath, '\n');
	file.open(filePath, std::ios::out);
	while (!file.is_open())
	{
		std::cout << "I'm sorry that's not available. try again." << std::endl;
		std::getline(std::cin, filePath, '\n');
		file.open(filePath, std::ios::out);
	}

	std::cout << "Who are you?" << std::endl;
	std::getline(std::cin, name, '\n');

	std::cout << "How old are you?" << std::endl;
	std::getline(std::cin, age, '\n');

	std::cout << "What is your favorite color" << std::endl;
	std::getline(std::cin, favColor, '\n');

	file << name << std::endl << age << std::endl << favColor << std::endl;
	file.close();
	return 0;
}

int garble()
{
	std::fstream file;
	std::string filePath = "importantMessage.txt";
	std::string buffer;
	srand(time(NULL));

	file.open(filePath, std::ios::in);
	while (std::getline(file, buffer))  // iterates until error or EOF
	{
		// print the line after it is buffered
		for (size_t i = 0; i < buffer.length(); i++)
		{
			int rand = std::rand() % 3;
			if (rand == 1)
			{
				buffer[i] = '#';
			}
			
		}
		std::cout << buffer << std::endl;
	}

	return 0;
}

int commaSep()
{
	std::fstream file;
	std::string filePath = "values.txt";
	std::string buffer;
	int arr[10];
	std::stringstream convert;

	file.open(filePath, std::ios::in);
	if (!file.is_open())
	{
		std::cout << "File not found." << std::endl;
		return -1;
	}

	int i = 0;
	while (std::getline(file, buffer, ','))  // iterates until error or EOF
	{
		arr[i] = std::stoi(buffer);
		
		i++;
	}

	for (size_t i = 0; i < 10; i++)
	{
		std::cout << arr[i] << std::endl;
	}
	file.close();
	return 0;
}

int loadData()
{
	std::fstream file;
	std::string filePath = "entityData.txt";
	std::string buffer;
	Entity arr[5];
	std::stringstream convert;

	file.open(filePath, std::ios::in);
	if (!file.is_open())
	{
		std::cout << "File not found." << std::endl;
		return -1;
	}

	int i = 0;
	for (size_t i = 0; i < 5;  )
	{

		std::getline(file, buffer, '\n');
		if (buffer != "" && buffer[0] != '@')
		{
			//std::cout << buffer << std::endl;
			arr[i].hitpoints = std::stoi(buffer);

			std::getline(file, buffer, '\n');
			arr[i].armor = std::stoi(buffer);

			std::getline(file, buffer, '\n');
			arr[i].strength = std::stoi(buffer);

			std::getline(file, buffer, '\n');
			arr[i].defense = std::stoi(buffer);

			std::getline(file, buffer, '\n');
			arr[i].agility = std::stoi(buffer);

			std::getline(file, buffer, '\n');
			arr[i].luck = std::stoi(buffer);
			i++;
		}
		

	}

	for (size_t i = 0; i < 5; i++)
	{
		
		std::cout << arr[i].hitpoints << std::endl;
		std::cout << arr[i].armor << std::endl;
		std::cout << arr[i].strength << std::endl;
		std::cout << arr[i].defense << std::endl;
		std::cout << arr[i].agility << std::endl;
		std::cout << arr[i].luck << std::endl;
		std::cout << "-----------" << std::endl;
	}
	file.close();
	return 0;
}

int caeserMessage()
{
	std::fstream file;
	std::string filePath;
	std::string input;
	std::string buffer;

	while (true)
	{


		std::cout << "Do you wish to save or load?" << std::endl;
		std::getline(std::cin, input, '\n');

		while (!(input == "save") && !(input == "load"))
		{
			std::cout << "I dont recognize that input. Do you wish to save or load?" << std::endl;
			std::getline(std::cin, input, '\n');
		}

		if (input == "load")
		{
			std::cout << "Where would you like to load from?" << std::endl;
			std::getline(std::cin, filePath, '\n');

			file.open(filePath, std::ios::in);

			if (!file.is_open())
			{
				std::cout << "File not found." << std::endl;
			}
			else
			{
				while (std::getline(file, buffer))  // iterates until error or EOF
				{
					// print the line after it is buffered
					for (size_t i = 0; i < buffer.length(); i++)
					{
						buffer[i] = buffer[i] -= 1;
					}
					std::cout << buffer << std::endl;
				}
			}



		}
		else if (input == "save")
		{
			std::cout << "Where would you like to save to?" << std::endl;
			std::getline(std::cin, filePath, '\n');

			std::cout << "Enter a message." << std::endl;
			std::getline(std::cin, input, '\n');

			file.open(filePath, std::ios::out);

			if (!file.is_open())
			{
				std::cout << "File not found." << std::endl;
			}
			else
			{
				for (size_t i = 0; i < input.length(); i++)
				{
					input[i] = input[i] += 1;
				}
				file << input << std::endl;
				
			}
			
		}

	}
	file.close();
}