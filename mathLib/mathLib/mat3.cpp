#include "mat3.h"
#include <iostream>

mat3::mat3()
{
	for (size_t i = 0; i < 9; i++)
	{
		m[i] = 0;
	}
}

mat3::mat3(float *ptr)
{
	if (ptr == nullptr)
	{
		for (size_t i = 0; i < 9; i++)
		{
			m[i] = 0;
		}
	}
	else
	for (size_t i = 0; i < 9; i++)
	{
		m[i] = ptr[i];
	}
}

mat3::mat3(float m1, float m2, float m3,
	float m4, float m5, float m6,
	float m7, float m8, float m9)
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
}

/* implicit operator to convert mat3 into a float array */
mat3::operator float *()
{
	return m;
}

mat3::operator const float *() const
{
	return m;
}

/* returns vec3 objects when accessing by subscript operator */
vec3& mat3::operator[](const int index)
{
	return axis[index];
}

/* concatenates two matrices together and returns the result */
mat3 mat3::operator*(const mat3 &rhs) const
{
	mat3 product;
	for (size_t row = 0; row < 3; row++)
	{
		for (size_t column = 0; column < 3; column++)
		{
			product.mm[column][row] =
				(mm[column][0] * rhs.mm[0][row] + mm[column][1] * rhs.mm[1][row] + mm[column][2] * rhs.mm[2][row]);
		}
	}
	return product;
}

mat3& mat3::operator*=(const mat3 &rhs)
{
	mat3 temp = *this * rhs;

	set(temp);

	return *this;
}

void mat3::operator=(const mat3 & rhs)
{
	for (size_t row = 0; row < 3; row++)
	{
		for (size_t column = 0; column < 3; column++)
		{
			mm[column][row] = rhs.mm[column][row];
		}
	}
	
}

/* returns true if the matrices are equal */
bool mat3::operator==(const mat3 &rhs) const
{
	for (size_t i = 0; i < 9; i++)
	{
		if (m[i] != rhs.m[i])
		{
			return false;
		} 
	}
	return true;
}

/* returns true if the matrices are inequal */
bool mat3::operator!=(const mat3 &rhs) const
{
	for (size_t i = 0; i < 9; i++)
	{
		if (m[i] != rhs.m[i])
		{
			return true;
		}
	}
	return false;
}

mat3 mat3::identity()
{
	return mat3(1, 0, 0,
				0, 1, 0,
				0, 0, 1);
}

/* updates the matrix elements with the given values */
void mat3::set(float m1, float m2, float m3,
	float m4, float m5, float m6,
	float m7, float m8, float m9)
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
}

void mat3::set(float * ptr)
{
	if (ptr == nullptr)
	{
		for (size_t i = 0; i < 9; i++)
		{
			m[i] = 0;
		}
	}
	else
		for (size_t i = 0; i < 9; i++)
		{
			m[i] = ptr[i];
		}
}

void mat3::transpose()
{
	/* Old bad method
	swap(&mm[1][0], &mm[0][1]);
	swap(&mm[2][0], &mm[0][2]);
	swap(&mm[2][1], &mm[1][2]);
	*/

	set((this->getTranspose()));
}

mat3 mat3::getTranspose() const 
{
	return mat3
	( m[0], m[3], m[6],
	  m[1], m[4], m[7],
	  m[2], m[5], m[8]);
}

mat3 mat3::translation(float x, float y)
{
	return mat3(
			1, 0, x,
			0, 1, y,
			0, 0, 1);
}

mat3 mat3::translation(const vec2 & vec)
{
	mat3 temp(
			1, 0, vec.x,
			0, 1, vec.y,
			0, 0, 1);
	return temp;
}

mat3 mat3::rotation(float rot)
{
	return mat3{
		cos(rot), -sin(rot), 0,
		sin(rot), cos(rot), 0,
		0, 0, 1
	};
}

mat3 mat3::scale(float xScale, float yScale)
{
	return mat3{
		xScale, 0, 0,
		0, yScale, 0,
		0, 0, 1
	};
}

mat3 mat3::scale(const vec2 & vec)
{
	return mat3{
		vec.x, 0, 0,
		0, vec.y, 0,
		0, 0, 1
	};
}

vec3 mat3::operator*(const vec3 & rhs) const
{
	vec3 product;
			product.x =
				(mm[0][0] * rhs.x + mm[0][1] * rhs.y + mm[0][2] * rhs.z);
			product.y =
				(mm[1][0] * rhs.x + mm[1][1] * rhs.y + mm[1][2] * rhs.z);
			product.z =
				(mm[2][0] * rhs.x + mm[2][1] * rhs.y + mm[2][2] * rhs.z);
	return product;
}

vec2 mat3::operator*(const vec2 & rhs) const
{
	vec2 product;
	product.x =
		(mm[0][0] * rhs.x + mm[0][1] * rhs.y + mm[0][2] * 1);
	product.y =
		(mm[1][0] * rhs.x + mm[1][1] * rhs.y + mm[1][2] * 1);
	return product;
}

/* Print funtion for debugging purposes */
void mat3::print()
{
	mm;
	mat3 tmm = this->getTranspose();
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			std::cout << tmm[i][j] << " ";
		}
		std::cout << std::endl;
	}

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			std::cout << "mm[" << i << "][" << j << "] = " << mm[i][j] << std::endl;
		}
		std::cout << std::endl;
	}
}

void mat3::swap(float* a, float* b)
{
	float temp = *a;
	*a = *b;
	*b = temp;
}