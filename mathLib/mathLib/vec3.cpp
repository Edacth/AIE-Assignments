#include "vec3.h"
#include <cfloat>

vec3::vec3()
{
}

vec3::vec3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

vec3 vec3::operator+(const vec3 &rhs) const
{
	return { x + rhs.x, y + rhs.y, z + rhs.z };
}

vec3 vec3::operator-(const vec3 &rhs) const
{
	return { x - rhs.x, y - rhs.y, z - rhs.z };
}

vec3& vec3::operator+=(const vec3 &rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

vec3& vec3::operator-=(const vec3 &rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

bool vec3::operator==(const vec3 &rhs) const
{
	float errorMargin = FLT_EPSILON * 100;
	return (x - rhs.x < errorMargin && y - rhs.y < errorMargin && z - rhs.z < errorMargin) ? true : false;
}

bool vec3::operator!=(const vec3 &rhs) const
{
	float errorMargin = FLT_EPSILON * 100;
	return (x - rhs.x < errorMargin && y - rhs.y < errorMargin &&  z - rhs.z < errorMargin) ? false : true;
}

vec3 vec3::operator-() const
{
	return { x * -1, y * -1, z * -1 };
}

vec3::operator float *()
{
	return &x;
}

vec3::operator const float *() const
{
	return &x;
}