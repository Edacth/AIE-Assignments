#pragma once
#include "raylib.h"

class MyColor
{

public:
	int r;
	int g;
	int b;
	int a = 256;

	MyColor();
	MyColor(int red, int green, int blue, int alpha);

	MyColor operator+(const MyColor &rhs);
	MyColor operator-(const MyColor &rhs);
	MyColor operator*(const MyColor &rhs);
	MyColor operator/(const MyColor &rhs);

	MyColor& operator+=(const MyColor &rhs);
	MyColor& operator-=(const MyColor &rhs);
	MyColor& operator*=(const MyColor &rhs);
	MyColor& operator/=(const MyColor &rhs);

	bool operator==(const MyColor &rhs) const;
	bool operator!=(const MyColor &rhs) const;

	MyColor operator!() const;

	Color convert();
	int clamp(int v, int min, int max);
};