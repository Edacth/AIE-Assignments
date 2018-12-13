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

void GameObject::setPosition(vec2 _position)
{
	position = _position;
}

vec2* GameObject::getPosition()
{
	return &position;
}