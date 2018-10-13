#pragma once

struct vector2D
{
	int x;
	int y;
};

struct circle {
	vector2D pos;
	float radius;

};

bool findCollision(circle circle1, circle circle2);