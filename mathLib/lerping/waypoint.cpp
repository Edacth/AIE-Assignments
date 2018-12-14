#include "waypoint.h"

waypoint::waypoint()
{
	position = { 100, 100 };
}

waypoint::waypoint(vec2 _position, waypoint* _nextPoint)
{
	position = _position;
	nextPoint = _nextPoint;
}

waypoint::~waypoint()
{
}

void waypoint::update()
{

}

void waypoint::draw()
{
	DrawCircleV(position, 5, BLACK);
}