#pragma once
#include <iostream>
#include "raylib.h"

template <typename T>
class GameObject
{
	bool enabled;   // is this gameObject enabled?
	Vector2 position; //Position of this object
	T * object;     // pointer to underlying instance of type T

public:

	GameObject(T*  _object) //Constructor
	{
		object = _object;
	}
	GameObject(T&  _object) //Constructor
	{
		object =  &_object;
	}
	~GameObject() {}; //Deconstructor
	

	void update() 
	{
		(*object).update();
	}

	void draw()
	{
		(*object).draw();
	}


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