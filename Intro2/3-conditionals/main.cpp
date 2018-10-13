#include<iostream>

int main()
{
	char letter;
	char vowels[12] = {'A', 'E', 'I', 'O', 'U', 'Y', 'a', 'e', 'i', 'o', 'u', 'y'};
	bool isvowel = false;
	std::cout << "Please enter a letter." << std::endl;
	std::cin >> letter;


	while (!std::cin)
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');

		std::cout << "That's not recognized input. Please try again." << std::endl;
		std::cin >> letter;
	}

	//std::cout << (int)letter << std::endl;
	if (((int)letter >= 65 && (int)letter <= 90))
	{
		std::cout << "That is uppercase" << std::endl;
		for (int i = 0; i < sizeof(vowels); i++)
		{
			if (letter == vowels[i])
			{
				isvowel = true;
				std::cout << "That is a vowel" << std::endl;
				break;
			}
		}
		if (isvowel == false)
		{
			std::cout << "That is a consonant" << std::endl;
		}
	}
	else if (((int)letter >= 97 && (int)letter <= 122))
	{
		std::cout << "That is lowercase" << std::endl;
		for (int i = 0; i < sizeof(vowels); i++)
		{
			if (letter == vowels[i])
			{
				isvowel = true;
				std::cout << "That is a vowel" << std::endl;
				break;
			}
		}
		if (isvowel == false)
		{
			std::cout << "That is a consonant" << std::endl;
		}
	}
	else
	{
		std::cout << "That is not a letter" << std::endl;
	}
	return 0;

}