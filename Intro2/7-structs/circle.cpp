#include <iostream>
#include "circle.h"
#include <cmath>

bool findCollision(circle circle1, circle circle2)
{
	bool isCollision = false;
	float distance = 0;
	distance = (float)sqrt(pow((circle2.pos.x - circle1.pos.x), 2) + pow((circle2.pos.y - circle1.pos.y), 2));
	std::cout << distance << std::endl;

	if (distance < circle2.radius + circle1.radius)
	{
		isCollision = true;
	}
	return isCollision;
}