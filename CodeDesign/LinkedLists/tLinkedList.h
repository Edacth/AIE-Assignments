//tLinkedList.h
#pragma once


template<typename T>
class tForwardList
{
	struct Node
	{
		T data;                     // data for the element stored
		Node * next;                // pointer to node following this node
	};
	
	class iterator
	{
		Node * cur;                                 // current node being operated upon

	public:
		iterator();
		iterator(const Node* start);

		bool operator==(const iterator& rhs) const; // returns true if the iterator points to the same node
		bool operator!=(const iterator& rhs) const; // returns false if the iterator does not point to the same node
		T& element() const;                       // returns a reference to the element pointed to by the current node
		iterator& operator++();                     // pre-increment (returns a reference to this iterator after it is incremented)
		iterator operator++(int);                   // post-increment (returns an iterator to current node while incrementing the existing iterator)
	};

	iterator begin();
	iterator end();
	
	Node * head;                    // pointer to head of linked list
	bool firstTime = true;			//Variable used to track if the first object is being inserted
	iterator iter;
public:
	tForwardList();                 // default constructor
	~tForwardList();                // destructor
	tForwardList(const tForwardList& other); //constructor being used to copy another list
	tForwardList& operator=(const tForwardList &rhs); // = operator overload

	void push_front(const T& val);  // adds element to front (i.e. head)
	void pop_front();               // removes element from front

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

template <typename T> 
tForwardList<T>::tForwardList(const tForwardList& other) //Constructor that copies another list
{
	
	Node* nodeIter = head;
	Node* otherNodeIter = other.head;
	Node* newNodePtr;
	while (otherNodeIter != nullptr)
	{
		Node* newNode = new Node;
		newNodePtr = newNode;
		newNode->data = { otherNodeIter->data };
		//std::cout << otherNodeIter->data << std::endl;
		otherNodeIter = otherNodeIter->next;
		newNode->next = head;
		head = newNode;
	}
}

template<typename T>
tForwardList<T>::~tForwardList() //Deconstructor
{

}

template <typename T>
tForwardList<T>& tForwardList<T>::operator = (const tForwardList &rhs) //= operator overload
{
	tForwardList(vec);
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
void tForwardList<T>::pop_front()
{
	Node* tempPointer;
	tempPointer = (head->next);
	delete head;
	head = tempPointer;
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
	iterator it(head);
	while (iter.curNode() != nullptr)
	{
		std::cout << (iter.element()) << std::endl;
		//iter.curNode() = iter.curNode().next;
		++iter;
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
	//I dont see a use for this funtion so it is TODO
}

/*
template<typename T>
bool tForwardList<T>::iterator::operator==(const iterator& rhs) const // returns true if the iterator points to the same node
{
	return (cur == rhs);

}
*/

template<typename T>
inline tForwardList<T>::iterator::iterator()
{
}

template<typename T>
inline tForwardList<T>::iterator::iterator(const Node* start)
{
	cur = start;
}

template<typename T>
bool tForwardList<T>::iterator::operator!=(const iterator& rhs) const // returns false if the iterator does not point to the same node
{
	return cur != rhs.cur;
}


template<typename T>
T& tForwardList<T>::iterator::element() const                      // returns a reference to the element pointed to by the current node
{
	return cur->data;
}

template<typename T>
typename tForwardList<T>::iterator& tForwardList<T>::iterator::operator++()
{
	cur = cur->next;
	// TODO: insert return statement here
	return *this;
}




/*
template<typename T>
tForwardList<T>::iterator& tForwardList<T>::iterator::operator++()                    // pre-increment (returns a reference to this iterator after it is incremented)
{

}


template<typename T>
tForwardList<T>::iterator tForwardList<T>::iterator::operator++(int)                 // post-increment (returns an iterator to current node while incrementing the existing iterator)
{

}
*/