#include "vec4.h"
#include "utils.h"
#include <iostream>
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

float vec4::magnitude() const
{
	return (std::sqrt(cMath::pow(x, 2) + cMath::pow(y, 2) + cMath::pow(z, 2)));
}

vec4& vec4::normalize()
{
	float mag = magnitude();
	w /= mag;
	x /= mag;
	y /= mag;
	z /= mag;
	return *this;
}

vec4 vec4::getNormalized() const
{
	float mag = magnitude();
	return {w / mag, x / mag, y / mag, z / mag };
}

vec4& vec4::scale(const vec4 &rhs)
{
	w *= rhs.w;
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
}

vec4 vec4::getScaled(const vec4 &rhs) const
{
	return {w * rhs.w, x * rhs.x, y * rhs.y, z * rhs.z };
}

vec4 vec4::operator*(const float rhs) const
{
	return {w * rhs, x * rhs, y * rhs, z * rhs };
}

vec4 operator*(const float lhs, const vec4 &rhs)
{
	return {rhs.w * lhs, rhs.x * lhs, rhs.y * lhs, rhs.z * lhs };
}

vec4& vec4::operator*=(const float rhs)
{
	w *= rhs;
	x *= rhs;
	y *= rhs;
	z *= rhs;
	return *this;
}

vec4& vec4::operator/=(const float rhs)
{
	w /= rhs;
	x /= rhs;
	y /= rhs;
	z /= rhs;
	return *this;
}