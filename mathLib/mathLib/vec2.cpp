#include "vec2.h"
#include "utils.h"
#include <cfloat>
#include <iostream>

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

float vec2::magnitude() const
{
	return (std::sqrt(cMath::pow(x, 2) + cMath::pow(y, 2)));
}

vec2& vec2::normalise()
{
	float mag = magnitude();
	x /= mag;
	y /= mag;
	return *this;
}

vec2 vec2::getNormalised() const
{
	float mag = magnitude();
	return {x / mag, y / mag};
}

vec2& vec2::scale(const vec2 &rhs)
{
	x *= rhs.x;
	y *= rhs.y;

	return *this;
}

vec2 vec2::getScaled(const vec2 &rhs) const
{
	return { x * rhs.x, y * rhs.y };
}

vec2 vec2::operator*(const float rhs) const
{
	return {x * rhs, y * rhs};
}

vec2 operator*(const float lhs, const vec2 &rhs)
{
	return {rhs.x * lhs, rhs.y * lhs};
}

vec2& vec2::operator*=(const float rhs)
{
	x *= rhs;
	y *= rhs;
	return *this;
}

vec2& vec2::operator/=(const float rhs)
{
	x /= rhs;
	y /= rhs;
	return *this;
}

float vec2::dot(const vec2 &rhs) const
{
	return (x * rhs.x + y * rhs.y);
}