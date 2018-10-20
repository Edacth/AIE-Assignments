//main.cpp
#include "Item.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

std::vector<std::string> split(std::string& line);
int main() {
	std::vector <Item> inventory;
	std::fstream file("Inventory.txt", std::ios::in);
	std::string buffer;
	std::vector <std::string> rtn;
	Item tmpItem("");
	while (std::getline(file, buffer))  // iterates until error or EOF
	{
		rtn = split(buffer);
		tmpItem.quality = std::stof(rtn.back());
		rtn.pop_back();
		tmpItem.cost = std::stoi(rtn.back().c_str());
		rtn.pop_back();
		tmpItem.fluff = rtn.back();
		rtn.pop_back();
		tmpItem.name = rtn.back();
		rtn.pop_back();
		inventory.push_back(tmpItem);

	}
	file.close();

	for (std::vector<Item>::iterator invIte = inventory.begin(); invIte != inventory.end(); invIte++)
	{
		std::cout << invIte->name << "," << invIte->fluff << "," << invIte->cost << "," << invIte->quality << std::endl;
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