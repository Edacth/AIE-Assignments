#include <iostream>
#include "C-String.h"

void topper(char* str, int length)
{

	for (size_t i = 0; i < length; i++)
	{
		str[i] = toupper(str[i]);
	}

}

void removeWhites(char* str)
{
	int length = strlen(str);
	int newStr[20];
	int j = 0;
	for (int i = 0; i < length + 1; i++)
	{
		if (str[i] != ' ')
		{
			std::cout << "i: " << i << " j: " << j << " char: " << str[j] << " <- " << str[i] << std::endl;
			newStr[j] = str[i];
			j++;

		}
		else
		{

		}

	}

	for (int i = 0; i < length; i++)
	{
		str[i] = newStr[i];
	}

}

void substring(char*newStr, char* oldStr, int start, int end)
{
	int j = 0;
	for (int i = start; i < end; i++)
	{
		newStr[j] = oldStr[i];
		j++;
	}
	newStr[j] = 0;
}

void shiftCipher(char* newStr, char* oldStr, int shift)
{
	int length = strlen(oldStr);
	int j = 0;
	for (int i = 0; i < length; i++)
	{
		if ( ((int)oldStr[i] >= 65 && (int)oldStr[i] <= 90) )
		{
			newStr[i] = oldStr[i] += shift;
			if ((int)oldStr[i] > 90)
			{
				oldStr[i] -= 26;
			}
			else if ((int)oldStr[i] < 65)
			{
				oldStr[i] += 26;
			}

		}
		else if ( ((int)oldStr[i] >= 97 && (int)oldStr[i] <= 122) )
		{
			newStr[i] = oldStr[i] += shift;
			if ((int)newStr[i] > 122)
			{
				newStr[i] -= 26;
			}
			else if ((int)newStr[i] < 97)
			{
				newStr[i] += 26;
			}
		}
		else
		{
			newStr[i] = oldStr[i];
		}
		j = i;
	}
	newStr[j + 1] = 0;
}