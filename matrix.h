#pragma once
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;


template <typename T>
class matrix;

template <class T>
std::ostream & operator<<(std::ostream & output, const matrix<T> &);

template <class T>
std::istream & operator>>(std::istream & input, matrix<T> &);
template <typename T>
class matrix
{
public:
        matrix<T>();
matrix(int _collumns, int _lines);
	matrix(const matrix &Matrix);
	matrix(T **matr, unsigned int _n, unsigned int _m);
	matrix(T **matr, unsigned int _n, unsigned int _m, int time);
	~matrix<T>();
	void get_line(int k);
	void get_from_file(string _name);
	void print_matrix() const;
	void copy_matrix(const matrix &Matrix);
	matrix &operator=(const matrix &Matrix);
	friend matrix operator+(const matrix &matrix_1, const matrix &matrix_2);
	friend matrix operator*(const matrix &matrix_1, const matrix &matrix_2);
	T *operator[] (int i) const;
	void get_sum_r(const matrix &matrix_1, const matrix &matrix_2, int s);
	void get_multi_r(const matrix &matrix_1, const matrix &matrix_2, int m);
	void create_memory();
	int get_num_rows() const;
	int get_num_cols() const;
	int get(int rows, int columns) const;
	void set(int row, int columns, int set);
	friend std::ostream & operator<< (std::ostream & output, const matrix<T> & x);
	friend std::istream & operator>> (std::istream & input, matrix<T> & _matrix);
private:
	int rows;
	int columns;
	T **_matrix;	
};

#endif
