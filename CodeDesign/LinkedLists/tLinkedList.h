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

	Node * head;                    // pointer to head of linked list
	bool firstTime = true;
public:
	tForwardList();                 // default constructor
	~tForwardList();                // destructor

	void push_front(const T& val);  // adds element to front (i.e. head)
	void pop_front();               // removes element from front

	tForwardList(const tForwardList& other);
	//tForwardList& operator=(const tForwardList &rhs);

	T& front();                     // returns the element at the head
	const T& front() const;               // returns the element at the head (const)

	void remove(const T& val);      // removes all elements equal to the given value
	void print();
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
		newNode->data = { val };
		//std::cout << otherNodeIter->data << std::endl;
		otherNodeIter = otherNodeIter->next;
	}
}

template<typename T>
tForwardList<T>::~tForwardList() //Deconstructor
{

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
	for (Node *itNode = head->next; itNode != nullptr; itNode = itNode->next) {
		if (head->data == val) {
			pop_front();
		}
		if (itNode->data == val) {
			Node *tempNode = itNode->next;
			itNode->next = itNode->next->next;
			delete tempNode;
		}
	}
}



template<typename T>
void tForwardList<T>::print()
{
	Node* currentNode = head; 
	while (currentNode != nullptr)
	{
		std::cout << currentNode->data << std::endl;
		currentNode = currentNode->next;
	}
}