#include "matrix.h"
#include <iostream>
#include <fstream>
using namespace std;

template < typename SomeValueType> 
Matrix<SomeValueType>::Matrix(int lines, int columns) :n(lines), m(columns)
{
	matrix = new SomeValueType*[n];
	for (int i = 0; i<n; i++)
	{
		matrix[i] = new SomeValueType[m];
		for (int j = 0; j<m; j++)
		{
			matrix[i][j] = 0;
		}
	}
}
template < typename SomeValueType>
Matrix<SomeValueType>::Matrix(const Matrix& copy) :n(copy.n), m(copy.m)
{
	matrix = new SomeValueType*[n];
	for (int i = 0; i<n; i++)
	{
		matrix[i] = new SomeValueType[m];
		for (int j = 0; j<m; j++)
		{
			matrix[i][j] = copy.matrix[i][j];
		}
	}
}
template < typename SomeValueType>
Matrix<SomeValueType>::~Matrix()
{
	if (matrix != nullptr)
	{
		for (int i = 0; i<n; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}
}
template < typename SomeValueType>
Matrix<SomeValueType> Matrix<SomeValueType>::operator + (const Matrix &matr)
{
	Matrix result(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			result.matrix[i][j] = matrix[i][j] + matr.matrix[i][j];
		}
	}
	return result;
}
template < typename SomeValueType>
Matrix<SomeValueType> Matrix<SomeValueType>::operator - (const Matrix &matr)
{
	Matrix result(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			result.matrix[i][j] = matrix[i][j] - matr.matrix[i][j];
		}
	}
	return result;
}
template < typename SomeValueType>
Matrix<SomeValueType> Matrix<SomeValueType>::operator * (const Matrix &matr)
{
	Matrix result(n, matr.m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < matr.m; j++)
		{
			int value = 0;
			for (int k = 0; k < m; k++)
			{
				value += matrix[i][k] * matr.matrix[k][j];
			}
			result.matrix[i][j] = value;
		}
	}
	return result;
}
template < typename SomeValueType>
Matrix<SomeValueType> &Matrix<SomeValueType>::operator = (const Matrix &matr)
{
	if (this != &matr)
	{
		if (matrix != nullptr)
		{
			for (int i = 0; i<n; i++)
			{
				delete[] matrix[i];
			}
			delete[] matrix;
		}
		n = matr.n;
		m = matr.m;
		matrix = new SomeValueType*[n];
		for (int i = 0; i<n; i++)
		{
			matrix[i] = new int[m];
			for (int j = 0; j<m; j++)
			{
				matrix[i][j] = matr.matrix[i][j];
			}
		}
	}
	return *this;
}
template < typename SomeValueType>
bool Matrix<SomeValueType>::operator == (const Matrix &matr)
{
	if (n!=matr.n || m!=matr.m) 
	{
		return false;
	}

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			if (matrix[i][j] != matr.matrix[i][j]) 
			{
				return false;
			}
		}
	}
	return true;
}
template < typename SomeValueType>
SomeValueType* Matrix<SomeValueType>::operator [] (int index)
{
	SomeValueType* a;
	try {
		a = this->matrix[index];
	}
	catch (int e) {
		throw "Index isn't good enough";
	}
	return a;
}
template < typename SomeValueType>
int Matrix<SomeValueType>::Lines() const
{
	return n;
}
template < typename SomeValueType>
int Matrix<SomeValueType>::Columns() const
{
	return m;
}
template < typename SomeValueType>
ostream &operator << (ostream &os, const Matrix<SomeValueType> &temp)
{
	for (int i = 0; i < temp.n; i++)
	{
		for (int j = 0; j < temp.m; j++)
		{
			os << temp.matrix[i][j] << " ";
		}
		os << endl;
	}
	return os;
}
template < typename SomeValueType>
istream &operator >> (istream &input, Matrix<SomeValueType> &matr)
{
    for (int i = 0; i < matr.n; i++) 
    {
        for (int j = 0; j < matr.m; j++) 
        {
            if (!(input >> matr.matrix[i][j]))
            {
                throw "exception in fill matrix";
            }
        }
    }
    return input;
}
int main()
{
	Matrix<double> m(5, 5); 
	for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++) 
			{
				m[i][j] = 5;
			}
		}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf( "%f\n",m[i][j]);
		}
	}

}
