#include <iostream>
#include "quiz.h"
#include "fives.h"
#include "candles.h"
#include "rotation.h"



int main()
{
	//quiz();
	int candles[6] = { 3, 3, 2, 4, 3, 5 };
	//printFives(2, 6);

	//blow(candles, 6);

	rotate(candles, 6, 1);

	for (int i = 0; i < 6; i++)
	{
		std::cout << candles[i] << std::endl;
	}
	return 0;
}