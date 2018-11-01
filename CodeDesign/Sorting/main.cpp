#include "HighScoreTable.h"
#include <fstream>
#include <string>
#include <sstream>

std::vector<std::string> split(std::string& line);
int main()
{
	HighScoreTable hsTable;
	std::string filePath = "high2.txt";
	std::fstream file(filePath, std::ios::in);
	std::string buffer;
	std::vector <std::string> rtn;

	HighScoreEntry tmpEntry;
	while (std::getline(file, buffer))  // iterates until error or EOF
	{
		rtn = split(buffer);
		//std::cout << "Back: " << rtn.back() << std::endl;
		std::string temp = (rtn.back());
		tmpEntry.level = std::stoi(rtn.back());
		rtn.pop_back();
		tmpEntry.score = std::stoi(rtn.back().c_str());
		rtn.pop_back();
		tmpEntry.name = rtn.back();
		rtn.pop_back();
		hsTable.hsVector.push_back(tmpEntry);

	}
	file.close();

	hsTable.sortAccending();

	for (std::vector<HighScoreEntry>::iterator invIte = hsTable.hsVector.begin(); invIte != hsTable.hsVector.end(); invIte++)
	{
		std::cout << invIte->name << "," << invIte->score << "," << invIte->level << std::endl;
	}

	return 0;
}

std::vector<std::string> split(std::string& line)
{
	std::vector<std::string> result;
	std::stringstream lineStream(line);
	std::string cell;
	while (std::getline(lineStream, cell, ','))
		result.push_back(cell);
	if (!lineStream && cell.empty())
		result.push_back("");
	return result;
}