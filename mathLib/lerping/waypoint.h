#pragma once
#include "raylib.h"
#undef PI;
#include "utils.h"
#include "vec2.h"

class waypoint
{
	

public:
	vec2 position;
	waypoint* nextPoint;
	waypoint();
	waypoint(vec2 _position, waypoint* _nextPoint);
	~waypoint();
	void update();
	void draw();

};