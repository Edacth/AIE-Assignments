#pragma once

struct vec3
{
	float x, y, z;

	vec3();
	vec3(float _x, float _y, float _z);

	vec3 operator+(const vec3 &rhs) const;
	vec3 operator-(const vec3 &rhs) const;

	vec3& operator+=(const vec3 &rhs);
	vec3& operator-=(const vec3 &rhs);

	bool operator==(const vec3 &rhs) const;
	bool operator!=(const vec3 &rhs) const;

	vec3 operator-() const;

	operator float *();
	operator const float *() const;
};