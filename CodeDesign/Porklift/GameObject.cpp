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

Rectangle* GameObject::getRectangle()
{
	return &rectangle;
}

void GameObject::setPosition(Vector2 _position)
{
	position = _position;
}

Vector2* GameObject::getPosition()
{
	return &position;
}

bool GameObject::push(Vector2 direction)
{
	return true;
}