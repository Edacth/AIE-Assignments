#include "HighScoreTable.h"
#include "mergeSort.h"
#include <string>



int main()
{
	int testArr[] = { 3, 4, 1, 9, 7, 9 };

	MergeSort(testArr, 0, 5);

	for (size_t i = 0; i < 6; i++)
	{
		std::cout << testArr[i] << " ";
	}

	/*HighScoreTable hst("high2.txt");

	hst.pruneBottomNNScores(6);

	hst.printTable();*/

	/*std::vector<HighScoreEntry> topScores = hst.topNNScores(5);
	for (std::vector<HighScoreEntry>::iterator invIte = topScores.begin(); invIte != topScores.end(); invIte++)
	{
		std::cout << invIte->name << "," << invIte->score << "," << invIte->level << std::endl;
	}*/
	return 0;
}
