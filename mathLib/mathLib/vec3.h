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

	float magnitude() const;

	vec3 &normalise();
	vec3 getNormalised() const;

	vec3 &scale(const vec3 &rhs);
	vec3 getScaled(const vec3 &rhs) const;

	vec3 operator*(const float rhs) const;
	friend vec3 operator*(const float lhs, const vec3 &rhs);

	vec3 &operator*=(const float rhs);
	vec3 &operator/=(const float rhs);

	float dot(const vec3 &rhs) const;

	vec3 cross(const vec3 &rhs) const;
};

