#include "tLinkedList.h"
#include <iostream>


int main()
{
	//_crtBreakAlloc = 193;
	tForwardList<int> testList;
	//std::cout << testList.empty() << std::endl;
	testList.push_front(3);
	//std::cout << testList.empty() << std::endl;
	testList.push_front(1);
	testList.push_front(3);
	testList.push_front(2);
	testList.push_front(3);
	testList.push_front(3);
	testList.push_front(4);
	testList.push_front(3);
	testList.push_front(3);
	testList.push_front(3);
	testList.push_front(9);
	testList.push_front(9);
	

	tForwardList<int> testList2(testList);

	//testList.remove(3);
	//testList.print();
	//testList.clear();
	
	std::cout << std::endl;
	testList.print();
	std::cout << "=====" << std::endl;
	testList2.print();

	testList.clear();
	_CrtDumpMemoryLeaks();
	return 0;
}