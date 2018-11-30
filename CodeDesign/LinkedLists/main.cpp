#include "tLinkedList.h"
#include <iostream>


int main()
{
	//_crtBreakAlloc = 193;
	tForwardList<int> testList;
	//std::cout << testList.empty() << std::endl;
	//std::cout << testList.empty() << std::endl;
	testList.push_front(1);
	testList.push_front(2);
	testList.push_front(3);

	testList.push_back(100);
	
	//tForwardList<int> emptyList;

	testList.resize(10);
	//tForwardList<int> testList2(testList);
	//tForwardList<int> testList2 = testList;

	//testList.remove(3);
	//testList.print();
	//testList.clear();
	
	std::cout << std::endl;
	testList.print();
	std::cout << "=====" << std::endl;
	testList.push_front(5);
	testList.push_front(6);
	testList.print();

	testList.clear();
	return 0;
}