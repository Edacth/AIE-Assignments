#include <iostream>
#include "review2.h"
#include <string>

int wordCount(std::string str)
{
	int count = 0;
	int length = str.length();
	int worldLength = false;
	str = str + " ";
	for (int i = 0; i < length; i++)
	{
		if (str[i + 1] == ' ' && str[i] != ' ')
		{
			count++;
		}
		/*
		if (str[i] != ' ')
		{
			worldLength++;
		}
		if (worldLength > 0 && str[i] != ' ')
		{
			count++;
		}
		*/
	}

	std::cout << count << std::endl;
	return count;
}

void wordWrap(std::string str)
{
	int j = 0;
	for (int i = 0; str[i] != 0; i++)
	{
		std::cout << str[i];
		j++;
		if (j >= 80)
		{
			std::cout << std::endl;
			j = 0;
		}
	}
}