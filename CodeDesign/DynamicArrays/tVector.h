// tVector.h
#pragma once
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

template <typename T>
class tVector
{
	const static size_t GROWTH_FACTOR = 2;

	T *arr;                             // pointer to underlying array
	size_t arrUsed;                     // stores the number of elements currently used
	size_t arrCapacity;                 // stores the capacity of the underlying array

public:

	tVector();                          // initializes the vector's default values
	tVector(const tVector &vec);
	~tVector();                         // destroys the underlying array

	T *data();                          // returns a pointer to the underlying array

	tVector& operator=(const tVector &vec);
	T& operator[] (size_t index);

	void reserve(size_t newCapacity);   // resizes the vector to at least this many elements

	void push_back(const T &value);     // adds an element to the end of the vector
	void pop_back();                    // drops the last element of the vector
	void print();						// a print funtion for debug purposes
	bool empty();						// Returns true if the vector contains no elements.
	void resize(size_t);				// Resizes the vector to contain the given number of elements.
	void shrink_to_fit();				// Resizes the vector's capacity to match its size.
	void clear();						// Empties the vector (all elements are destroyed in this process)


	T &at(size_t index);                // returns the element at the given element
	const T& at(size_t index) const;    // returns the element at the given element

	size_t used() const;                // returns current number of elements
	size_t capacity() const;            // returns maximum number of elements we can store
};

template <typename T>
tVector<T>::tVector() //Default constructor
{
	arrCapacity = 5;
	arr = new T[arrCapacity];
	arrUsed = 0;
}

template <typename T>
tVector<T>::tVector(const tVector &vec) //Constructor
{

	*this = vec;
}

template <typename T>
tVector<T>::~tVector() //Deconstructor 
{
	delete[] arr;
}

template <typename T>
void tVector<T>::push_back(const T &value) //Adds a value to the array
{
	if (arrUsed == arrCapacity)
	{
		reserve(arrCapacity * GROWTH_FACTOR);

	}
	arr[arrUsed] = value;
	arrUsed++;
}

template <typename T>
void tVector<T>::pop_back() //Delete last element
{
	if (arrUsed > 0)
	{
		arrUsed--;
	}
	
}

template <typename T>
void tVector<T>::print() // a print funtion for debug purposes
{
	std::cout << "===" << std::endl;
	for (size_t i = 0; i < arrUsed; i++)
	{

		std::cout << arr[i] << std::endl;

	}
}

template <typename T>
bool tVector<T>::empty() 
{
	return (arrUsed == 0);
}

template <typename T>
void tVector<T>::resize(size_t newCapacity) //Creates a new array of the passed in size
{
	T* newArr = new T[newCapacity];
	if (arrUsed > newCapacity)
	{
		arrUsed = newCapacity;
	}
	for (size_t i = 0; i < arrUsed; i++)
	{
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = newArr;
	arrCapacity = newCapacity;
}

template <typename T>
void tVector<T>::shrink_to_fit() //Creates a new array with size equal to arrUsed
{
	T* newArr = new T[arrUsed];
	for (size_t i = 0; i < arrUsed; i++)
	{
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = newArr;
	arrCapacity = arrUsed;
}

template <typename T>
void tVector<T>::clear() //Empties the array by creating a new one
{
	T* newArr = new T[arrCapacity];
	delete[] arr;
	arr = newArr;
	arrUsed = 0;
}

template <typename T>
void tVector<T>::reserve(size_t newCapacity) //CREATES A NEW BIGGER ARRAY IF NEEDED
{
	T* newArr = new T[newCapacity];
	for (size_t i = 0; i < arrUsed; i++)
	{
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = newArr;
	arrCapacity = newCapacity;
}

template <typename T>
T* tVector<T>::data() //Returns a pointer to the array
{
	return arr;
}

template <typename T>
T& tVector<T>::at(size_t index) //Returns the value at the index
{
	return arr[index];
}

template<typename T>
inline const T & tVector<T>::at(size_t index) const //Const version of the above funtion
{
	return arr[index];
}

template <typename T>
tVector<T>& tVector<T>::operator = (const tVector &vec) //= operator overload
{
	reserve(vec.arrCapacity);
	arrUsed = vec.arrUsed;
	arrCapacity = vec.arrCapacity;

	for (size_t i = 0; i < arrCapacity; i++)
	{
		arr[i] = vec.arr[i];
	}
	return *this;
}

template <typename T>
T& tVector<T>::operator [] (size_t index) //subscript operator overload
{
	return at(index);
}

template <typename T>
size_t tVector<T>::capacity() const
{
	return arrCapacity;
}

template <typename T>
size_t tVector<T>::used() const
{
	return arrUsed;
}