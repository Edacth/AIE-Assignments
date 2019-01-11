#include "transform2d.h"
#include <iostream>


transform2d::transform2d()
{
	localPos = { 0, 0 };
	localRot = 0;
	localScale = { 0 , 0 };
}

transform2d::transform2d(float * ptr)
{
	localPos = {ptr[0], ptr[1]};
	localScale = { ptr[6], ptr[7] };
}

transform2d::transform2d(vec2 _localPos, float _localRot, vec2 _localScale)
{
	localPos = _localPos;
	localRot = _localRot;
	localScale = _localScale;
}

vec2 transform2d::getLocalPosition() const
{
	return localPos;
}

float transform2d::getLocalRotation() const //TODO NEEDS TESTING
{
	return localRot;
	//return -atan(trsMatrix.mm[1][0] / trsMatrix.mm[1][1]);
}

vec2 transform2d::getLocalScale() const
{
	return localScale;
}
void transform2d::setLocalPosition(const vec2 & newPos)
{
	localPos = newPos;
}

void transform2d::setLocalRotation(const float & newRot)
{
	//trsMatrix *= mat3::rotation(newRot);
	localRot = newRot;
}

void transform2d::setLocalScale(const vec2 & newScale)
{
	localScale = newScale;
}

void transform2d::translate(const vec2 & offset)
{
	localPos += offset;
	//vec3 newPos = mat3::translation(offset) * vec3(trsMatrix.xAxis.x, trsMatrix.xAxis.y, 1);
	//trsMatrix.xAxis.x = newPos.x;
	//trsMatrix.xAxis.y = newPos.y;
	//std::cout << trsMatrix.xAxis.x << " " << trsMatrix.xAxis.y << " " << trsMatrix.xAxis.z << std::endl;
}

void transform2d::rotate(const float angle)
{
	//This method works sorta
	/*vec3 newRot = mat3::rotation(angle) * vec3(trsMatrix.yAxis.x, trsMatrix.yAxis.y, 1);
	trsMatrix.yAxis.x = newRot.x;
	trsMatrix.yAxis.y = newRot.y;*/
	/* Scrapped with matrices
	float newAngle = angle + transform2d::localRotation();
	std::cout << "Prerotation: " << cMath::RAD_TO_DEG * localRotation();
	
	vec3 newRot = mat3::rotation(angle) * vec3(1, 1, 1);
	trsMatrix.yAxis.x = newRot.x;
	trsMatrix.yAxis.y = newRot.y;*/

	localRot += angle;
}

void transform2d::lookAt(const transform2d & target)
{
	vec2 directionToTarget = localPos - target.getLocalPosition();
	vec2 normDirectionToCursor = directionToTarget.getNormalised();

	localRot = -(atan2(normDirectionToCursor.x, normDirectionToCursor.y) + 1.5708);
}

void transform2d::lookAt(const vec2 & target)
{
	vec2 directionToTarget = localPos - target;
	vec2 normDirectionToCursor = directionToTarget.getNormalised();

	localRot = -(atan2(normDirectionToCursor.x, normDirectionToCursor.y) + 1.5708);
}

vec2 transform2d::getForward() const
{
	return vec2(cos(localRot), sin(localRot));
}

vec2 transform2d::getRight()
{
	return vec2(cos(localRot + 1.5708), sin(localRot + 1.5708));
}

mat3 transform2d::getTRSMatrix() const
{
	return mat3(
	localPos.x, localPos.y, 0,
	cos(localRot), sin(localRot), 0,
	localScale.x, localScale.y, 0);
}

mat3 transform2d::getTSMatrix() const
{
	return mat3(
	localScale.x, 0, localPos.x,
	0, localScale.y, localPos.y,
	0, 0 , 1);
}

vec2 transform2d::worldPosition() const //TODO Expand this funtion to go deeper than one parent check
{
	
	if (parent != nullptr) //If you have a parent
	{
		mat3 concat = getTSMatrix() * parent->getTSMatrix();
		return vec2(concat.m3, concat.m6);
	}

	return localPos;
}

void transform2d::setParent(transform2d * _parent)
{
	parent = _parent;
	parent->children.push_back(this);
}

transform2d * transform2d::getParent()
{
	return parent;
}

transform2d const * transform2d::getParent() const
{
	return parent;
}


