#include "vec4.h"
#include "utils.h"
#include <iostream>
#include <cfloat>

vec4::vec4()
{
}

vec4::vec4(float _x, float _y, float _z, float _w)
{
	
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

vec4 vec4::operator+(const vec4 &rhs) const
{
	return {x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w };
}

vec4 vec4::operator-(const vec4 &rhs) const
{
	return {x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w };
}

vec4& vec4::operator+=(const vec4 &rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	w += rhs.w;
	return *this;
}

vec4& vec4::operator-=(const vec4 &rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	w -= rhs.w;
	return *this;
}

bool vec4::operator==(const vec4 &rhs) const
{
	float errorMargin = FLT_EPSILON * 100;
	return (abs(x - rhs.x) < errorMargin && abs(y - rhs.y) < errorMargin && abs(z - rhs.z) < errorMargin && abs(w - rhs.w) < errorMargin) ? true : false;
}

bool vec4::operator!=(const vec4 &rhs) const
{
	float errorMargin = FLT_EPSILON * 100;
	return (abs(x - rhs.x) < errorMargin && abs(y - rhs.y) < errorMargin && abs(z - rhs.z) < errorMargin && abs(w - rhs.w) < errorMargin) ? false : true;
}

vec4 vec4::operator-() const
{
	return {x * -1, y * -1, z * -1, w * -1, };
}

vec4::operator float *()
{
	return &x;
}

vec4::operator const float *() const
{
	return &x;
}

float vec4::magnitude() const
{
	return (std::sqrt(cMath::pow(x, 2) + cMath::pow(y, 2) + cMath::pow(z, 2) + cMath::pow(w, 2)));
}

vec4& vec4::normalise()
{
	float mag = magnitude();
	x /= mag;
	y /= mag;
	z /= mag;
	w /= mag;
	return *this;
}

vec4 vec4::getNormalised() const
{
	float mag = magnitude();
	return {x / mag, y / mag, z / mag, w / mag };
}

vec4& vec4::scale(const vec4 &rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	w *= rhs.w;
	return *this;
}

vec4 vec4::getScaled(const vec4 &rhs) const
{
	return {x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w };
}

vec4 vec4::operator*(const float rhs) const
{
	return {x * rhs, y * rhs, z * rhs, w * rhs };
}

vec4 operator*(const float lhs, const vec4 &rhs)
{
	return {rhs.x * lhs, rhs.y * lhs, rhs.z * lhs, rhs.w * lhs };
}

vec4& vec4::operator*=(const float rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	w *= rhs;
	return *this;
}

vec4& vec4::operator/=(const float rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;
	w /= rhs;
	return *this;
}

//TODO Waiting on Terry confirmaion to complete this funtion
float vec4::dot(const vec4 &rhs) const
{
	return (x * rhs.x + y * rhs.y + z * rhs.z);
}

//TODO Waiting on Terry confirmaion to complete this funtion
vec4 vec4::cross(const vec4 &rhs) const
{
	return {y * rhs.z - z * rhs.y,
			z * rhs.x - x * rhs.z,
			x * rhs.y - y * rhs.x,
			w};
}