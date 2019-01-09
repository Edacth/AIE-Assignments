#include "transform2d.h"
#include <iostream>


transform2d::transform2d()
{
	trsMatrix = { 1,0,0,0,1,0,0,0,1 };
}

transform2d::transform2d(float * ptr)
{
	if (ptr == nullptr)
	{
		for (size_t i = 0; i < 9; i++)
		{
			trsMatrix.m[i] = 0;
		}
	}
	else
		for (size_t i = 0; i < 9; i++)
		{
			trsMatrix.m[i] = ptr[i];
		}
}

transform2d::transform2d(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9)
{
	trsMatrix.m[0] = m1;
	trsMatrix.m[1] = m2;
	trsMatrix.m[2] = m3;
	trsMatrix.m[3] = m4;
	trsMatrix.m[4] = m5;
	trsMatrix.m[5] = m6;
	trsMatrix.m[6] = m7;
	trsMatrix.m[7] = m8;
	trsMatrix.m[8] = m9;
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
	vec3 newPos = mat3::translation(offset) * vec3(trsMatrix.xAxis.x, trsMatrix.xAxis.y, 1);
	trsMatrix.xAxis.x = newPos.x;
	trsMatrix.xAxis.y = newPos.y;
	//std::cout << trsMatrix.xAxis.x << " " << trsMatrix.xAxis.y << " " << trsMatrix.xAxis.z << std::endl;
}

void transform2d::rotate(const float angle)
{
	//This method works sorta
	/*vec3 newRot = mat3::rotation(angle) * vec3(trsMatrix.yAxis.x, trsMatrix.yAxis.y, 1);
	trsMatrix.yAxis.x = newRot.x;
	trsMatrix.yAxis.y = newRot.y;*/
	float newAngle = angle + transform2d::localRotation();
	std::cout << "Prerotation: " << cMath::RAD_TO_DEG * localRotation();
	
	vec3 newRot = mat3::rotation(angle) * vec3(1, 1, 1);
	trsMatrix.yAxis.x = newRot.x;
	trsMatrix.yAxis.y = newRot.y;
}

mat3 transform2d::getTRSMatrix() const
{
	return trsMatrix;
}


