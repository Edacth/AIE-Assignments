#include <string>
#include "STL-String.h"
#include <iostream>

void everyOther(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		i++;
		std::cout << str[i];

	}

}

void bestow(std::string str)
{
	if (str == "Terry")
	{
		str = str + ", the Terminator";
	}
	else
	{
		str = str + ", the Pleb";
	}

	std::cout << str << std::endl;
}

void charCount(std::string str, char letter)
{
	int count = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == letter)
		{
			count++;
		}
		
	}
	std::cout << count << std::endl;
}

int instanceCount(std::string str, std::string snippet)
{
	
	int count = 0;
	for (int i = 0; i < str.length(); i++)
	{
		int pos = str.find(snippet, i);
		//std::cout << pos << std::endl;
		if (pos > -1)
		{
			i = pos;
			//std::cout << str.substr(i, (str.length() - i) ) << std::endl;
			count++;
		}
	}
	std::cout << count << std::endl;
	return count;
}