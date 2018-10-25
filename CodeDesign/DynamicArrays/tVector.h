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
	void print();						// a print funtion for debug purposes

	T &at(size_t index);                // returns the element at the given element

	size_t size() const;                // returns current number of elements
	size_t capacity() const;            // returns maximum number of elements we can store
};

template <typename T>
tVector<T>::tVector() //Default constructor
{
	arr = new T[5];
	arrUsed = 0;
	arrCapacity = 5;

}

template <typename T>
tVector<T>::tVector(const tVector &vec) //Constructor
{
	//CHANGE THIS CONSTRUCTOR
	/*arr[0] = vec[0];
	arrUsed = 0;
	arrCapacity = vec.arrCapacity;*/
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
		

	}
	arr[arrUsed] = value;
	arrUsed++;
}

//https://stackoverflow.com/questions/28379457/reusing-a-pointer-after-delete
template <typename T>
void tVector<T>::reserve(size_t newCapacity)
{
	T* newArr = new T[newCapacity];
	for (size_t i = 0; i < arrCapacity; i++)
	{
		newArr[i] = arr[i];
		std::cout << newArr[i] << std::endl;
	}
	delete[] arr;
	arr = newArr;
	arrCapacity = newCapacity;
}

template <typename T>
T* tVector<T>::data() //NOT SURE IF THIS WORKS
{
	return arr;
}

template <typename T>
T& tVector<T>::at(size_t index) //Returns the value at the index
{
	return arr[index];
}

template <typename T>
tVector<T>& tVector<T>::operator = (const tVector &vec)
{

	for (size_t i = 0; i < arrCapacity; i++)
	{
		//std::cout << arr[i] << std::endl;
		//std::cout << vec.at(i) << std::endl;
		//arr[i] = vec.at(i);
	}
	
	return *this;
}

template <typename T>
void tVector<T>::print()
{
	std::cout << "===" << std::endl;
	for (size_t i = 0; i < arrCapacity; i++)
	{

		std::cout << arr[i] << std::endl;
		
	}
}