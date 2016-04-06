#ifndef Matrix_h
#define Matrix_h

#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
template < typename SomeValueType> class Matrix  
{
private:
	int lines;
	int columns;
	SomeValueType **matrix;
public:
	int cout_columns() const;
	int cout_lines() const;
	Matrix();
	Matrix(const Matrix &a);
	~Matrix();
	Matrix(int _lines, int _columns);
	void read_matrix(std::string s);
	void print_matrix() const;
	Matrix operator + (const Matrix &array);
	Matrix operator * (const Matrix &array);
	SomeValueType* operator [](int i) const;
	Matrix &operator = (Matrix &a);
	void reset();
	bool operator ==(const Matrix &array) const;
	friend ostream &operator << (ostream &cout, const Matrix &temp);
	friend istream &operator >> (istream &input, Matrix &matr);

};

#endif
