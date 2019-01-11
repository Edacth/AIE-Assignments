#pragma once
#include "mat3.h"
#include "utils.h"
#include <vector>

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
	mat3 getTSMatrix() const;
	
	vec2 worldPosition() const;               // world position of this object
	float worldRotation() const;              // world rotation of this object
	vec2 worldScale() const;                  // world scale of this object (lossy)

	void setParent(transform2d *parent);      // assigns a parent to this object
	transform2d *getParent();                 // returns a pointer to its parent
	transform2d const *getParent() const;     // returns a pointer to its parent (const-qualified)

	transform2d *getChildren();               // returns a pointer to the first child
	transform2d *const* getChildren() const;  // returns a pointer to the first child (const-qualified)
	size_t getChildrenCount() const;          // returns the number of children available

private:
	vec2 localPos;
	float localRot;
	vec2 localScale;

	transform2d * parent;                   // pointer to parent
	std::vector<transform2d *> children;    // vector containing pointers to all children
	std::vector<transform2d> callStack;
};

