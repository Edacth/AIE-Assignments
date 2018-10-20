#pragma once
#include "raylib.h"
#include <math.h>
#include "raylib.h"

class dialFace
{
public:
	Vector2 position;
	 Vector2 endingPoint;
	 float radius;
	 float currentAngle;
	 float speed;
	 void drawFace();
	void tick();
	dialFace();
	dialFace(float _x, float _y, float _radius, float speed);
	~dialFace();
};

//STATIC IS EVIL

/*static float currentAngle;
class dialFace
{
public:
	static Vector2 position;
	static Vector2 endingPoint;
	static float radius;
	static void drawFace();
	void tick();
	dialFace();
	dialFace(float _x, float _y, float _radius);
	~dialFace();
};*/

