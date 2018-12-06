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

	#ifdef RAYLIB_H
	operator Vector2();
	#endif
};