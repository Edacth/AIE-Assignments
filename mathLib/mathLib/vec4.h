#pragma once

struct vec4
{
	float w, x, y, z;

	vec4();
	vec4(float _w, float _x, float _y, float _z);

	vec4 operator+(const vec4 &rhs) const;
	vec4 operator-(const vec4 &rhs) const;

	vec4& operator+=(const vec4 &rhs);
	vec4& operator-=(const vec4 &rhs);

	bool operator==(const vec4 &rhs) const;
	bool operator!=(const vec4 &rhs) const;

	vec4 operator-() const;

	operator float *();
	operator const float *() const;
};