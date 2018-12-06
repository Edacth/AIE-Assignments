#include "vec2.h"
#include <cfloat>

vec2::vec2()
{
}

vec2::vec2(float _x, float _y)
{
	x = _x;
	y = _y;
}

vec2 vec2::operator+(const vec2 &rhs) const
{
	return {x + rhs.x, y + rhs.y};
}

vec2 vec2::operator-(const vec2 &rhs) const
{
	return { x - rhs.x, y - rhs.y };
}

vec2& vec2::operator+=(const vec2 &rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

vec2& vec2::operator-=(const vec2 &rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

bool vec2::operator==(const vec2 &rhs) const
{
	float errorMargin = FLT_EPSILON * 100;
	return (x - rhs.x < errorMargin && y - rhs.y < errorMargin) ? true : false;
}

bool vec2::operator!=(const vec2 &rhs) const
{
	float errorMargin = FLT_EPSILON * 100;
	return (x - rhs.x < errorMargin && y - rhs.y < errorMargin) ? false : true;
}

vec2 vec2::operator-() const
{
	return {x * -1, y * -1};
}

vec2::operator float *()
{
	return &x;
}

vec2::operator const float *() const
{
	return &x;
}

vec2::Vector2()
{

}