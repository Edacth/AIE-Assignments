#pragma once

struct vec2
{
	float x, y;

	vec2();
	vec2(float _x, float _y);

	vec2 operator+(const vec2 &rhs) const;
	vec2 operator-(const vec2 &rhs) const;

	vec2& operator+=(const vec2 &rhs);
	vec2& operator-=(const vec2 &rhs);

	bool operator==(const vec2 &rhs) const;
	bool operator!=(const vec2 &rhs) const;

	vec2 operator-() const;

	operator float *();
	operator const float *() const;

	float magnitude() const;

	vec2 &normalise();
	vec2 getNormalised() const;

	vec2 &scale(const vec2 &rhs);
	vec2 getScaled(const vec2 &rhs) const;

	vec2 operator*(const float rhs) const;
	friend vec2 operator*(const float lhs, const vec2 &rhs);

	vec2 &operator*=(const float rhs);
	vec2 &operator/=(const float rhs);

	float dot(const vec2 &rhs) const;

	#ifdef RAYLIB_H
	operator Vector2();
	#endif
};