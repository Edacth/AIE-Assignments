#include "tLinkedList.h"
#include <iostream>


int main()
{
	tForwardList<int> testList;
	testList.push_front(3);
	testList.push_front(1);
	testList.push_front(3);
	testList.push_front(2);
	testList.push_front(3);
	testList.push_front(3);
	testList.push_front(4);
	testList.push_front(3);
	testList.push_front(3);
	testList.push_front(3);

	//tForwardList<int> testList2 = {testList};

	testList.remove(3);
	testList.print();
	return 0;
}