#include "mat4.h"
#include <iostream>

mat4::mat4()
{
	for (size_t i = 0; i < 12; i++)
	{
		m[i] = 0;
	}
}

mat4::mat4(float *ptr)
{
	if (ptr == nullptr)
	{
		for (size_t i = 0; i < 12; i++)
		{
			m[i] = 0;
		}
	}
	else
		for (size_t i = 0; i < 12; i++)
		{
			m[i] = ptr[i];
		}
}

mat4::mat4(float m1, float m2, float m3, float m4,
	float m5, float m6, float m7, float m8,
	float m9, float m10, float m11, float m12,
	float m13, float m14, float m15, float m16)
{
	m[0] = m1;
	m[1] = m2;
	m[2] = m3;
	m[3] = m4;
	m[4] = m5;
	m[5] = m6;
	m[6] = m7;
	m[7] = m8;
	m[8] = m9;
	m[9] = m10;
	m[10] = m11;
	m[11] = m12;
	m[12] = m13;
	m[13] = m14;
	m[14] = m15;
	m[15] = m16;
}

/* implicit operator to convert mat3 into a float array */
mat4::operator float *()
{
	return m;
}

mat4::operator const float *() const
{
	return m;
}

/* returns vec4 objects when accessing by subscript operator */
vec4& mat4::operator[](const int index)
{
	return axis[index];
}

/* concatenates two matrices together and returns the result */
mat4 mat4::operator*(const mat4 &rhs) const
{
	mat4 product;
	for (size_t row = 0; row < 4; row++)
	{
		for (size_t column = 0; column < 4; column++)
		{
			product.mm[column][row] =
				(mm[column][0] * rhs.mm[0][row] + mm[column][1] * rhs.mm[1][row] + mm[column][2] * rhs.mm[2][row] + mm[column][3] * rhs.mm[3][row]);
		}
	}
	return product;
}

mat4& mat4::operator*=(const mat4 &rhs)
{
	mat4 temp = *this * rhs;

	set(temp);

	return *this;
}

void mat4::operator=(const mat4 & rhs)
{
	for (size_t row = 0; row < 4; row++)
	{
		for (size_t column = 0; column < 4; column++)
		{
			mm[column][row] = rhs.mm[column][row];
		}
	}

}

/* returns true if the matrices are equal */
bool mat4::operator==(const mat4 &rhs) const
{
	for (size_t i = 0; i < 16; i++)
	{
		if (m[i] != rhs.m[i])
		{
			return false;
		}
	}
	return true;
}

/* returns true if the matrices are inequal */
bool mat4::operator!=(const mat4 &rhs) const
{
	for (size_t i = 0; i < 16; i++)
	{
		if (m[i] != rhs.m[i])
		{
			return true;
		}
	}
	return false;
}

mat4 mat4::identity()
{
	return mat4(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
}

/* updates the matrix elements with the given values */
void mat4::set(float m1, float m2, float m3, float m4,
	float m5, float m6, float m7, float m8,
	float m9, float m10, float m11, float m12,
	float m13, float m14, float m15, float m16)
{
	m[0] = m1;
	m[1] = m2;
	m[2] = m3;
	m[3] = m4;
	m[4] = m5;
	m[5] = m6;
	m[6] = m7;
	m[7] = m8;
	m[8] = m9;
	m[9] = m10;
	m[10] = m11;
	m[11] = m12;
	m[12] = m13;
	m[13] = m14;
	m[14] = m15;
	m[15] = m16;
}

void mat4::set(float * ptr)
{
	if (ptr == nullptr)
	{
		for (size_t i = 0; i < 16; i++)
		{
			m[i] = 0;
		}
	}
	else
		for (size_t i = 0; i < 16; i++)
		{
			m[i] = ptr[i];
		}
}

void mat4::transpose()
{
	/* Old bad method
	swap(&mm[1][0], &mm[0][1]);
	swap(&mm[2][0], &mm[0][2]);
	swap(&mm[2][1], &mm[1][2]);
	*/

	set((float*)(this->getTranspose()));
}

mat4 mat4::getTranspose() const
{
	return mat4 (
		m[0], m[4], m[8], m[12],
		m[1], m[5],	m[9], m[13],
		m[2], m[6], m[10], m[14],
		m[3], m[7], m[11], m[15]);
}

mat4 mat4::translation(float x, float y, float z)
{
	return mat4(1, 0, 0, x,
				0, 1, 0, y,
				0, 0, 1, z,
				0, 0, 0, 1);
}

mat4 mat4::translation(const vec3 & vec)
{
	mat4 temp(
		1, 0, 0, vec.x,
		0, 1, 0, vec.y,
		0, 0, 1, vec.z,
		0, 0, 0, 1);
	return temp;
}

mat4 mat4::rotationX(float rot)
{
	return mat4 {
		1, 0, 0, 0,
		0, cos(rot), -sin(rot), 0,
		0, sin(rot), cos(rot), 0,
		0, 0, 0, 1
	};
}

mat4 mat4::rotationY(float rot)
{
	return mat4 {
		cos(rot), 0, sin(rot), 0,
		0, 1, 0, 0,
		-sin(rot), 0, cos(rot), 0,
		0, 0, 0, 1
	};
}

mat4 mat4::rotationZ(float rot)
{
	return mat4 {
		cos(rot), -sin(rot), 0, 0,
		sin(rot), cos(rot), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};
}

mat4 mat4::scale(float xScale, float yScale, float zScale)
{
	return mat4{
		xScale, 0, 0, 0,
		0, yScale, 0, 0,
		0, 0, zScale, 0,
		0, 0, 0, 1
	};
}

mat4 mat4::scale(const vec3 & vec)
{
	return mat4{
		vec.x, 0, 0, 0,
		0, vec.y, 0, 0,
		0, 0, vec.z, 0,
		0, 0, 0, 1
	};
}

vec4 mat4::operator*(const vec4 & rhs) const
{
	vec4 product;
	product.x =
		(mm[0][0] * rhs.x + mm[0][1] * rhs.y + mm[0][2] * rhs.z + mm[0][3] * rhs.w);
	product.y =
		(mm[1][0] * rhs.x + mm[1][1] * rhs.y + mm[1][2] * rhs.z + mm[1][3] * rhs.w);
	product.z =
		(mm[2][0] * rhs.x + mm[2][1] * rhs.y + mm[2][2] * rhs.z + mm[2][3] * rhs.w);
	product.w =
		(mm[3][0] * rhs.x + mm[3][1] * rhs.y + mm[3][2] * rhs.z + mm[3][3] * rhs.w);
	return product;
}

vec3 mat4::operator*(const vec3 & rhs) const
{
	vec3 product;
	product.x =
		(mm[0][0] * rhs.x + mm[0][1] * rhs.y + mm[0][2] * rhs.z + mm[0][3] * 1);
	product.y =
		(mm[1][0] * rhs.x + mm[1][1] * rhs.y + mm[1][2] * rhs.z + mm[1][3] * 1);
	product.z =
		(mm[2][0] * rhs.x + mm[2][1] * rhs.y + mm[2][2] * rhs.z + mm[2][3] * 1);
	return product;
}