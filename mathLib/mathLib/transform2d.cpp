#include "transform2d.h"



transform2d::transform2d()
{
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

void transform2d::setLocalScale(const vec2 & newScale)
{
	trsMatrix.m7 = newScale.x;
	trsMatrix.m8 = newScale.y;
}

void transform2d::translate(const vec2 & offset)
{

}


