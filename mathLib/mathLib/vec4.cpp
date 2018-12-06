#include "vec4.h"
#include <cfloat>

vec4::vec4()
{
}

vec4::vec4(float _w, float _x, float _y, float _z)
{
	w = _w;
	x = _x;
	y = _y;
	z = _z;
}

vec4 vec4::operator+(const vec4 &rhs) const
{
	return {w + rhs.w, x + rhs.x, y + rhs.y, z + rhs.z };
}

vec4 vec4::operator-(const vec4 &rhs) const
{
	return {w - rhs.w, x - rhs.x, y - rhs.y, z - rhs.z };
}

vec4& vec4::operator+=(const vec4 &rhs)
{
	w += rhs.w;
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

vec4& vec4::operator-=(const vec4 &rhs)
{
	w -= rhs.w;
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

bool vec4::operator==(const vec4 &rhs) const
{
	float errorMargin = FLT_EPSILON * 100;
	return (w - rhs.w < errorMargin && x - rhs.x < errorMargin && y - rhs.y < errorMargin && z - rhs.z < errorMargin) ? true : false;
}

bool vec4::operator!=(const vec4 &rhs) const
{
	float errorMargin = FLT_EPSILON * 100;
	return (w - rhs.w < errorMargin && x - rhs.x < errorMargin && y - rhs.y < errorMargin && z - rhs.z < errorMargin) ? false : true;
}

vec4 vec4::operator-() const
{
	return {w * -1, x * -1, y * -1, z * -1 };
}

vec4::operator float *()
{
	return &w;
}

vec4::operator const float *() const
{
	return &w;
}