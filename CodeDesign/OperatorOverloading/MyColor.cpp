#include <string>
#include "raylib.h"
#include "MyColor.h"

MyColor::MyColor()
{
	r = 1;
	g = 1;
	b = 1;
	a = 1;
}

MyColor::MyColor(int red, int green, int blue, int alpha)
{
	r = clamp(red, 0, 255);
	g = clamp(green, 0, 255);
	b = clamp(blue, 0, 255);
	a = clamp(alpha, 0, 255);
}

MyColor MyColor::operator + (const MyColor &rhs)
{
	MyColor newColor;
	
	newColor.r = r + rhs.r;
	newColor.g = g + rhs.g;
	newColor.b = b + rhs.b;
	newColor.a = a + rhs.a;
	newColor.r = clamp(newColor.r, 0, 255);
	newColor.g = clamp(newColor.g, 0, 255);
	newColor.b = clamp(newColor.b, 0, 255);
	newColor.a = clamp(newColor.a, 0, 255);

	return newColor;
}

MyColor MyColor::operator - (const MyColor &rhs)
{
	MyColor newColor;

	newColor.r = r - rhs.r;
	newColor.g = g - rhs.g;
	newColor.b = b - rhs.b;
	newColor.a = a - rhs.a;
	newColor.r = clamp(newColor.r, 0, 255);
	newColor.g = clamp(newColor.g, 0, 255);
	newColor.b = clamp(newColor.b, 0, 255);
	newColor.a = clamp(newColor.a, 0, 255);

	return newColor;
}

MyColor MyColor::operator * (const MyColor &rhs)
{
	MyColor newColor;

	newColor.r = r * rhs.r;
	newColor.g = g * rhs.g;
	newColor.b = b * rhs.b;
	newColor.a = a * rhs.a;
	newColor.r = clamp(newColor.r, 0, 255);
	newColor.g = clamp(newColor.g, 0, 255);
	newColor.b = clamp(newColor.b, 0, 255);
	newColor.a = clamp(newColor.a, 0, 255);

	return newColor;
}

MyColor MyColor::operator / (const MyColor &rhs)
{
	MyColor newColor;

	newColor.r = r / rhs.r;
	newColor.g = g / rhs.g;
	newColor.b = b / rhs.b;
	newColor.a = a / rhs.a;
	newColor.r = clamp(newColor.r, 0, 255);
	newColor.g = clamp(newColor.g, 0, 255);
	newColor.b = clamp(newColor.b, 0, 255);
	newColor.a = clamp(newColor.a, 0, 255);

	return newColor;
}

MyColor& MyColor::operator += (const MyColor &rhs)
{
	r += clamp(rhs.r, 0, 255);
	g += clamp(rhs.g, 0, 255);
	b += clamp(rhs.b, 0, 255);
	a += clamp(rhs.a, 0, 255);
	
	return *this;
}

MyColor& MyColor::operator -= (const MyColor &rhs)
{
	r -= clamp(rhs.r, 0, 255);
	g -= clamp(rhs.g, 0, 255);
	b -= clamp(rhs.b, 0, 255);
	a -= clamp(rhs.a, 0, 255);
	
	return *this;
}

int MyColor::clamp(int v, int min, int max)
{
	int newV = v;
	if (newV > max)
	{
		newV = max;
	}
	else if (newV < min)
	{
		newV = min;
	}
	return newV;
}

Color MyColor::convert()
{
	Color newColor;
	newColor.r = r;
	newColor.g = g;
	newColor.b = b;
	newColor.a = a;
	return newColor;
}