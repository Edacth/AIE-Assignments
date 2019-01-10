#pragma once
#include "mat3.h"
#include "utils.h"

struct transform2d
{
public:
	transform2d();
	transform2d(float *ptr);
	transform2d(vec2 _localPos, float _localRot, vec2 _localScale);

	vec2 getLocalPosition() const;
	float getLocalRotation() const;
	vec2 getLocalScale() const;

	void setLocalPosition(const vec2 & newPos);
	void setLocalRotation(const float & newRot);
	void setLocalScale(const vec2 & newScale);

	void translate(const vec2 &offset);
	void rotate(const float angle);

	void lookAt(const transform2d &target);
	void lookAt(const vec2 &target);
	vec2 getForward() const;
	vec2 getRight();

	mat3 getTRSMatrix() const;
	
private:
	vec2 localPos;
	float localRot;
	vec2 localScale;
};

