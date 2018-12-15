#include <iostream>
#include <cassert>
#include "utils.h"
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "iostream"
//#include "unittest.h"
#undef assert;

bool assert(const char * testName, bool expression)
{
	if (expression)
	{
		std::cout << " [PASS] " << testName << std::endl;
	}
}

int main()
{
	typedef vec2 Vector2;
	typedef vec3 Vector3;
	typedef vec4 Vector4;
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


	// vector addition
	Vector2 v2a(13.5f, -48.23f), v2b(5, 3.99f), v2c;
	v2c = v2a + v2b;
	Vector3 v3a(13.5f, -48.23f, 862), v3b(5, 3.99f, -12), v3c;
	v3c = v3a + v3b;
	Vector4 v4a(13.5f, -48.23f, 862, 0), v4b(5, 3.99f, -12, 1), v4c;
	v4c = v4a + v4b;

	TEST("Vector2 addition", v2c, Vector2(18.5f, -44.24f));
	TEST("Vector3 addition", v3c, Vector3(18.5f, -44.24f, 850));
	TEST("Vector4 addition", v4c, Vector4(18.5f, -44.24f, 850, 1));

	// vector subtraction
	v2a = Vector2(13.5f, -48.23f);
	v2b = Vector2(5, 3.99f);
	v2c = v2a - v2b;
	v3a = Vector3(13.5f, -48.23f, 862);
	v3b = Vector3(5, 3.99f, -12);
	v3c = v3a - v3b;
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4b = Vector4(5, 3.99f, -12, 1);
	v4c = v4a - v4b;

	TEST("Vector2 subtraction", v2c, Vector2(8.5f, -52.22f));
	TEST("Vector3 subtraction", v3c, Vector3(8.5f, -52.22f, 874));
	TEST("Vector4 subtraction", v4c, Vector4(8.5f, -52.22f, 874, -1));

	// vector post-scale
	v2a = Vector2(13.5f, -48.23f);
	v2c = v2a * 2.482f;
	v3a = Vector3(13.5f, -48.23f, 862);
	v3c = v3a * 0.256f;
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4c = v4a * 4.89f;

	TEST("Vector2 post-scale", v2c, Vector2(33.5069999695f, -119.706863403f));
	TEST("Vector3 post-scale", v3c, Vector3(3.45600008965f, -12.3468809128f, 220.672012329f));
	TEST("Vector4 post-scale", v4c, Vector4(66.0149993896f, -235.844696045f, 4215.1796875f, 0));

	// vector pre-scale
	v2a = Vector2(13.5f, -48.23f);
	v2c = 2.482f * v2a;
	v3a = Vector3(13.5f, -48.23f, 862);
	v3c = 0.256f * v3a;
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4c = 4.89f * v4a;

	TEST("Vector2 pre-scale", v2c, Vector2(33.5069999695f, -119.706863403f));
	TEST("Vector3 pre-scale", v3c, Vector3(3.45600008965f, -12.3468809128f, 220.672012329f));
	TEST("Vector4 pre-scale", v4c, Vector4(66.0149993896f, -235.844696045f, 4215.1796875f, 0));

	// vector dot product
	v2a = Vector2(13.5f, -48.23f);
	v2b = Vector2(5, 3.99f);
	float dot2 = v2a.dot(v2b);
	v3a = Vector3(13.5f, -48.23f, 862);
	v3b = Vector3(5, 3.99f, -12);
	float dot3 = v3a.dot(v3b);
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4b = Vector4(5, 3.99f, -12, 1);
	float dot4 = v4a.dot(v4b);

	TEST("Vector2 dot", dot2, -124.937698364f);
	TEST("Vector3 dot", dot3, -10468.9375f);
	TEST("Vector4 dot", dot4, -10468.9375f);

	// vector cross product
	v3a = Vector3(13.5f, -48.23f, 862);
	v3b = Vector3(5, 3.99f, -12);
	v3c = v3a.cross(v3b);
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4b = Vector4(5, 3.99f, -12, 1);
	v4c = v4a.cross(v4b);

	TEST("Vector3 cross", v3c, Vector3(-2860.62011719f, 4472.00000000f, 295.01498413f));
	TEST("Vector4 cross", v4c, Vector4(-2860.62011719f, 4472.00000000f, 295.01498413f, 0));

	// vector magnitude
	v2a = Vector2(13.5f, -48.23f);
	float mag2 = v2a.magnitude();
	v3a = Vector3(13.5f, -48.23f, 862);
	float mag3 = v3a.magnitude();
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	float mag4 = v4a.magnitude();

	TEST("Vector2 magnitude", mag2, 50.0837593079f);
	TEST("Vector3 magnitude", mag3, 863.453735352f);
	TEST("Vector4 magnitude", mag4, 863.453735352f);

	// vector normalize
	v2a = Vector2(-13.5f, -48.23f);
	v2a.normalize();
	v3a = Vector3(13.5f, -48.23f, 862);
	v3a.normalize();
	v4a = Vector4(243, -48.23f, 862, 0);
	v4a.normalize();

	TEST("Vector2 normalize", v2a, Vector2(-0.269548f, -0.962987f));
	TEST("Vector3 normalize", v3a, Vector3(0.0156349f, -0.0558571f, 0.998316f));
	TEST("Vector4 normalize", v4a, Vector4(0.270935f, -0.0537745f, 0.961094f, 0));

	// matrix rotation
	/*Matrix3 m3a, m3b, m3c, m3d;
	Matrix4 m4a, m4b, m4c, m4d;
	m3a.setRotateX(3.98f);
	m4a.setRotateX(4.5f);
	m3b.setRotateY(1.76f);
	m4b.setRotateY(-2.6f);
	m3c.setRotateZ(9.62f);
	m4c.setRotateZ(0.72f);

	TEST("Matrix3 set rotate", m3a, Matrix3(1, 0, 0, 0, -0.668648f, -0.743579f, 0, 0.743579f, -0.668648f));
	TEST("Matrix3 set rotate", m3b, Matrix3(-0.188077f, 0, -0.982154f, 0, 1, 0, 0.982154f, 0, -0.188077f));
	TEST("Matrix3 set rotate", m3c, Matrix3(-0.981005f, -0.193984f, 0, 0.193984f, -0.981005f, 0, 0, 0, 1));
	TEST("Matrix4 set rotate", m4a, Matrix4(1, 0, 0, 0, 0, -0.210796f, -0.97753f, 0, 0, 0.97753f, -0.210796f, 0, 0, 0, 0, 1));
	TEST("Matrix4 set rotate", m4b, Matrix4(-0.856889f, 0, 0.515501f, 0, 0, 1, 0, 0, -0.515501f, 0, -0.856889f, 0, 0, 0, 0, 1));
	TEST("Matrix4 set rotate", m4c, Matrix4(0.751806f, 0.659385f, 0, 0, -0.659385f, 0.751806f, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1));

	// vector transform
	v2a = Vector2(13.5f, -48.23f);
	v3a = Vector3(13.5f, -48.23f, 862);
	v3b = m3b * v3a;
	v3c = m3c * v3a;
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4b = m4b * v4a;
	v4c = m4c * v4a;

	TEST("Vector3 matrix transform", v3b, Vector3(844.077941895f, -48.2299995422f, -175.38130188f));
	TEST("Vector3 matrix transform", v3c, Vector3(-22.5994224548f, 44.6950683594f, 862));
	TEST("Vector4 matrix transform", v4b, Vector4(-455.930236816f, -48.2299995422f, -731.678771973f, 0));
	TEST("Vector4 matrix transform", v4c, Vector4(41.951499939f, -27.3578968048f, 862, 0));

	// matrix multiply
	m3d = m3a * m3c;
	m4d = m4c * m4b;

	TEST("Matrix3 multiply", m3d, Matrix3(-0.981004655361f, 0.129707172513f, 0.14424264431f, 0.193984255195f, 0.655946731567f, 0.729454636574f, 0, 0.743579149246f, -0.668647944927f));
	TEST("Matrix4 multiply", m4d, Matrix4(-0.644213855267f, -0.565019249916f, 0.515501439571f, 0, -0.659384667873f, 0.751805722713f, 0, 0, -0.387556940317f, -0.339913755655f, -0.856888711452f, 0, 0, 0, 0, 1));

	// homogeneous point translation
	m3b = Matrix3(1, 0, 0,
		0, 1, 0,
		0, 0, 1);
	m3b[2] = Vector3(55, 44, 1);
	m3c.setRotateZ(2.2f);
	m3c[2] = Vector3(55, 44, 1);
	m4b = Matrix4(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
	m4b[3] = Vector4(55, 44, 99, 1);
	m4c.setRotateZ(2.2f);
	m4c[3] = Vector4(55, 44, 99, 1);

	v3a = Vector3(13.5f, -48.23f, 1);
	v3b = m3b * v3a;
	v3c = m3c * v3a;
	v4a = Vector4(13.5f, -48.23f, -54, 1);
	v4b = m4b * v4a;
	v4c = m4c * v4a;

	TEST("Vector3 matrix translation A", v3b, Vector3(68.5f, -4.23f, 1));
	TEST("Vector3 matrix translation B", v3c, Vector3(86.0490112305f, 83.2981109619f, 1));
	TEST("Vector4 matrix translation A", v4b, Vector4(68.5f, -4.23f, 45, 1));
	TEST("Vector4 matrix translation B", v4c, Vector4(86.0490112305f, 83.2981109619f, 45, 1));

	// homogeneous vector translation
	m3b = Matrix3(1, 0, 0,
		0, 1, 0,
		0, 0, 1);
	m3b[2] = Vector3(55, 44, 1);
	m3c.setRotateZ(2.2f);
	m3c[2] = Vector3(55, 44, 1);
	m4b = Matrix4(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
	m4b[3] = Vector4(55, 44, 99, 1);
	m4c.setRotateZ(2.2f);
	m4c[3] = Vector4(55, 44, 99, 1);

	v3a = Vector3(13.5f, -48.23f, 0);
	v3b = m3b * v3a;
	v3c = m3c * v3a;
	v4a = Vector4(13.5f, -48.23f, -54, 0);
	v4b = m4b * v4a;
	v4c = m4c * v4a;

	TEST("Vector3 matrix translation C", v3b, Vector3(13.5f, -48.23f, 0));
	TEST("Vector3 matrix translation D", v3c, Vector3(31.0490131378f, 39.2981109619f, 0));
	TEST("Vector4 matrix translation C", v4b, Vector4(13.5f, -48.23f, -54, 0));
	TEST("Vector4 matrix translation D", v4c, Vector4(31.0490131378f, 39.2981109619f, -54, 0));
	*/
	return true;
	
	return 0;
}