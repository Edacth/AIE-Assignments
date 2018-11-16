#include "HighScoreTable.h"
#include "mergeSort.h"
#include <string>



int main()
{
	std::cout << "1 for bubble sort, 2 for merge sort, 3 for high score table sort" << std::endl;
	int input;
	std::cin >> input;
	switch (input )
	{
	case 1:
	{
		int testArr[] = { 3, 4, 1, 9, 11, 23, 7, 9 };
		int arrSize = 8;

		for (size_t i = 0; i < arrSize - 1; i++)
		{
			for (size_t j = arrSize - 1; j > i; j--)
			{
				if (testArr[j] < testArr[j - 1])
				{
					int tempScore = testArr[j - 1];
					testArr[j - 1] = testArr[j];
					testArr[j] = tempScore;
				}
				//std::cout << "i = " << i << " j = " << j << std::endl;
				

			}
		}

		for (size_t i = 0; i < arrSize; i++)
		{
			std::cout << testArr[i] << " ";
		}
		break;
	}
	case 2:
	{
		int testArr[] = { 3, 4, 1, 9, 11, 23, 7, 9 };
		int arrSize = 8;

		MergeSort(testArr, 0, arrSize - 1);

		for (size_t i = 0; i < arrSize; i++)
		{
			std::cout << testArr[i] << " ";
		}
		break;
	}
	case 3:
	{
		HighScoreTable hst("high2.txt");

		hst.pruneBottomNNScores(6);

		hst.printTable();

		std::vector<HighScoreEntry> topScores = hst.topNNScores(5);
		/*for (std::vector<HighScoreEntry>::iterator invIte = topScores.begin(); invIte != topScores.end(); invIte++)
		{
		std::cout << invIte->name << "," << invIte->score << "," << invIte->level << std::endl;
		}*/
		break;
	}
	default:
		break;
	}
	

	
	return 0;
}
