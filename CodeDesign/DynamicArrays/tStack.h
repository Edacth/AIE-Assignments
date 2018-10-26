// tStack.h
#pragma once
#include "tVector.h"

template <typename T>
class tStack
{
	tVector<T> vec;                     // contains the data for a stack

public:
	tStack();                           // initializes the stack's default values
	~tStack();

	void push(const T& value);          // adds an element to the top of the Stack
	void pop();                         // drops the top-most element of the Stack
	

	T& top();                           // returns the top-most element at the given element
	const T& top() const;
	size_t size();
	bool empty() const;

	size_t size() const;                // returns current number of elements
};
template <typename T>
tStack<T>::tStack()
{

}

template <typename T>
tStack<T>::~tStack()
{

}

template <typename T>
void tStack<T>::push(const T& value)
{
	vec.push_back(value);
}

template <typename T>
void tStack<T>::pop()
{
	vec.pop_back();
}

template <typename T>
T& tStack<T>::top()
{
	return vec[vec.used() - 1];
}

template <typename T>
const T& tStack<T>::top() const
{
	return vec[vec.used() - 1];
}

template <typename T>
size_t tStack<T>::size()
{
	return vec.used();
}

template <typename T>
inline bool tStack<T>::empty() const
{
	return (vec.used() == 0);

}