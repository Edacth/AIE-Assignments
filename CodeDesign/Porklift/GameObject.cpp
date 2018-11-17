#include "GameObject.h"

GameObject::GameObject()
{

}

GameObject::~GameObject()
{

}

void GameObject::update()
{
}

void GameObject::draw()
{
	DrawRectangleV(position, { 30, 30 }, GREEN);
}