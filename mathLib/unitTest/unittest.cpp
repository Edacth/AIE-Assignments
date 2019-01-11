#include "unittest.h"

#ifndef NO_DEFAULT_STREAM_OPERATOR

	std::ostream& operator << (std::ostream& os, Vector2& rhs) { 
		float* a = (float*)rhs;
		os << std::setprecision(12) << a[0] << "," << std::setprecision(12) << a[1]; return os; }
	std::ostream& operator << (std::ostream& os, Vector3& rhs) {
		float* a = (float*)rhs;
		os << std::setprecision(12) << a[0] << "," << std::setprecision(12) << a[1] << "," << std::setprecision(12) << a[2]; return os; }
	std::ostream& operator << (std::ostream& os, Vector4& rhs) {
		float* a = (float*)rhs;
		os << std::setprecision(12) << a[0] << "," << std::setprecision(12) << a[1] << "," << std::setprecision(12) << a[2] << "," << std::setprecision(12) << a[3]; return os; }
	
	/* -Commented out until I implement Matricies- */
	std::ostream& operator << (std::ostream& os, Matrix3& rhs) {
		float* a = (float*)rhs;
		for (int i = 0; i < 9; ++i) {
			os << std::setprecision(12) << a[i];
			if (!(i == 8))
				os << ",";
		}
		return os;
	}
	/*std::ostream& operator << (std::ostream& os, Matrix4& rhs) {
		float* a = (float*)rhs;
		for (int i = 0; i < 16; ++i) {
			os << std::setprecision(12) << a[i];
			if (!(i == 15))
				os << ",";
		}
		return os;
	}*/

#endif

static const float DEFAULT_TOLERANCE = 0.00001f;

/* Compare funtions */
	bool compare(const float a, const float b, float tolerance = DEFAULT_TOLERANCE) {
		if (abs(a - b) > tolerance)
			return false;
		return true;
	}

	bool compare(const Vector2& A,const Vector2& B, float tolerance = DEFAULT_TOLERANCE) {
		if (abs(A[0] - B[0]) > tolerance ||
			abs(A[1] - B[1]) > tolerance)
			return false;
		return true;
	}

	bool compare(const Vector3& A,const Vector3& B, float tolerance = DEFAULT_TOLERANCE) {
		if (abs(A[0] - B[0]) > tolerance ||
			abs(A[1] - B[1]) > tolerance ||
			abs(A[2] - B[2]) > tolerance)
			return false;
		return true;
	}

	bool compare(const Vector4& A, const Vector4& B, float tolerance = DEFAULT_TOLERANCE) {
		if (abs(A[0] - B[0]) > tolerance ||
			abs(A[1] - B[1]) > tolerance ||
			abs(A[2] - B[2]) > tolerance ||
			abs(A[3] - B[3]) > tolerance)
			return false;
		return true;
	}
	
	bool compare( const Matrix3& A, const Matrix3& B, float tolerance = DEFAULT_TOLERANCE) {
		 //const float* a = ( float*)A;
		 //float* b = ( float*)B;
		if (abs(A.m[0] - B.m[0]) > tolerance || abs(A[1] - B[1]) > tolerance || abs(A[2] - B[2]) > tolerance ||
			abs(A.m[3] - B.m[3]) > tolerance || abs(A.m[4] - B.m[4]) > tolerance || abs(A.m[5] - B.m[5]) > tolerance ||
			abs(A.m[6] - B.m[6]) > tolerance || abs(A.m[7] - B.m[7]) > tolerance || abs(A.m[8] - B.m[8]) > tolerance)
			return false;
		return true;
	}

	bool compare( const Matrix4& A, const Matrix4& B, float tolerance = DEFAULT_TOLERANCE) {
		 //float* a = ( float*)A;
		 //float* b = ( float*)B;
		if (abs(A.m[0] - B.m[0]) > tolerance || abs(A.m[1] - B.m[1]) > tolerance || abs(A.m[2] - B.m[2]) > tolerance || abs(A.m[3] - B.m[3]) > tolerance ||
			abs(A.m[4] - B.m[4]) > tolerance || abs(A.m[5] - B.m[5]) > tolerance || abs(A.m[6] - B.m[6]) > tolerance || abs(A.m[7] - B.m[7]) > tolerance ||
			abs(A.m[8] - B.m[8]) > tolerance || abs(A.m[9] - B.m[9]) > tolerance || abs(A.m[10] - B.m[10]) > tolerance || abs(A.m[11] - B.m[11]) > tolerance ||
			abs(A.m[12] - B.m[12]) > tolerance || abs(A.m[13] - B.m[13]) > tolerance || abs(A.m[14] - B.m[14]) > tolerance || abs(A.m[15] - B.m[15]) > tolerance)
			return false;
		return true;
	}


