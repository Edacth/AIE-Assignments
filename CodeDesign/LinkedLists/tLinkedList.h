//tLinkedList.h
#pragma once
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

template<typename T>
class tForwardList
{
	struct Node
	{
		T data;										// data for the element stored
		Node * next;								// pointer to node following this node
	};
	
	class iterator
	{
		Node * cur;                                 // current node being operated upon

	public:
		iterator();
		iterator(Node* start);

		bool operator==(const iterator& rhs) const; // returns true if the iterator points to the same node
		bool operator!=(const iterator& rhs) const; // returns false if the iterator does not point to the same node
		T& element() const;                         // returns a reference to the element pointed to by the current node
		Node node();								// returns are reference to the node occupied by this iterator
		iterator& operator++();                     // pre-increment (returns a reference to this iterator after it is incremented)
		iterator operator++(int);                   // post-increment (returns an iterator to current node while incrementing the existing iterator)
	};

	iterator begin();
	iterator end();
	
	Node* head;                    // pointer to head of linked list

	bool firstTime = true;			//Variable used to track if the first object is being inserted
	iterator iter;
public:
	tForwardList();                 // default constructor
	~tForwardList();                // destructor
	tForwardList(const tForwardList& other); //constructor being used to copy another list
	tForwardList& operator=(const tForwardList &rhs); // = operator overload

	void push_front(const T& val);  // adds element to front (i.e. head)
	void push_back(const T& val);	// adds element to back (i.e. tail)
	void pop_front();               // removes element from front
	void pop_back();               // removes element from front

	T& front();                     // returns the element at the head
	const T& front() const;         // returns the element at the head (const)

	void remove(const T& val);      // removes all elements equal to the given value
	void print();					//Prints the list for debug purposes
	bool empty() const;             // Returns true if there are no elements
	void clear();                   // Destroys every single node in the linked list
	void resize(size_t newSize);    // Resizes the linked list to contain the given number of elements
									// New elements are default-initialized
};



template<typename T>
tForwardList<T>::tForwardList() //Default constructor
{
	head = nullptr;
}

/*THIS IS UNUSED AS OF NOW. IT MAY BE NEEDED LATER. I AM NOT SURE.*/
//template<typename T>
//tForwardList<T>::tForwardList<int>() //Default constructor for ints
//{
//	head = nullptr;
//	data = 0;
//}

template <typename T> 
tForwardList<T>::tForwardList(const tForwardList& other) //Constructor that copies another list
{
	*this = other;
	
}


template<typename T>
tForwardList<T>::~tForwardList() //Destructor
{

	if (head == nullptr) {
		return;
	}

	Node * it = head;
	while (it->next != nullptr)
	{
		head = it;
		it = it->next;
		delete head;
	}
	delete it;
}

template <typename T>
tForwardList<T>& tForwardList<T>::operator = (const tForwardList &rhs) //= operator overload
{
	/*tForwardList(vec);
	return *this;*/


	Node* rhsNodeIter = rhs.head;
	if (rhs.head == nullptr)
	{
		return *this;
	}
	head = new Node{ rhs.head->data, nullptr };
	Node* temp = head;//Creates a node
	rhsNodeIter = rhsNodeIter->next;
	while (rhsNodeIter != nullptr)
	{
		Node* newNode = new Node;
		newNode->next = nullptr;
		newNode->data = { rhsNodeIter->data };//Copes data from other node to new node
		head->next = newNode;
		head = newNode;
		rhsNodeIter = rhsNodeIter->next;//Move other node to next node
											/*newNode = new Node;
											newNodePtr->next = newNode;
											head = newNode;*/
											//delete newNode;
	}
	head = temp;

	return *this;
}

template<typename T>
void tForwardList<T>::push_front(const T& val) //adds element to front (i.e. head)
{
	Node * newNode = new Node;
	newNode->data = { val };
	newNode->next = head;
	head = newNode;
	
}

template<typename T>
void tForwardList<T>::push_back(const T& val) // adds element to back (i.e. tail)
{
	Node * it = head;
	while (it->next != nullptr)
	{
		it = it->next;
		
	}

	Node * newNode = new Node;
	newNode->data = val;
	newNode->next = nullptr;

	it->next = newNode;

	//delete it;

}

template<typename T>
void tForwardList<T>::pop_front()
{
	Node* tempPointer;
	tempPointer = (head->next);
	delete head;
	head = tempPointer;
}

template<typename T>
void tForwardList<T>::pop_back()
{
	Node * it = head;
	while (it->next->next != nullptr)
	{
		it = it->next;

	}

	delete it->next;

	it->next = nullptr;
}

template<typename T>
T& tForwardList<T>::front()
{
	return head->data;
}

template<typename T>
const T& tForwardList<T>::front() const
{
	return head->data;
}

template<typename T>
void tForwardList<T>::remove(const T & val)
{
	Node *itNode = head;
	while ( itNode->next != nullptr) {
		if (itNode->data == val) {
			std::cout << "Popping front " << front() << std::endl;
			pop_front();
			itNode = head;
		}
		else if (itNode->next->data == val) {
			Node *tempNode = itNode->next->next;
			std::cout << "Popping " << itNode->next->data << std::endl;
			delete itNode->next;
			itNode->next = tempNode;
		}
		else { itNode = itNode->next; }
	}
}


template<typename T>
void tForwardList<T>::print()
{
	//iter.curNode() = head;
	iterator it(begin());
	while (it != end())
	{
		std::cout << (it.element()) << std::endl;
		//iter.curNode() = iter.curNode().next;
		++it;
		//it++;
	}
}

template<typename T>
bool tForwardList<T>::empty() const
{
	return (head == nullptr);
}

template<typename T>
void tForwardList<T>::clear()
{
	
	while (head != nullptr)
	{
		pop_front();
	}
}

template<typename T>
void tForwardList<T>::resize(size_t size)
{
	int count = 0;
	iterator it(begin());
	while (it != end())
	{
		count++;
		++it;
	}
	if (count < size)
	{
		for (size_t i = count; i < size; i++)
		{
			push_back(0);
		}
		
	}
	else if (count > size)
	{
		for (size_t i = 0; i < count - size; i++)
		{
			pop_back();
		}
	}

}


template<typename T>
bool tForwardList<T>::iterator::operator==(const iterator& rhs) const // returns true if the iterator points to the same node
{
	return (cur == rhs);

}


template<typename T>
inline tForwardList<T>::iterator::iterator()
{
}

template<typename T>
inline tForwardList<T>::iterator::iterator(Node* start)
{
	cur = start;
}

template<typename T>
bool tForwardList<T>::iterator::operator!=(const iterator& rhs) const // returns false if the iterator does not point to the same node
{
	return cur != rhs.cur;
}


template<typename T>
T& tForwardList<T>::iterator::element() const              // returns a reference to the element pointed to by the current node
{
	return cur->data;
}

template<typename T>
typename tForwardList<T>::Node tForwardList<T>::iterator::node()
{
	return cur;
}

template<typename T>
typename tForwardList<T>::iterator& tForwardList<T>::iterator::operator++()
{
	cur = cur->next;
	return *this;
}

template<typename T>
typename tForwardList<T>::iterator tForwardList<T>::begin()
{
	return head;
}

template<typename T>
typename tForwardList<T>::iterator tForwardList<T>::end()
{
	iterator nullIter(nullptr);
	return nullIter;
}

template<typename T>
typename tForwardList<T>::iterator tForwardList<T>::iterator::operator++(int)                 // post-increment (returns an iterator to current node while incrementing the existing iterator)
{
	Node* temp = cur;
	cur = cur->next;
	return temp;
}