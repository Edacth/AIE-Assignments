// tVector.h
#pragma once

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

	T &at(size_t index);                // returns the element at the given element

	size_t size() const;                // returns current number of elements
	size_t capacity() const;            // returns maximum number of elements we can store
};

template <typename T>
tVector<T>::tVector()
{
	arr = new T[10];
	arrUsed = 0;
	arrCapacity = 10;

}

template <typename T>
tVector<T>::tVector(const tVector &vec)
{
	//CHANGE THIS CONSTRUCTOR
	/*arr[0] = vec[0];
	arrUsed = 0;
	arrCapacity = vec.arrCapacity;*/
}

template <typename T>
tVector<T>::~tVector()
{
	delete[] arr;
}

template <typename T>
void tVector<T>::push_back(const T &value)
{
	if (arrUsed == arrCapacity)
	{
		

	}
	arr[arrUsed] = value;
	arrUsed++;
}

template <typename T>
T* data()
{
	return arr;
}

template <typename T>
T& tVector<T>::at(size_t index)
{
	return arr[index];
}