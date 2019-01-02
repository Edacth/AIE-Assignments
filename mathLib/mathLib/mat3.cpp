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

/*Deconstructor*/
mat3::~mat3()
{

}

/* implicit operator to convert mat3 into a float array */
mat3::operator float *()
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
	mat3 product;
	for (size_t row = 0; row < 3; row++)
	{
		for (size_t column = 0; column < 3; column++)
		{
			product.mm[column][row] =
				(mm[column][0] * rhs.mm[0][row] + mm[column][1] * rhs.mm[1][row] + mm[column][2] * rhs.mm[2][row]);
		}
	}
	
	for (size_t row = 0; row < 3; row++)
	{
		for (size_t column = 0; column < 3; column++)
		{
			mm[column][row] = product.mm[column][row];
		}
	}
	return product;
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
	swap(&mm[1][0], &mm[0][1]);
	swap(&mm[2][0], &mm[0][2]);
	swap(&mm[2][1], &mm[1][2]);
}

mat3 mat3::getTranspose() const
{
	return mat3
	( m[0], m[3], m[6],
	  m[1], m[4], m[7],
	  m[2], m[5], m[8]);
}

/* Print funtion for debugging purposes */
void mat3::print()
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			std::cout << mm[i][j] << " ";
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