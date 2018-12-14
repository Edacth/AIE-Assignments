#pragma once
#include "raylib.h"
#undef PI;
#include "utils.h"
#include "vec2.h"
#include "waypoint.h"

class guard
{

public:
	vec2 position;
	vec2 startingPosition;
	waypoint* destination;
	bool foundDestination;
	float t;
	float lerpSpeed;
	guard();
	guard(vec2 _position);
	~guard();
	void update();
	void draw();

};