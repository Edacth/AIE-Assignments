#pragma once
#include "mat3.h"
#include "utils.h"

struct transform2d
{
public:
	transform2d();
	transform2d(float *ptr);
	transform2d(float m1, float m2, float m3,
		float m4, float m5, float m6,
		float m7, float m8, float m9);

	vec2 localPosition() const;
	float localRotation() const;
	vec2 localScale() const;

	void setLocalPosition(const vec2 & newPos);
	void setLocalRotation(const float & newRot);
	void setLocalScale(const vec2 & newScale);

	void translate(const vec2 &offset);
	void rotate(const float angle);

	void lookAt(const transform2d &target);
	vec2 forward() const;
	void setForward(const vec2 &newFwd);

	mat3 getTRSMatrix() const;
	
private:
	mat3 trsMatrix;
};

