#include "transform2d.h"



transform2d::transform2d()
{
}

transform2d::transform2d(float * ptr)
{
	mat3 trsMatrix(float * ptr);
}

transform2d::transform2d(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9)
{
	mat3 trsMatrix(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9);
}

vec2 transform2d::localPosition() const
{
	return vec2(trsMatrix.mm[0][0], trsMatrix.mm[0][1]);
}

float transform2d::localRotation() const //TODO NEEDS TESTING
{
	return -atan(trsMatrix.mm[1][0] / trsMatrix.mm[1][1]);
}

vec2 transform2d::localScale() const
{
	return vec2(trsMatrix.mm[2][0], trsMatrix.mm[2][1]);
}

void transform2d::setLocalPosition(const vec2 & newPos)
{
	trsMatrix.m1 = newPos.x;
	trsMatrix.m2 = newPos.y;
}

void transform2d::setLocalRotation(const float & newRot)
{
	trsMatrix *= mat3::rotation(newRot);
}

void transform2d::setLocalScale(const vec2 & newScale)
{
	trsMatrix.m7 = newScale.x;
	trsMatrix.m8 = newScale.y;
}

void transform2d::translate(const vec2 & offset)
{

}


