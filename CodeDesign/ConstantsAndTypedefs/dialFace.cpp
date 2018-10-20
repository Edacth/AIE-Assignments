#include "dialFace.h"
//
//float dialFace::radius;
//float dialFace::currentAngle;
//Vector2 dialFace::position;
//Vector2 dialFace::endingPoint;

dialFace::dialFace()
{

}

dialFace::dialFace(float _x, float _y, float _radius, float _speed)
{
	position = { _x, _y };
	radius = _radius;
	currentAngle = 0;
	speed = _speed;

}


dialFace::~dialFace()
{
}

void dialFace::tick()
{
	currentAngle = currentAngle + speed;
}

void dialFace::drawFace()
{
	float slope = 0;
	float rise = 0;
	float run = 0;

	//Trig Calculations


	endingPoint = { (position.x + radius * (float)cos(currentAngle)), (position.y + radius * (float)sin(currentAngle)) };

	DrawCircleLines(position.x, position.y, radius, WHITE);
	DrawLineEx(position, endingPoint, 3, RED);
}