// tObjectPool.h
#pragma once
#include <vector>

template <typename T>
class tObjectPool
{
public:
	tObjectPool();                       // default initializes the object pool
	tObjectPool(size_t initialCapacity); // initializes the pool to have a set number of objects
	~tObjectPool();                      // destroys all objects

	T* retrieve();                      // returns a pointer to an object that will be used (returns null if none available)
	void recycle(T* obj);               // accepts a pointer that can be used in the future
	T* pool;
	T** ageSortPool;
	int* objectAge;
	bool* getFree();					//returns a pointer to the free array
	int freeCount();					//Returns the number of free objects
	void ageInsertionSort();			//Sorts the pool in descending order by age
	size_t getCapacity();               // returns the total number of objects that this pool can provide
	void updateAge();

private:
	Texture2D * textureMasters;
										// pointers to objects that are currently in use
	size_t capacity;                    // number of objects that are free to use
	bool* free;
	void init();

};

template <typename T>
tObjectPool<T>::tObjectPool(size_t initialCapacity)
{

	capacity = initialCapacity;
	pool = new T[capacity];
	free = new bool[capacity];
	objectAge = new int[capacity];
	ageSortPool = new T*[capacity];
	for (size_t i = 0; i < capacity; i++)
	{
		free[i] = true;
		objectAge[i] = 0;
		ageSortPool[i] = &pool[i];
	}

	textureMasters = new Texture2D[8];
	textureMasters[0] = LoadTexture("resources/spaceBuilding_007.png");
	textureMasters[1] = LoadTexture("resources/spaceBuilding_001.png");
	textureMasters[2] = LoadTexture("resources/spaceBuilding_003.png");
	textureMasters[3] = LoadTexture("resources/spaceBuilding_020.png");
	textureMasters[4] = LoadTexture("resources/spaceMeteors_001.png");
	textureMasters[5] = LoadTexture("resources/spaceMeteors_002.png");
	textureMasters[6] = LoadTexture("resources/spaceMeteors_003.png");
	textureMasters[7] = LoadTexture("resources/spaceMeteors_004.png");
}

template <typename T>
tObjectPool<T>::tObjectPool()
{
	capacity = 20;
	pool = new T[capacity];
	free = new bool[capacity];
	objectAge = new int[capacity];
	ageSortPool = new T*[capacity];
	for (size_t i = 0; i < capacity; i++)
	{
		free[i] = true;
		objectAge[i] = 0;
		ageSortPool[i] = &pool[i];
	}

	textureMasters = new Texture2D[8];
	textureMasters[0] = LoadTexture("resources/spaceBuilding_007.png");
	textureMasters[1] = LoadTexture("resources/spaceBuilding_001.png");
	textureMasters[2] = LoadTexture("resources/spaceBuilding_003.png");
	textureMasters[3] = LoadTexture("resources/spaceBuilding_020.png");
	textureMasters[4] = LoadTexture("resources/spaceMeteors_001.png");
	textureMasters[5] = LoadTexture("resources/spaceMeteors_002.png");
	textureMasters[6] = LoadTexture("resources/spaceMeteors_003.png");
	textureMasters[7] = LoadTexture("resources/spaceMeteors_004.png");
}

template <typename T>
tObjectPool<T>::~tObjectPool()
{
	delete[] pool;
	delete[] free;
	delete[] objectAge;
	delete[] ageSortPool;
}

template <typename T>

T* tObjectPool<T>::retrieve()
{
	T* ptr = nullptr;
	for (size_t i = 0; i < capacity; i++)
	{
		if (free[i] == true)
		{
			ptr = &pool[i];
			free[i] = false;
			break;
		}
	}

	if (ptr == nullptr)
	{
		ageInsertionSort();
		ptr = ageSortPool[0];
		objectAge[0] = 0;
	}

	int spriteValue = GetRandomValue(0, 7);
	float scale = 1;
	std::string sprType;
	if (spriteValue >= 0 && spriteValue <= 3)
	{
		sprType = "debris";
		scale = 0.5f;
	}
	else if (spriteValue >= 4 && spriteValue <= 7)
	{
		sprType = "rock";
		scale = 0.2f;
	}
	ptr->Init({ (float)GetRandomValue(0, 800), -10 }, textureMasters[spriteValue], sprType, scale);
	//{ { (float)GetRandomValue(0, 800), -10 }, textureMasters[spriteValue], sprType, scale };

	return ptr;
}

template <typename T>
void tObjectPool<T>::recycle(T* obj)
{
	for (size_t i = 0; i < capacity; i++)
	{
		if (&pool[i] == obj)
		{
			free[i] = true;
			objectAge[i] = 0;
		}
	}
}

template <typename T>
size_t tObjectPool<T>::getCapacity()
{
	return capacity;
}

template <typename T>
bool* tObjectPool<T>::getFree()
{
	return free;
}

template <typename T>
void tObjectPool<T>::ageInsertionSort()
{
	for (size_t i = 1; i < capacity; i++)
	{
		int ageKey = objectAge[i];
		T** memLocation = &ageSortPool[i];
		/*std::string sprTypeKey = pool[i].sprType;
		float scaleKey = pool[i].scale;
		float rotKey = pool[i].rot;
		Texture2D textureKey = pool[i].texture;
		Vector2 posKey = pool[i].pos;*/
		int j = i - 1;
		while (j >= 0 && objectAge[j] < ageKey)
		{
			ageSortPool[j + 1] = ageSortPool[j];
			objectAge[j + 1] = objectAge[j];
			/*pool[j + 1].age = pool[j].age;
			pool[j + 1].sprType = pool[j].sprType;
			pool[j + 1].scale = pool[j].scale;
			pool[j + 1].rot = pool[j].rot;
			pool[j + 1].texture = pool[j].texture;
			pool[j + 1].pos = pool[j].pos;*/

			j = j - 1;
			ageSortPool[j + 1] = *memLocation;
			objectAge[j + 1] = ageKey;
			/*pool[j + 1].age = ageKey;
			pool[j + 1].sprType = sprTypeKey;
			pool[j + 1].scale = scaleKey;
			pool[j + 1].rot = rotKey;
			pool[j + 1].texture = textureKey;
			pool[j + 1].pos = posKey;*/
		}
	}
	for (size_t i = 0; i < capacity; i++)
	{
		DrawText((std::to_string(objectAge[i])).c_str(), 10, 40 + (i * 22), 20, BLACK);
	}
	
}

template <typename T>
int tObjectPool<T>::freeCount()
{
	int count = 0;
	for (size_t i = 0; i < capacity; i++)
	{
		if (free[i] == true)
		{
			count++;
		}
	}
	return count;
}

template <typename T>
void tObjectPool<T>::updateAge()
{
	DrawCircleV(ageSortPool[0]->pos, 15, RED);
	for (size_t i = 0; i < capacity; i++)
	{
		if (!free[i])
		{
			objectAge[i]++;
			DrawText((std::to_string(objectAge[i])).c_str(), pool[i].pos.x, pool[i].pos.y, 10, BLACK);
			
		}
		
	}
}