bool assert(const char * testName, const bool expression)
{
	if (expression)
	{
		std::cout << " [PASS] " << testName << std::endl;
		return true;
	}
	std::cout << " [FAIL] " << testName << std::endl;
	return false;
}

template <typename T>
bool assert(const char * testName, const T& expected, const T& actual)
{
	if (compare(expected, actual))
	{
		std::cout << " [PASS] " << testName << std::endl;
		return true;
	}
	std::cout << " [FAIL] " << testName << std::endl;
	return false;
}
//This is for comparing a float with a const float
//template <typename T>
//bool assert(const char * testName, T& expected, float actual)
//{
//	if (compare(expected, actual))
//	{
//		std::cout << " [PASS] " << testName << std::endl;
//		return true;
//	}
//	std::cout << " [FAIL] " << testName << std::endl;
//	return false;
//}


template <typename T>
bool TestFunc(const char* msg, const T& a, const T& b) {
	if (compare(a, b) == false) {
		std::cout << "Test failed: " << msg << "\n\tA: (" << a << ")\n\t - does not match - \n\tB: (" << b << ")\n";
		return false;
	}
	return true;
}
////needed for comparing a float variable with a const float
//template <typename T>
//bool TestFunc(const char* msg, T& a, float b) {
//	if (compare(a, b) == false) {
//		std::cout << "Test failed: " << msg << "\n\tA: (" << a << ")\n\t - does not match -\n\tB: (" << b << ")\n";
//		return false;
//	}
//	return true;
//}

//#define TEST(a, b) {if (assert(a, b) == false) {return false;}}
#define TEST(a, b, c) {if (assert(a, b, c) == false) {}}

