#include "tObjectPool.h"


template <typename T>
tObjectPool::tObjectPool()
{
	freeCount = 20;
	usedCount = 0;
	T* free = new *T[freeCount];
	T* used = new *T[freeCount];
	for (size_t i = 0; i < freeCount; i++)
	{
		free[i] = {};
		used[i] = nullptr;
	}
	
}

template <typename T>
tObjectPool::~tObjectPool()
{
	delete[] free;
	delete[] used;
}

template <typename T>
tObjectPool::~tObjectPool()
{
}

template <typename T>
T* tObjectPool::retrieve()
{
	for (size_t i = 0; i < capacity(); i++)
	{
		if (free[i] != nullptr)
		{
			T* ptr = free[i];
			free[i] = nullptr;
			break;
		}
	}
	
	return ptr;
}

template <typename T>
size_t tObjectPool::capacity()
{
	return freeCount + usedCount;
}