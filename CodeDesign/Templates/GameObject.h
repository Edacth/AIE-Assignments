#pragma once
#include <iostream>
#include "raylib.h"

template <typename T>
class GameObject
{
public:
	GameObject(T*  _object)
	{
		object = _object;
	}
	GameObject(T&  _object)
	{
		object =  &_object;
	}
	~GameObject() {};
	bool enabled;   // is this gameObject enabled?
	T * object;     // pointer to underlying instance of type T

	void update()
	{
		(*object).update();
	}

	void render()
	{
		(*object).render();
	}


	// todo: What else would you need to include in this class declaration?
};



/*
template<typename T>
void GameObject<T>::update()
{
	std::cout << "UPDATE." << std::endl;
}

template<typename T>
void GameObject<T>::render()
{
	std::cout << "RENDER." << std::endl;
}
*/