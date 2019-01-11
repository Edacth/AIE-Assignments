#include <iostream>
#include <cassert>
#include "utils.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "iostream"
#include "unittest.h"
#include "raylibTest.h"

#undef assert;

static const float DEFAULT_TOLERANCE = 0.00001f;

#define TEST(a, b, c) {if (TestFunc(a, b, c) == false) {return false;}}

int main()
{
	typedef vec2 Vector2;
	typedef vec3 Vector3;
	typedef vec4 Vector4;

	//runRaylibTest();
	/*
	vec4 v4a= { 13.5f, -48.23f, 862, 0 };
	vec4 v4b= { 5, 3.99f, -12, 1 };
	vec3 v3a = vec3(13.5f, -48.23f, 862);
	vec3 v3b = vec3(5, 3.99f, -12);

	float dotProduct1 = v4a.dot(v4b);
	float dotProduct2 = v3a.dot(v3b);
	

	assert(cMath::min(-5, 11) == -5);

	assert(cMath::max(2, -1) == 2);

	assert(cMath::clamp(122, 4, 10) == 10);

	assert(6 * cMath::DEG_TO_RAD - 0.10472 < 0.00001);

	assert(6 * cMath::RAD_TO_DEG - 343.775 < 0.00001);

	assert(cMath::abs(-5) == 5);
	assert(cMath::abs(5) == 5);
	assert(cMath::abs(0) == 0);

	assert(cMath::pow(5, 5) == 3125);
	assert(cMath::pow(5, 0) == 1);

	assert(cMath::isPowerOfTwo(34) == 0);
	assert(cMath::isPowerOfTwo(16) == 1);

	assert(cMath::nextPowerOfTwo(1024) == 2048);

	assert(cMath::moveTowards(10, -15, 11) == -1);


	vec2 myVec1(10, -7);
	vec2 myVec2(3, 6);
	vec2 myVec3(13, -1);
	vec2 myVec4(7, -3);
	vec2 myVec5(-7, 3);
	vec2 myVec6(3, -7);

	//std::cout << myVec1 + myVec2 << std::endl;
	assert( (myVec1 + myVec2).x == 13);
	assert( (myVec1 + myVec2).y == -1);

	assert(myVec1 + myVec2 == myVec3);
	assert(myVec1 - myVec2 == myVec4);

	myVec1 += myVec2;
	assert(myVec1 == myVec3);

	assert(myVec1 != myVec2);

	assert(-myVec4 == myVec5);

	assert(myVec5[0] == myVec6.y);
	assert(myVec5[1] == myVec6.x);

	std::cout << cMath::lerp(3.0f, 6.0f, -.8) << std::endl;
	std::cout << cMath::lerp2(3.0f, 6.0f, -.8) << std::endl;
	*/

	
	if (runUnitTests() == false) {
		std::cout << "Unit test failed!" << std::endl;
		return -1;
	}
	std::cout << "All tests passed successfully." << std::endl;
	
	return 0;
}