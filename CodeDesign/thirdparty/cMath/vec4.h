#pragma once

struct vec4
{
	float x, y, z, w;

	vec4();
	vec4(float _x, float _y, float _z, float _w);

	vec4 operator+(const vec4 &rhs) const;
	vec4 operator-(const vec4 &rhs) const;

	vec4& operator+=(const vec4 &rhs);
	vec4& operator-=(const vec4 &rhs);

	bool operator==(const vec4 &rhs) const;
	bool operator!=(const vec4 &rhs) const;

	vec4 operator-() const;

	operator float *();
	operator const float *() const;

	float magnitude() const;

	vec4 &normalise();
	vec4 getNormalised() const;

	vec4 &scale(const vec4 &rhs);
	vec4 getScaled(const vec4 &rhs) const;

	vec4 operator*(const float rhs) const;
	friend vec4 operator*(const float lhs, const vec4 &rhs);

	vec4 &operator*=(const float rhs);
	vec4 &operator/=(const float rhs);

	float dot(const vec4 &rhs) const;

	vec4 cross(const vec4 &rhs) const;
};