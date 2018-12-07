#include "vec3.h"
#include "utils.h"
#include <cfloat>
#include <iostream>

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

float vec3::magnitude() const
{
	return (std::sqrt(cMath::pow(x, 2) + cMath::pow(y, 2) + cMath::pow(z, 2)));
}

vec3& vec3::normalise()
{
	float mag = magnitude();
	x /= mag;
	y /= mag;
	z /= mag;
	return *this;
}

vec3 vec3::getNormalised() const
{
	float mag = magnitude();
	return { x / mag, y / mag, z / mag };
}

vec3& vec3::scale(const vec3 &rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;

	return *this;
}

vec3 vec3::getScaled(const vec3 &rhs) const
{
	return { x * rhs.x, y * rhs.y, z * rhs.z };
}

vec3 vec3::operator*(const float rhs) const
{
	return { x * rhs, y * rhs, z * rhs };
}

vec3 operator*(const float lhs, const vec3 &rhs)
{
	return { rhs.x * lhs, rhs.y * lhs, rhs.z * lhs };
}

vec3& vec3::operator*=(const float rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	return *this;
}

vec3& vec3::operator/=(const float rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;
	return *this;
}

float vec3::dot(const vec3 &rhs) const
{
	return (x * rhs.x + y * rhs.y + z * rhs.z);
}

vec3 vec3::cross(const vec3 &rhs) const
{
	return { y * rhs.z - z * rhs.y,
			z * rhs.x - x * rhs.z,
			x * rhs.y - y * rhs.x };
}