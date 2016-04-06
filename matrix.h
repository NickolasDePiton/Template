#pragma once
#ifndef matrix_h
#define matrix_h

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template < typename SomeValueType> class Matrix 
{
public:
	Matrix() :n(0), m(0), matrix(nullptr) {}
	Matrix(int lines, int columns);
	Matrix(const Matrix& copy);
	~Matrix();
	Matrix operator + (const Matrix&);
	Matrix operator - (const Matrix&);
	Matrix operator * (const Matrix&);
	Matrix &operator = (const Matrix&);
	bool operator == (const Matrix&);
	SomeValueType* operator [] (int);
	int Lines() const;
	int Columns() const;
	friend ostream &operator << (ostream &cout, const Matrix &temp);
	friend istream &operator >> (istream &input, Matrix &matr);
private:
	SomeValueType **matrix;
	int n;
	int m;	
};

#endif
