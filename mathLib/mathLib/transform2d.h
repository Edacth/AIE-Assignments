#pragma once
#include "mat3.h"
#include "utils.h"

struct transform2d
{
public:
	transform2d();

	vec2 localPosition() const;
	float localRotation() const;
	vec2 localScale() const;

	void setLocalPosition(const vec2 & newPos);
	void setLocalScale(const vec2 & newScale);

	void translate(const vec2 &offset);
	void rotate(const float angle);

	void lookAt(const transform2d &target);
	vec2 forward() const;
	void setForward(const vec2 &newFwd);

	mat3 getTRSMatrix() const;

private:
	mat3 trsMatrix = { 1,0,0,0,1,0,0,0,1 };
};