bool runUnitTests() {

	// vector addition
	Vector2 v2a(13.5f, -48.23f), v2b(5, 3.99f), v2c, v2d;
	v2c = v2a + v2b;
	Vector3 v3a(13.5f, -48.23f, 862), v3b(5, 3.99f, -12), v3c, v3d;
	v3c = v3a + v3b;
	Vector4 v4a(13.5f, -48.23f, 862, 0), v4b(5, 3.99f, -12, 1), v4c, v4d;
	v4c = v4a + v4b;

	int int1 = 3 + 2;
	TEST("TESTY TEST", int1, int(5));

	TEST("Vector2 addition", v2c, Vector2(18.5f, -44.24f));
	TEST("Vector3 addition", v3c, Vector3(18.5f, -44.24f, 850));
	TEST("Vector4 addition", v4c, Vector4(18.5f, -44.24f, 850, 1));

	// vector subtraction
	v2a = Vector2(13.5f, -48.23f); v2b = Vector2(5, 3.99f);
	v2c = v2a - v2b;
	v3a = Vector3(13.5f, -48.23f, 862); v3b = Vector3(5, 3.99f, -12);
	v3c = v3a - v3b;
	v4a = Vector4(13.5f, -48.23f, 862, 0); v4b = Vector4(5, 3.99f, -12, 1);
	v4c = v4a - v4b;

	TEST("Vector2 subtraction", v2c, Vector2(8.5f, -52.22f));
	TEST("Vector3 subtraction", v3c, Vector3(8.5f, -52.22f, 874));
	TEST("Vector4 subtraction", v4c, Vector4(8.5f, -52.22f, 874, -1));

	// vector += 
	v2a = Vector2(13.5f, -48.23f); v2b = Vector2(5, 3.99f);
	v2a += v2b;
	v3a = Vector3(13.5f, -48.23f, 862); v3b = Vector3(5, 3.99f, -12);
	v3a += v3b;
	v4a = Vector4(13.5f, -48.23f, 862, 0); v4b = Vector4(5, 3.99f, -12, 1);
	v4a += v4b;

	TEST("Vector2 +=", v2a, Vector2(18.5f, -44.24f));
	TEST("Vector3 +=", v3a, Vector3(18.5f, -44.24f, 850));
	TEST("Vector4 +=", v4a, Vector4(18.5f, -44.24f, 850, 1));

	// vector -= 
	v2a = Vector2(13.5f, -48.23f); v2b = Vector2(5, 3.99f);
	v2a -= v2b;
	v3a = Vector3(13.5f, -48.23f, 862); v3b = Vector3(5, 3.99f, -12);
	v3a -= v3b;
	v4a = Vector4(13.5f, -48.23f, 862, 0); v4b = Vector4(5, 3.99f, -12, 1);
	v4a -= v4b;

	TEST("Vector2 -=", v2a, Vector2(8.5f, -52.22f));
	TEST("Vector3 -=", v3a, Vector3(8.5f, -52.22f, 874));
	TEST("Vector4 -=", v4a, Vector4(8.5f, -52.22f, 874, -1));

	//vector ==
	v2a = Vector2(13.5f, -48.23f); v2b = Vector2(5, 3.99f);
	v2c = v2a - v2b;
	v2a -= v2b;
	v3a = Vector3(13.5f, -48.23f, 862); v3b = Vector3(5, 3.99f, -12);
	v3c = v3a - v3b;
	v3a -= v3b;
	v4a = Vector4(13.5f, -48.23f, 862, 0); v4b = Vector4(5, 3.99f, -12, 1);
	v4c = v4a - v4b;
	v4a -= v4b;

	TEST("Vector2 ==", v2c, v2a);
	TEST("Vector3 ==", v3c, v3a);
	TEST("Vector4 ==", v4c, v4a);
	TEST("Vector2 ==", v2c, v2c);
	TEST("Vector3 ==", v3c, v3c);
	TEST("Vector4 ==", v4c, v4c);

	//vector !=
	//test true and false?

	//vector invert
	v2a = Vector2(13.5f, -48.23f); v2b = Vector2(5, 3.99f);
	v2c = -v2a;
	v3a = Vector3(13.5f, -48.23f, 862); v3b = Vector3(5, 3.99f, -12);
	v3c = -v3a;
	v4a = Vector4(13.5f, -48.23f, 862, 0); v4b = Vector4(5, 3.99f, -12, 1);
	v4c = -v4a;

	TEST("Vector2 invert", v2c, Vector2(-13.5f, 48.23f));
	TEST("Vector3 invert", v3c, Vector3(-13.5f, 48.23f, -862));
	TEST("Vector4 invert", v4c, Vector4(-13.5f, 48.23f, -862, 0));

	//vector as array


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

	// vector *=
	v2a = Vector2(13.5f, -48.23f);
	v2a *= 2.482f;
	v3a = Vector3(13.5f, -48.23f, 862);
	v3a *= 0.256f;
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4a *= 4.89f;

	TEST("Vector2 *=", v2a, Vector2(33.5069999695f, -119.706863403f));
	TEST("Vector3 *=", v3a, Vector3(3.45600008965f, -12.3468809128f, 220.672012329f));
	TEST("Vector4 *=", v4a, Vector4(66.0149993896f, -235.844696045f, 4215.1796875f, 0));


	// vector dot product
	v2a = Vector2(13.5f, -48.23f); v2b = Vector2(5, 3.99f);
	float dot2 = v2a.dot(v2b);
	v3a = Vector3(13.5f, -48.23f, 862); v3b = Vector3(5, 3.99f, -12);
	float dot3 = v3a.dot(v3b);
	v4a = Vector4(13.5f, -48.23f, 862, 0); v4b = Vector4(5, 3.99f, -12, 1);
	float dot4 = v4a.dot(v4b);

	TEST("Vector2 dot", dot2, -124.937698364f);
	TEST("Vector3 dot", dot3, -10468.9375f);
	TEST("Vector4 dot", dot4, -10468.9375f);

	// vector cross product
	v3a = Vector3(13.5f, -48.23f, 862); v3b = Vector3(5, 3.99f, -12);
	v3c = v3a.cross(v3b);
	v4a = Vector4(13.5f, -48.23f, 862, 0); v4b = Vector4(5, 3.99f, -12, 1);
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

	//// vector normalise
	v2a = Vector2(-13.5f, -48.23f);
	v2a.normalise();
	v3a = Vector3(13.5f, -48.23f, 862);
	v3a.normalise();
	v4a = Vector4(243, -48.23f, 862, 0);
	v4a.normalise();

	TEST("Vector2 normalise", v2a, Vector2(-0.269548f, -0.962987f));
	TEST("Vector3 normalise", v3a, Vector3(0.0156349f, -0.0558571f, 0.998316f));
	TEST("Vector4 normalise", v4a, Vector4(0.270935f, -0.0537745f, 0.961094f, 0));


	Matrix3 m3a, m3b, m3c, m3d;
	Matrix4 m4a, m4b, m4c, m4d;

	// matrix * matrix multiply
	{
	m3a = {
		1, 2, 3,
		4, 5, 6,
		7, 8, 9 };
	m3b = {
		9, 8, 7,
		6, 5, 4,
		3, 2, 1 };
	m4a = {
		1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16
	};
	m4b = {
		16, 15, 14, 13,
		12, 11, 10, 9,
		8, 7, 6, 5,
		4, 3, 2, 1
	};
	m3c = m3a * m3b;
	m4c = m4a * m4b;

	TEST("Matrix3 * Matrix3 multiply", m3c, Matrix3(30, 24, 18, 84, 69, 54, 138, 114, 90));
	TEST("Matrix4 * Matrix4 multiply", m4c, Matrix4(80, 70, 60, 50, 240, 214, 188, 162, 400, 358, 316, 274, 560, 502, 444, 386));
	}

	// matrix * vector multiply
	{
		m3a = {
			1, 2, 3,
			4, 5, 6,
			7, 8, 9 };
		m4a = {
			16, 15, 14, 13,
			12, 11, 10, 9,
			8, 7, 6, 5,
			4, 3, 2, 1
		};
		v2a = Vector2(6, 4);
		v3a = Vector3(6, 4, 1);
		v4a = Vector4(6, 4, 2, 1);
		v3b = Vector3(6, 4, 2);
		v2c = m3a * v2a;
		v3c = m3a * v3a;
		v3d = m4a * v3b;
		v4c = m4a * v4a;
		//v4a = Vector4(13.5f, -48.23f, 862, 0);
		//v4b = m4b * v4a;
		//v4c = m4c * v4a;

		TEST("Matrix3 * Vector2 matrix transform", v2c, Vector2(17, 50));
		TEST("Matrix3 * Vector3 matrix transform", v3c, Vector3(17, 50, 83));
		TEST("Matrix4 * Vector3 matrix transform", v3d, Vector3(197, 145, 93));
		TEST("Matrix4 * Vector4 matrix transform", v4c, Vector4(197, 145, 93, 41));
	}


	//m3a.rotationX(3.98f);
	//m4a.rotationX(4.5f);
	//m3b.rotationY(1.76f);
	//m4b.rotationY(-2.6f);
	//m3c.rotationZ(9.62f);
	//m4c.rotationZ(0.72f);

	//TEST("Matrix3 set rotate", m3a, Matrix3(1,0,0,0,-0.668648f,-0.743579f,0,0.743579f,-0.668648f));
	//TEST("Matrix3 set rotate", m3b, Matrix3(-0.188077f,0,-0.982154f,0,1,0,0.982154f,0,-0.188077f));
	//TEST("Matrix3 set rotate", m3c, Matrix3(-0.981005f,-0.193984f,0,0.193984f,-0.981005f,0,0,0,1));
	//TEST("Matrix4 set rotate", m4a, Matrix4(1,0,0,0,0,-0.210796f,-0.97753f,0,0,0.97753f,-0.210796f,0,0,0,0,1));
	//TEST("Matrix4 set rotate", m4b, Matrix4(-0.856889f,0,0.515501f,0,0,1,0,0,-0.515501f,0,-0.856889f,0,0,0,0,1));
	//TEST("Matrix4 set rotate", m4c, Matrix4(0.751806f,0.659385f,0,0,-0.659385f,0.751806f,0,0,0,0,1,0,0,0,0,1));

	

	// homogeneous point translation
	m3a = Matrix3(1, 0, 0,
				  0, 1, 0,
				  0, 0, 1);
	m3b[2] = Vector3(55, 44, 1);
	//m4b = Matrix4(1, 0, 0, 0,
	//			  0, 1, 0, 0,
	//			  0, 0, 1, 0,
	//			  0, 0, 0, 1);
	//m4b[3] = Vector4(55, 44, 99, 1);
	//m4c.rotationZ(2.2f);
	//m4c[3] = Vector4(55, 44, 99, 1);

	v3a = Vector3(13.5f, -48.23f, 1);
	v3b = m3b * v3a;
	//v4a = Vector4(13.5f, -48.23f, -54, 1);
	//v4b = m4b * v4a;
	//v4c = m4c * v4a;

	TEST("Vector3 matrix translation A", v3b, Vector3(-257.339996f, -156.149994f, -1378.61987));
	//TEST("Vector4 matrix translation A", v4b, Vector4(68.5f, -4.23f, 45, 1));
	//TEST("Vector4 matrix translation B", v4c, Vector4(86.0490112305f, 83.2981109619f, 45, 1));

	//// homogeneous vector translation
	m3b = Matrix3(1, 0, 0,
				  0, 1, 0,
				  0, 0, 1);
	m3b[2] = Vector3(55, 44, 1);
	m3c[2] = Vector3(55, 44, 1);
	//m4b = Matrix4(1, 0, 0, 0,
	//			  0, 1, 0, 0,
	//			  0, 0, 1, 0,
	//			  0, 0, 0, 1);
	//m4b[3] = Vector4(55, 44, 99, 1);
	//m4c.rotationZ(2.2f);
	//m4c[3] = Vector4(55, 44, 99, 1);

	v3a = Vector3(13.5f, -48.23f, 0);
	v3b = m3b * v3a;
	//v4a = Vector4(13.5f, -48.23f, -54, 0);
	//v4b = m4b * v4a;
	//v4c = m4c * v4a;

	TEST("Vector3 matrix translation C", v3b, Vector3(13.5f, -48.2299995, -1379.61987));
	//TEST("Vector4 matrix translation C", v4b, Vector4(13.5f, -48.23f, -54, 0));
	//TEST("Vector4 matrix translation D", v4c, Vector4(31.0490131378f, 39.2981109619f, -54, 0));
	
	return true;
}